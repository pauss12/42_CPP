# Conversión y Almacenamiento de Datos en la Clase `Fixed`

Esta documentación explica cómo la clase `Fixed` gestiona y almacena números enteros y de punto flotante. Nuestro formato de punto fijo está diseñado para representar valores decimales de manera precisa dentro de un tipo de dato entero.

## El Problema

El desafío es cómo almacenar un número entero como el `42` en una estructura, ya que hay guardarlo en formato de bits.

* **`42` en binario (8 bits):** `00101010`
* **`42` en binario (32 bits):** `00000000 00000000 00000000 00101010`

Para poder transformar de binario a entero, la transformacion seria:

| Potencia | Fracción | Valor Decimal |
|:---:|:---:|:---:|
| $2^{10}$ | $1024/1$ | 1024 |
| $2^9$ | $512/1$ | 512 |
| $2^8$ | $256/1$ | 256 |
| $2^7$ | $128/1$ | 128 |
| $2^6$ | $64/1$ | 64 |
| $2^5$ | $32/1$ | 32 |
| $2^4$ | $16/1$ | 16 |
| $2^3$ | $8/1$ | 8 |
| $2^2$ | $4/1$ | 4 |
| $2^1$ | $2/1$ | 2 |
| $2^0$ | $1/1$ | 1 |
| $2^{-1}$ | $1/2$ | 0.5 |
| $2^{-2}$ | $1/4$ | 0.25 |
| $2^{-3}$ | $1/8$ | 0.125 |
| $2^{-4}$ | $1/16$ | 0.0625 |
| $2^{-5}$ | $1/32$ | 0.03125 |
| $2^{-6}$ | $1/64$ | 0.015625 |
| $2^{-7}$ | $1/128$ | 0.0078125 |
| $2^{-8}$ | $1/256$ | 0.00390625 |
| $2^{-9}$ | $1/512$ | 0.001953125 |
| $2^{-10}$ | $1/1024$ | 0.0009765625 |


Por ejemplo, si el número `42` se guardara directamente, sería interpretado como un valor fraccionario:

$$
\frac{1}{8} + \frac{1}{32} + \frac{1}{128} = 0.125 + 0.03125 + 0.0078125 = \textbf{0.1640625}
$$

Esto demuestra que simplemente guardar el número no es suficiente; necesitamos una estrategia para mantener su valor original.

---

## La Solución: Desplazamiento de Bits

La solución es **desplazar los bits** del número entero a la izquierda, reservando espacio para la parte fraccionaria. En nuestra clase, hemos definido que los últimos **8 bits** de nuestro número de 32 bits (`int`) estarán dedicados a la fracción.

 Por lo tanto, para poder mantener su valor, habria que guardar el valor 42.0

 - Primeros 24 bits bits serian la parte entera
 - Últimos 8 bits son la parte fraccionaria.

 
    `00000000 00000000 00101010 00000000`


