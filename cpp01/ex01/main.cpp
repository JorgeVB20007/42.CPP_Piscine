/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:08:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/06/12 21:56:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void hordeAnnouncer(int num, Zombie* ptr)
{
	int a = 0;

	while (a < num)
	{
		std::cout << a << ". "; 
		ptr[a].announce();
		a++;
	}
}

int main()
{
	Zombie* ptr;
	int hordesize;
	
	std::cout << "\033[0;36mThis is a test.\033[0m" << std::endl;
	std::cout << "\033[0;32m  -----\033[0m" << std::endl << std::endl;

	hordesize = 5;
	std::cout << "\033[0;33mCreating a new array of " << hordesize << " Zombies named \"Atlantis\":\033[0m" << std::endl;
	ptr = zombieHorde(hordesize, "Atlantis");
	std::cout << "\033[0;33mDone. Announcing themselves:\033[0m" << std::endl;
	hordeAnnouncer(hordesize, ptr);
	std::cout << "\033[0;33mDeleting zombies:\033[0m" << std::endl;
	delete [] ptr;
	std::cout << std::endl << "\033[0;32m  -----\033[0m" << std::endl << std::endl;

	hordesize = 9;
	std::cout << "\033[0;33mCreating a new array of " << hordesize << " Zombies named \"Wakanda Metropolitano\":\033[0m" << std::endl;
	ptr = zombieHorde(hordesize, "Wakanda Metropolitano");
	std::cout << "\033[0;33mDone. Announcing themselves:\033[0m" << std::endl;
	hordeAnnouncer(hordesize, ptr);
	std::cout << "\033[0;33mDeleting zombies:\033[0m" << std::endl;
	delete [] ptr;
	std::cout << std::endl << "\033[0;32m  -----\033[0m" << std::endl << std::endl;
//	system("leaks manyzombies");
}
