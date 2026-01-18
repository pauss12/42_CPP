#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void acting_normal()
{
	std::cout << std::endl << YELLOW << "------------ CREATING CHARACTER ME WITH NAME CLOUD --------------------- " << RESET << std::endl;
	Character me("Cloud");

	std::cout << std::endl << YELLOW << "------------ CREATING MATERIAS \"ice\" and \"cure\" --------------------- " << RESET << std::endl;
	AMateria* ice = new Ice();
	std::cout << std::endl;
	AMateria* cure = new Cure();

	std::cout << std::endl << YELLOW << "------------ (ME) CHARACTER EQUIPS THE MATERIAS \"ice\" and \"cure\" --------------------- " << RESET << std::endl;
	me.equip(ice);
	std::cout << std::endl;
	me.equip(cure);

	std::cout << std::endl << YELLOW << "------------ (ME) CHARACTER USES THE MATERIAS ON HIMSELF --------------------- " << RESET << std::endl;
	me.use(0, me);
	std::cout << std::endl;
	me.use(1, me);

	std::cout << std::endl << YELLOW << "------------ UNEQUIP MATERIAS \"ice\" and \"cure\" --------------------- " << RESET << std::endl;
	me.unequip(0);
	std::cout << std::endl;
	me.unequip(1);

	std::cout << std::endl << YELLOW << "------------ CLEANING UP MEMORY (deleting materias) --------------------- " << RESET << std::endl;
	delete ice;
	delete cure;

	std::cout << std::endl << YELLOW << "------------ END OF FUNCTION --------------------- " << RESET << std::endl;
}

void cloning_materias_in_new_character()
{
	std::cout << std::endl << YELLOW << "------------ CREATING MATERIAS \"ice\" and \"cure\" --------------------- " << RESET << std::endl;
	AMateria* ice = new Ice();
	std::cout << std::endl;
	AMateria* cure = new Cure();

	std::cout << std::endl << YELLOW << "------------ CLONING THE MATERIAS --------------------- " << RESET << std::endl;
	AMateria* cloneIce = ice->clone();
	std::cout << std::endl;
	AMateria* cloneCure = cure->clone();

	std::cout << std::endl << YELLOW << "------------ SHOWING MEMORY ADDRESS FROM THE MATERIAS (cloned and original) --------------------- " << RESET << std::endl;
	std::cout << std::endl << "Las materias clonadas son: " << cloneIce->getType() << " y " << cloneCure->getType() << std::endl;
	std::cout << "CLONED   ==> " << cloneIce << " y " << cloneCure << std::endl;
	std::cout << "ORIGINAL ==> " << ice << " y " << cure << std::endl;

	std::cout << std::endl << YELLOW << "------------ CREATING NEW CHARACTER (mage) --------------------- " << RESET << std::endl;
	Character mage("Aerith");

	std::cout << std::endl << YELLOW << "------------ CLONED MATERIAS EQUIPPED TO NEW CHARACTER (mage)--------------------- " << RESET << std::endl;
	mage.equip(cloneIce);
	mage.equip(cloneCure);

	std::cout << std::endl << YELLOW << "------------ (MAGE) CHARACTER USES THE MATERIAS --------------------- " << RESET << std::endl;
	mage.use(0, mage);
	std::cout << std::endl;
	mage.use(1, mage);

	std::cout << std::endl << YELLOW << "------------ CLEANING UP MEMORY (deleting original materias) --------------------- " << RESET << std::endl;
	delete ice;
	delete cure;
	ice = NULL;
	cure = NULL;

	std::cout << std::endl << YELLOW << "------------ SHOWING MEMORY ADDRESS FROM THE MATERIAS AFTER DELETING (cloned and original) --------------------- " << RESET << std::endl;
	std::cout << "CLONED   ==> " << cloneIce << " y " << cloneCure << std::endl;
	std::cout << "ORIGINAL ==> " << ice << " y " << cure << std::endl;

	std::cout << std::endl << YELLOW << "------------ END OF FUNCTION --------------------- " << RESET << std::endl;
}

void trying_to_equip_more_than_four_materias()
{
	std::cout << std::endl << YELLOW << "------------ CREATING NEW CHARACTER (mage) --------------------- " << RESET << std::endl;
	Character mage("Tifa");

	std::cout << std::endl << YELLOW << "------------ EQUIPPING MORE THAN FOUR MATERIAS --------------------- " << RESET << std::endl;
	mage.equip(new Ice());
	std::cout << std::endl;
	mage.equip(new Cure());
	std::cout << std::endl;
	mage.equip(new Ice());
	std::cout << std::endl;
	mage.equip(new Cure());
	std::cout << std::endl;

	AMateria* extraMateria = new Cure();
	mage.equip(extraMateria); // no debería hacer nada (ya hay 4 materias)

	delete extraMateria;

	std::cout << std::endl << YELLOW << "------------ END OF FUNCTION --------------------- " << RESET << std::endl;
}


