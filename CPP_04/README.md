# CPP04 - Polimorfismo y Funciones Virtuales (C++98)

Este módulo demuestra el **polimorfismo dinámico** en C++98 usando herencia y funciones virtuales. Permite que objetos de clases diferentes respondan de forma distinta a la misma llamada de método.

Por ejemplo, una clase principal "Animal" tiene la funcion "hablar()". Dos clases que heredan de ella, "Gato" y "Perro".
Cada uno tiene una forma de ejecucion, uno maulla y el otro ladra.

### `IMPORTANTE`
- Para poder crear el Gato, primero tienes que crear el Animal.
- Si no hay Animal, no puede haber Gato.

## Ejemplo Completo

```cpp
#include <iostream>
#include <vector>

class Animal {
	public:
		virtual ~Animal() {}  // Destructor virtual
		virtual void makeSound() const {
			std::cout << "I am an Animal" << std::endl;
		}
};

class Dog : public Animal {
public:
    void makeSound() const {
        std::cout << "¡Guau! ¡Guau!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const {
        std::cout << "¡Miau! ¡Miau!" << std::endl;
    }
};

int main() 
{
    std::vector<Animal*> animales;
    animales.push_back(new Dog());
    animales.push_back(new Cat());

    // Polimorfismo en acción
    std::cout << "=== CON VIRTUAL ===" << std::endl;
    for (const auto* animal : animales) {
        animal->makeSound();  // ¡Cada uno responde diferente!
    }

    // Limpieza de memoria
    for (auto* animal : animales) {
        delete animal;
    }
    return 0;
}
```

### Salida Esperada

```shell
=== CON VIRTUAL ===
¡Guau! ¡Guau!
¡Miau! ¡Miau!
```

#

### ¿Qué significa `Virtual`?

**`Virtual`** = Decide en tiempo de ejecución cuál función llamar según el objeto real, no el puntero. Es decir, ejecutaria el ***makeSound*** de Animal, no el de los respectivos animales.


### Salida Esperada

```shell
=== CON VIRTUAL ===
I am an Animal
I am an Animal
```
