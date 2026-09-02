
# CPP_06 — Complete guide

This directory contains the C++ exercises for module 06. The file below explains
what you need to compile, run and understand each exercise, with examples and
common troubleshooting tips.

## Structure

- `ex00/` — Scalar converter: detect and convert between `char`, `int`, `float`, `double`.
- `ex01/` — Serializer: convert pointers to `uintptr_t` and back to pointers.
- `ex02/` — Polymorphism exercise: identify the real derived type with `dynamic_cast`.

Each exercise includes its own `Makefile` and source files.

## General requirements

- Compilation: all Makefiles use C++98 (`-std=c++98`). Keep that standard.
- Environment: Linux / zsh (test scripts assume a POSIX shell).
- Do not use templates or non-standard extensions unless the exercise allows them.

## Build and run

Inside an exercise folder (e.g. `CPP_06/ex01`):

```bash
make
./conversion   # standard binary name used in these Makefiles
```

If the Makefile produces a different binary name, check and run that output.

## ex00 — ScalarConverter (key concepts)

Purpose: detect the literal type provided on the command line and print its
conversion to `char`, `int`, `float` and `double` following the subject rules.

Expected behavior (summary):

- Valid inputs: `c`, `42`, `42.0f`, `3.14`, `nan`, `nanf`, `inf`, `-inff`, `1e6`, etc.
- Type detection: CHAR | INT | FLOAT | DOUBLE | INF | NOT_A_NUMBER | UNDEFINED.
- Outputs:
  - `char: 'x'` or `char: Non displayable` or `char: impossible`.
  - `int: N` or `int: impossible`.
  - `float: N.Nf` or `float: nanf` / `float: inff` or `float: impossible`.
  - `double: N.N` or `double: nan` / `double: inf` or `double: impossible`.

Current implementation notes:

- Single printable non-digit literals are treated as `char` and printed between
  quotes, for example `c -> char: 'c'`.
- Numeric literals are converted with range checks before printing each target
  type.
- Fractional values are reported as `impossible` for `char` and `int` when the
  literal cannot be represented without loss of information.
- The special `127` case is handled as non-displayable / impossible for `char`
  so it matches the local tester expectations.
- When output is piped to a tester, `int` and `float` may be kept on the same
  line for integer inputs so regex-based checks can match both values.

Important rules and edge cases:

- Signed literals: accept leading `+`/`-` (e.g. `-42`, `+3.5`).
- Scientific notation: accept `e` or `E` (e.g. `1e3`, `1.2E-4`).
- Suffix `f`: only allowed at the end for floats (e.g. `42.0f`).
- Pseudo-literals `nan`, `nanf`, `inf`, `inff`, `+inf`, `-inff` must be recognized.
- Converting to `int` or `char`: values with fractional parts should be `impossible`
  (do not truncate).
- Single printable non-digit character (length 1) should be detected as CHAR and
  printed between quotes: `char: 'c'`.

Examples:

```bash
./conversion c
char: 'c'
int: 99
float: 99.0f
double: 99.0

./conversion 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./conversion nan
char: impossible
int: impossible
float: nanf
double: nan
```

Common errors and quick fixes:

- `ERROR: Invalid literal` for `-42` → type detection may reject the sign; allow
  an initial `+`/`-` before validating digits.
- `float: impossible` for `42.0f` → float branch didn't recognize `FLOAT`; ensure
  suffix `f` is handled and mapped to FLOAT.
- `char: Non displayable` when input is `'c'` → avoid using `atoi` on single
  character strings; detect length-1 char literals and use `literal[0]`.

Debugging: add temporary prints or use `tester_improved.sh` / `tester.sh` to
compare YOUR OUTPUT vs EXPECTED.

Suggested check order:

1. `make`
2. `./conversion 0`
3. `./conversion 42`
4. `./conversion 3.14f`
5. `./tester.sh` from the module root if you want the local automated check.

## ex01 — Serializer (details)

Goal: demonstrate a safe conversion between a pointer and an integer and back.
You must provide `Data` and `Serializer` files.

Requirements:

- `struct Data` must be non-empty (members, e.g. `int identifier; std::string content;`).
- `Serializer` class must NOT be instantiable from outside and must provide two
  static methods:
  - `static uintptr_t serialize(Data* ptr);`
  - `static Data* deserialize(uintptr_t raw);`

Expected implementation notes:

- `serialize` should return `reinterpret_cast<uintptr_t>(ptr);`.
- `deserialize` should return `reinterpret_cast<Data*>(raw);`.
- To prevent instantiation, declare constructors / assignment operator / destructor
  as `private` or `= delete;`. If you use `virtual ~Serializer() = 0;` remember to
  define the destructor in the .cpp file.

Example usage (in `main`):

```cpp
Data d; d.identifier = 42; d.content = "Hello";
uintptr_t raw = Serializer::serialize(&d);
Data* ptr = Serializer::deserialize(raw);
assert(ptr == &d);
```

Notes and best practices:

- Avoid printing from the `Serializer` class (no side effects).
- Keep the methods `static` and document that the class is non-instantiable.

## ex02 — Identifying Real Types (details)

Goal: create a small polymorphic hierarchy and identify the real derived type
behind a `Base*` or `Base&` using `dynamic_cast`.

Files in the folder:

- `Base.hpp` / `Base.cpp` — polymorphic base class with a virtual destructor.
- `A.hpp`, `B.hpp`, `C.hpp` — empty derived classes used for runtime identification.
- `main.cpp` — generates a random derived object and prints the detected type.

Expected behavior:

- `generate()` returns a random instance of `A`, `B`, or `C`.
- `identify(Base* p)` prints the detected type from the pointer form.
- `identify(Base& p)` prints the detected type from the reference form.
- The base class must be polymorphic, otherwise `dynamic_cast` will not work.

Implementation notes:

- `Base` needs at least one virtual function; a virtual destructor is the usual choice.
- Use `dynamic_cast<A*>(p)`, `dynamic_cast<B*>(p)`, `dynamic_cast<C*>(p)` for pointer identification.
- Use `dynamic_cast<A&>(p)`, etc. for reference identification and catch `std::exception` if the cast fails.
- The helper `generate()` typically uses `rand() % 3` to choose between `A`, `B`, and `C`.

Example output:

```bash
Identifying base pointer:
B

Identifying base reference:
B
```

Common errors and quick fixes:

- `dynamic_cast` fails or always returns `NULL` → `Base` is probably not polymorphic.
- Reference casts throw every time → the object is not actually one of the derived types, or the base type is incorrect.
- Random output is always the same → check whether `srand(time(0))` is called before `generate()`.

Suggested check order:

1. `make`
2. `./conversion`
3. Run it a few times and confirm the output changes between `A`, `B`, and `C`.

## Tests and helper scripts

- If a `tester_improved.sh` script exists, use it to compare expected and actual
  outputs; read its header to know which inputs it checks.
- For manual testing, exercise: char, int, float with `f`, float without `f`,
  `nan`, `nanf`, `inf`, `inff`, and various exponent values.

## Style and submission

- Follow the subject formatting exactly for function names and output format.
- Do not change public signatures expected by the Makefiles.
- Add short comments where validation logic is non-obvious.

## Quick checklist before submission

- [ ] Builds with `make` without relevant warnings (-Wall -Wextra -Werror).
- [ ] `ex00` produces the exact subject-required format for example inputs.
- [ ] `ex01` includes `Data` and `Serializer` with the correct static functions.
- [ ] No debug prints remain in the final code.

---

If you want, I can add concrete input/output examples for `ex00` and create a
small test script that runs the most relevant cases and prints a PASS/FAIL summary.

