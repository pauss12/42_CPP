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

## Operación CONSTRUCTOR con un float

En el caso del número `42.42f`; para no perder la información, hay que multiplicarlo por el numero de bits reservados; es decir, $2^8$  == 256.

***42.42f X 256 (1 << _bits) = 10859.52***

Ahora la parte fraccionaria ".42", estaria guardada en la parte entera del resultado "10859", por eso se puede redondear 
sin perder mucha informacion.

`roundf(value * 256)` == `roundf(42.42f X 256)` == `10860`

```zsh
   Fixed::Fixed(float const value)
   {
      std::cout << "Float constructor called" << std::endl;
      this->_value = roundf(value * (1 << _bits));
   }
```

## Operación TO INT 

Es decir, transformar el value, que esta en bits, y transformarlo a numero entero.

   `00000000 00000000 00101010 00000000`

Se aplicaría la siguiente operación:

```bash
   int Fixed::toInt(void) const
   {
      return (this->_value >> this->_bits);
   }
```

Para tranformarlo en: `00000000 00000000 00000000 00101010`

## Operación TO FLOAT

En este caso, al contrario que en el constructor de float, en vez de multiplicar por el numero de bits reservados, en este caso seria dividir entre ese numero, es decir, dividir  por $2^8$. Por lo que la operacion seria: 

```zsh
   float Fixed::toFloat(void) const
   {
      return (this->_value / (float)(1 << this->_bits));
   }
```
Para poder transformarlo en: `10859 / $2^8$` == `10859 / 256` == `42.41796875` ==  `42.42`

## BINARIO NÚMERO DE PUNTO FLOTANTE

En este caso, es diferente, se divide en 3 partes:

   1. **Signo (1 bit)**: Si es `0` significa que el numero es positivo. Si es `1` significa que el número es negativo.
   2. **Exponente (8 bits)**: Indican donde esta el punto decimal. 
   3. **Mantisa (23 bits)**: Representan los digitos más representativos del número


