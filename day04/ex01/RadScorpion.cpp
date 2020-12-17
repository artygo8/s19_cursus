/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

// Coplien /////////////////////////////////////////////////////////////////////

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	// std::cout << "Default constructor for RadScorpion called" << std::endl;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &source) : Enemy(source)
{
	// std::cout << "Copy constructor for RadScorpion called" << std::endl;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	// std::cout << "Destructor for RadScorpion called" << std::endl;
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion& RadScorpion::operator = (const RadScorpion &source)
{
	// std::cout << "Assignations operator for RadScorpion called" << std::endl;
	std::cout << "* click click click *" << std::endl;
	*this = source;
	return *this;
}

std::ostream &operator<<(std::ostream &out, RadScorpion const &obj)
{
	out << obj.getType() << " has " << obj.getHP() << " hp" << std::endl;
	return (out);
}
