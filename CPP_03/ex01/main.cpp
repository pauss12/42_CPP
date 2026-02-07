/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:38:09 by pmendez-          #+#    #+#             */
/*   Updated: 2026/01/19 20:08:47 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int	main(void)
{
	// Constructor por defecto con nombre pasado como parametro
	ScavTrap*	troopy = new ScavTrap("Troopy");

	troopy->guardGate();
	troopy->attack("Target1");
 	troopy->takeDamage(5);
	troopy->beRepaired(3);

	// Constructor por copia
 	ScavTrap	troopy2(*troopy);
	troopy2.guardGate();
	troopy2.attack("Target2");

	// Constructor por la sobrecarga del operador igual
	ScavTrap troopy3;
	troopy3 = *troopy;
	
	// Troopy lo tengo que eliminar porque lo reserve con memoria dinámica.
	// Troopy2 no tengo que liberarlo porque lo estoy reservando en el stack, se libera cuando acaba la funcion
	delete troopy;
	return (0);
}