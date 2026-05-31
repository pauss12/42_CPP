# PmergeMe

Este ejercicio implementa una ordenación de enteros positivos usando el algoritmo de **merge-insert sort**, también conocido como **Ford-Johnson**.

La idea principal es ordenar dos veces la misma secuencia para comparar dos contenedores distintos: `std::vector` y `std::deque`.

## Uso

```bash
./PmergeMe 3 5 9 7 4
```

Salida esperada:

```text
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : ... us
Time to process a range of 5 elements with std::deque : ... us
```

Si algún argumento no es un entero positivo válido, el programa imprime `Error` en la salida de error estándar.

## Flujo general del programa

El código está dividido en tres piezas:

1. `main.cpp`
   - Su única tarea es crear un objeto `PmergeMe` y ejecutar el programa.

2. `PmergeMe.hpp`
   - Declara la clase `PmergeMe`.

3. `PmergeMe.cpp`
   - Contiene toda la lógica real: validación, ordenación, comparación de contenedores y medición de tiempo.

## Qué hace la clase `PmergeMe`

La clase recibe `argc` y `argv` en el constructor.

- Si no hay argumentos, o alguno no es un entero positivo, la instancia se marca como inválida.
- El método `execute()` es el que imprime el resultado final.

Esto mantiene `main` muy pequeño y deja la lógica encapsulada en una clase con el mismo nombre que el ejecutable.

## Validación de entrada

Antes de ordenar, el programa comprueba cada argumento:

- que no esté vacío,
- que solo contenga dígitos,
- que represente un número mayor que cero,
- y que no supere `INT_MAX`.

Si una sola entrada falla, el programa se detiene y muestra `Error`.

## Cómo funciona el algoritmo

La implementación sigue la idea de **merge-insert sort**:

1. Se toman los elementos de dos en dos.
2. En cada pareja, se coloca primero el menor y después el mayor.
3. Se construye una secuencia con los elementos mayores.
4. Esa secuencia se ordena de forma recursiva con el mismo procedimiento.
5. Después se insertan los elementos menores en la posición correcta usando búsqueda binaria.
6. Si queda un elemento sin pareja, se inserta al final con búsqueda binaria completa.

### Por qué funciona

La secuencia de elementos mayores ya queda ordenada antes de insertar los menores. Eso permite limitar la búsqueda del punto de inserción y mantener el resultado final ordenado.

### Por qué se llama Ford-Johnson

Ford-Johnson es una variante de ordenación por inserción optimizada para reducir comparaciones. La estructura básica que usamos aquí es la misma:

- emparejar,
- ordenar parcialmente,
- e insertar por búsqueda binaria.

## Estructuras auxiliares

El archivo `PmergeMe.cpp` usa una estructura pequeña llamada `Item`:

- `value`: el entero real que se ordena,
- `index`: un identificador temporal de la pareja actual.

Ese índice permite localizar el elemento “pareja” cuando toca insertar el elemento pequeño correspondiente.

También hay una estructura `PairData` que agrupa:

- el elemento pequeño,
- el elemento grande.

## Ordenación con dos contenedores

El programa ordena la misma entrada dos veces:

- una vez con `std::vector`,
- otra vez con `std::deque`.

Después compara ambos resultados. Si no coinciden, se considera un error.

Esto cumple la condición del ejercicio de usar al menos dos contenedores distintos.

## Medición de tiempo

El tiempo que se muestra incluye:

- la copia de los datos al contenedor,
- la transformación a `Item`,
- la ordenación,
- y la extracción del resultado final.

Se mide en microsegundos para que la diferencia entre `vector` y `deque` se vea con claridad.

## Estructura del código

### `main.cpp`

Solo contiene:

```cpp
int main(int argc, char *argv[])
{
    PmergeMe program(argc, argv);
    return program.execute();
}
```

### `PmergeMe.hpp`

Declara la clase pública.

### `PmergeMe.cpp`

Contiene:

- validación de argumentos,
- funciones auxiliares de ordenación,
- la implementación recursiva del merge-insert sort,
- la impresión de `Before` y `After`,
- y la medición de tiempo.

## Resumen mental rápido

Si quieres entender el código en una frase:

> el programa convierte cada número en un `Item`, separa la secuencia en parejas, ordena primero los elementos grandes y luego inserta los pequeños con búsqueda binaria hasta reconstruir la secuencia completa.
