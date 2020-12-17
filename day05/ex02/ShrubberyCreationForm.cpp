/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(std::string cible) :
Form("ShrubberyCreationForm", 145, 137, cible)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) :
Form(source)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &source)
{
	*this = source;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// others //////////////////////////////////////////////////////////////////////

void	ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
	Form::execute(executor);
	
	std::ofstream shrubberyFile(getTarget() + "_shrubbery");
	shrubberyFile << "###########################'`################################\n\
###########################  V##'############################\n\
#########################V'  `V  ############################\n\
########################V'      ,############################\n\
#########`#############V      ,A###########################V\n\
########' `###########V      ,###########################V',#\n\
######V'   ###########l      ,####################V~~~~'',###\n\
#####V'    ###########l      ##P' ###########V~~'   ,A#######\n\
#####l      d#########l      V'  ,#######V~'       A#########\n\
#####l      ##########l         ,####V''         ,###########\n\
#####l        `V######l        ,###V'   .....;A##############\n\
#####A,         `######A,     ,##V' ,A#######################\n\
#######A,        `######A,    #V'  A########'''''##########''\n\
##########,,,       `####A,           `#''           '''  ,,,\n\
#############A,                               ,,,     ,######\n\
######################oooo,                 ;####, ,#########\n\
##################P'                   A,   ;#####V##########\n\
#####P'    ''''       ,###             `#,     `V############\n\
##P'                ,d###;              ##,       `V#########\n\
##########A,,   #########A              )##,    ##A,..,ooA###\n\
#############A, Y#########A,            )####, ,#############\n\
###############A ############A,        ,###### ##############\n\
###############################       ,#######V##############\n\
###############################      ,#######################\n\
##############################P    ,d########################\n\
##############################'    d#########################\n\
##############################     ##########################\n\
##############################     ##########################\n\
#############################P     ##########################\n\
#############################'     ##########################\n\
############################P      ##########################\n\
###########################P'     ;##########################\n\
###########################'     ,###########################\n\
##########################       ############################\n\
#########################       ,############################\n\
########################        d###########P'    `Y#########\n\
#######################        ,############        #########\n\
######################        ,#############        #########\n\
#####################        ,##############b.    ,d#########\n\
####################        ,################################\n\
###################         #################################\n\
##################          #######################P'  `V##P'\n\
#######P'     `V#           ###################P'\n\
#####P'                    ,#################P'\n\
###P'                      d##############P''\n\
##P'                       V##############'\n\
#P'                         `V###########'\n\
#'                             `V##P'\n\
\n\
                                                        GNN94\n\
";
	shrubberyFile.close();
}
