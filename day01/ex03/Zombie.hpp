/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:23:39 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 15:32:00 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <ctime>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <string>

class Zombie {

public:
	std::string	type = "pyro";
	std::string	name;
	Zombie();
	~Zombie();
	void	announce();

private:

};

#endif