void trying_to_use_or_unequip_invalid()
{
	Character mage("Tifa");

	std::cout << std::endl << YELLOW << "------------ TRYING TO USE A MATERIA IN AN INVALID INDEX --------------------- " << RESET << std::endl;
	mage.use(0, mage);

	std::cout << std::endl << YELLOW << "------------ TRYING TO UNEQUIP A MATERIA WITH WRONG INDEX --------------------- " << RESET << std::endl;
	mage.unequip(4);

	std::cout << std::endl << YELLOW << "------------ END OF FUNCTION --------------------- " << RESET << std::endl;
}

void trying_cloning_character_and_then_equipping_materias_in_new_character()
{
	std::cout << std::endl << YELLOW << "------------ CREATING CHARACTER ME WITH NAME CLOUD --------------------- " << RESET << std::endl;
	Character me("Cloud");

	std::cout << std::endl << YELLOW << "------------ CREATING MATERIAS \"ice\" and \"cure\" --------------------- " << RESET << std::endl;
	AMateria* ice = new Ice();
	std::cout << std::endl;
	AMateria* cure = new Cure();

	std::cout << std::endl << YELLOW << "------------ (ME) CHARACTER EQUIPS THE MATERIAS \"ice\" and \"cure\" --------------------- " << RESET << std::endl;
	me.equip(ice);
	std::cout << std::endl;
	me.equip(cure);

	std::cout << std::endl << YELLOW << "------------ TRYING A DEEP COPY OF A CHARACTER --------------------- " << RESET << std::endl;
	Character copy(me);
	std::cout << std::endl;
	copy.use(0, copy);
	std::cout << std::endl;
	copy.use(1, copy);

	std::cout << std::endl << YELLOW << "------------ SAVING THE MATERIAS IN ANOTHER ARRAY BEFORE UNEQUIPPING --------------------- " << RESET << std::endl;
	AMateria* savedMaterias[4];
	for (int i = 0; i < 4; i++)
		savedMaterias[i] = copy.getMateria(i);

	std::cout << std::endl << YELLOW << "------------ UNEQUIPPING A MATERIA --------------------- " << RESET << std::endl;
	copy.unequip(0);
	std::cout << std::endl;
	copy.unequip(1);

	std::cout << std::endl << YELLOW << "------------ (COPY) CHARACTER USES THE MATERIAS --------------------- " << RESET << std::endl;
	copy.use(0, copy);
	std::cout << std::endl;
	copy.use(1, copy);

	std::cout << std::endl << YELLOW << "------------ (ME) CHARACTER USES THE MATERIAS --------------------- " << RESET << std::endl;
	me.use(0, me);
	std::cout << std::endl;
	me.use(1, me);

	std::cout << std::endl << YELLOW << "------------ UNEQUIP MATERIAS \"ice\" and \"cure\" FROM (ME) CHARACTER --------------------- " << RESET << std::endl;
	me.unequip(0);
	std::cout << std::endl;
	me.unequip(1);

	std::cout << std::endl << YELLOW << " ------------ NOW, \"ice\" and \"cure\" CAN BE DELETED --------------------- " << RESET << std::endl;
	delete ice;
	delete cure;
	ice = NULL;
	cure = NULL;

	std::cout << std::endl << YELLOW << "------------ (COPY) CHARACTER DELETES THE SAVED MATERIAS --------------------- " << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (savedMaterias[i])
			delete savedMaterias[i];
	}

	std::cout << std::endl << YELLOW << "------------ CLEANING UP MEMORY (deleting materias) --------------------- " << RESET << std::endl;
}

void materia_source_pruebas()
{
	std::cout << std::endl << YELLOW << "------------ CREATING MATERIA SOURCE --------------------- " << RESET << std::endl;
	MateriaSource src;

	std::cout << std::endl << YELLOW << "------------ LEARNING MATERIA ICE --------------------- " << RESET << std::endl;
	src.learnMateria(new Ice());

	std::cout << std::endl << YELLOW << "------------ LEARNING MATERIA CURE --------------------- " << RESET << std::endl;
	src.learnMateria(new Cure());

	std::cout << std::endl << YELLOW << "------------ CREATING MATERIA ICE --------------------- " << RESET << std::endl;
	AMateria* ice = src.createMateria("ice");

	std::cout << std::endl << YELLOW << "------------ CREATING MATERIA CURE --------------------- " << RESET << std::endl;
	AMateria* cure = src.createMateria("cure");

	std::cout << std::endl << YELLOW << "------------ DELETING MATERIA ICE --------------------- " << RESET << std::endl;
	delete ice;

	std::cout << std::endl << YELLOW << "------------ DELETING MATERIA CURE --------------------- " << RESET << std::endl;
	delete cure;

	std::cout << std::endl << YELLOW << "------------ END OF MATERIA SOURCE PRUEBAS --------------------- " << RESET << std::endl;
}

int main()
{
	acting_normal();
	// cloning_materias_in_new_character();
	// trying_to_equip_more_than_four_materias();
	// trying_to_use_or_unequip_invalid();
	// trying_cloning_character_and_then_equipping_materias_in_new_character();
	// materia_source_pruebas();

	return (0);
}
