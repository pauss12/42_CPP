
# CPP_06 — Complete guide

This directory contains the C++ exercises for module 06. The file below explains
what you need to compile, run and understand each exercise, with examples and
common troubleshooting tips.

## Structure

- `ex00/` — Scalar converter: detect and convert between `char`, `int`, `float`, `double`.
- `ex01/` — Serializer: convert pointers to `uintptr_t` and back to pointers.
- `ex02/` — Other exercises for the module (check the folder for details).

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

Important rules and edge cases:

- Signed literals: accept leading `+`/`-` (e.g. `-42`, `+3.5`).
- Scientific notation: accept `e` or `E` (e.g. `1e3`, `1.2E-4`).
- Suffix `f`: only allowed at the end for floats (e.g. `42.0f`).
- Pseudo-literals `nan`, `nanf`, `inf`, `inff`, `+inf`, `-inff` must be recognized.
- Converting to `int` or `char`: values with fractional parts should be `impossible`
  (do not truncate).
- Single printable non-digit character (length 1) should be detected as CHAR and
  printed between quotes: `char: 'c'`.

Common errors and quick fixes:

- `ERROR: Invalid literal` for `-42` → type detection may reject the sign; allow
  an initial `+`/`-` before validating digits.
- `float: impossible` for `42.0f` → float branch didn't recognize `FLOAT`; ensure
  suffix `f` is handled and mapped to FLOAT.
- `char: Non displayable` when input is `'c'` → avoid using `atoi` on single
  character strings; detect length-1 char literals and use `literal[0]`.

Debugging: add temporary prints or use `tester_improved.sh` (if present) to
compare YOUR OUTPUT vs EXPECTED.

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

