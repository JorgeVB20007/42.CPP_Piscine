/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:08:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/12 20:57:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* ptr;
	
	std::cout << "\033[0;36mThis is a test.\033[0m" << std::endl;
	std::cout << "\033[0;32m  -----\033[0m" << std::endl << std::endl;
	std::cout << "\033[0;33mExecuting randomChump() with the name \"Wakanda\":\033[0m" << std::endl;
	randomChump("Wakanda");
	std::cout << std::endl << "\033[0;32m  -----\033[0m" << std::endl << std::endl;

	std::cout << "\033[0;33mCreating a new Zombie named \"Atlantis\" (using newZombie):\033[0m" << std::endl;
	ptr = newZombie("Atlantis");
	std::cout << "\033[0;33mDone. Announcing itself:\033[0m" << std::endl;
	ptr->announce();
	std::cout << "\033[0;33mDeleting zombie:\033[0m" << std::endl;
	delete ptr;
	std::cout << std::endl << "\033[0;32m  -----\033[0m" << std::endl << std::endl;

	std::cout << "\033[0;33mCreating a new Zombie named \"Metropolis\" assigned to the old \"Atlantis\" pointer:\033[0m" << std::endl;
	ptr = newZombie("Metropolis");
	std::cout << "\033[0;33mDone. Announcing itself:\033[0m" << std::endl;
	ptr->announce();
	std::cout << "\033[0;33mDeleting zombie:\033[0m" << std::endl;
	delete ptr;
	std::cout << std::endl << "\033[0;32m  -----\033[0m" << std::endl << std::endl;
//	system("leaks zombies");
}
