/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:04:41 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/20 14:36:43 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if ( argc == 1)
	{
		std::cout << "Please enter 1 C++ litterals" << std::endl;
		return (1);
	}
	if ( argc > 2)
	{
		std::cout << "Please enter only 1 C++ litterals" << std::endl;
		return (1);
	}
	ScalarConverter convert(argv[1]);
	std::cout << convert << std::endl;
	return (0);
}