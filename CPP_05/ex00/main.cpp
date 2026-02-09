#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << YELLOW << "------------ CREATING A DEFAULT BUREAUCRAT --------------------- " << RESET << std::endl;
	Bureaucrat b0;

	std::cout << std::endl << YELLOW << "------------ CREATING A BUREAUCRAT WITH PARAMETERS --------------------- " << RESET << std::endl;
	Bureaucrat b1("Paula", 4);

	std::cout << std::endl << YELLOW << "------------ CREATING WITH COPY CONSTRUCTOR --------------------- " << RESET << std::endl;
	Bureaucrat b2(b1);
	std::cout << b2 << std::endl;

	std::cout << std::endl << YELLOW << "------------ CREATING WITH ASSIGN OPERATOR --------------------- " << RESET << std::endl;
	Bureaucrat b3;
	b3 = b1;
	std::cout << b3 << std::endl;

	std::cout << std::endl << YELLOW << "################################# TESTS ##############################" << RESET << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 1: INCREMENTING GRADE (100) --------------------- " << RESET << std::endl;
	Bureaucrat b4("John", 100);
	std::cout << b4 << std::endl;
	b4.incrementGrade();
	std::cout << b4 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 2: DECREMENTING GRADE (50) --------------------- " << RESET << std::endl;
	Bureaucrat b5("Jane", 50);
	std::cout << b5 << std::endl;
	b5.decrementGrade();
	std::cout << b5 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 3: GRADE TOO HIGH (0) --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b6("Alice", 0);
		std::cout << b6 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 4: GRADE TOO LOW (151) --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b7("Bob", 151);
		std::cout << b7 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 5: INCREMENTING GRADE TOO HIGH (1) --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b8("Charlie", 1);
		std::cout << b8 << std::endl;
		b8.incrementGrade();
		std::cout << b8 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 6: DECREMENTING GRADE TOO LOW (150) --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b9("David", 150);
		std::cout << b9 << std::endl;
		b9.decrementGrade();
		std::cout << b9 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 7: MÚLTIPLES INCREMENTOS HASTA LÍMITE --------------------- " << RESET << std::endl;
	Bureaucrat b10("Max", 5);
	std::cout << b10 << std::endl;
	for (int i = 0; i < 4; i++) 
	{
		b10.incrementGrade();
		std::cout << b10 << std::endl;
	}
	try {
		b10.incrementGrade();
		std::cout << b10 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Expected: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 8: MÚLTIPLES DECREMENTOS HASTA LÍMITE --------------------- " << RESET << std::endl;
	try {
		Bureaucrat b11("Min", 146);
		std::cout << b11 << std::endl;
		for (int i = 0; i < 4; i++) {
			b11.decrementGrade();
			std::cout << b11 << std::endl;
		}
		// Ahora está en grade 150, siguiente debe fallar
		b11.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "Expected: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 9: ASSIGN + MODIFY ORIGINAL --------------------- " << RESET << std::endl;
	Bureaucrat b12("Original", 10);
	Bureaucrat b13 = b12;  // Copy constructor
	std::cout << "Original: " << b12 << std::endl;
	std::cout << "Copia:    " << b13 << std::endl;
	b13.incrementGrade();  // Modificar copia NO afecta original
	std::cout << "Después de modificar copia:" << std::endl;
	std::cout << "Original: " << b12 << std::endl;
	std::cout << "Copia:    " << b13 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 10: CAPTURA EXCEPCIONES ESPECÍFICAS --------------------- " << RESET << std::endl;
	// Test que diferencia entre las dos excepciones
	try {
		Bureaucrat high("TooHigh", 0);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "✓ GradeTooHighException capturada: " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "✗ Debió ser GradeTooHighException" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "✗ Excepción genérica inesperada" << std::endl;
	}

	try {
		Bureaucrat low("TooLow", 151);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "✓ GradeTooLowException capturada: " << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "✗ Debió ser GradeTooLowException" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "✗ Excepción genérica inesperada" << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------ TEST 11: COPY DESTRUCTOR COMPLETO --------------------- " << RESET << std::endl;
	{
		Bureaucrat b14("Scoped", 75);
		std::cout << "Original en scope: " << b14 << std::endl;
	}  // b14 se destruye aquí
	Bureaucrat b15("PostScope", 75);
	std::cout << "Nuevo después del scope: " << b15 << std::endl;

	std::cout << std::endl << YELLOW << "------------ TEST 12: STRESS TEST (100 INC/DEC) --------------------- " << RESET << std::endl;
	Bureaucrat b16("Stress", 75);
	for (int i = 0; i < 50; i++) {
		b16.incrementGrade();
		b16.decrementGrade();  // Vuelve al mismo grade
	}
	std::cout << "Stress test OK: " << b16 << std::endl;

	std::cout << std::endl << YELLOW << "------------ END OF TESTS --------------------- " << RESET << std::endl;

	return (0);
}