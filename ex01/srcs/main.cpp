/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:05:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/20 16:15:31 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"

int main(void)
{
	Data* data = new Data(36);

	uintptr_t serialized = Serializer::serialize(data);
	Data* unserialized = Serializer::deserialize(serialized);

	if (data == unserialized)
	{
		std::cout << "Both pointer are equals" << std::endl;
		std::cout << "Data: " << data << std::endl;
		std::cout << "Unserialized: " << unserialized << std::endl;
	}
	else
	{
		std::cout << "Both pointer are NOT equals" << std::endl;
		std::cout << "Data: " << data << std::endl;
		std::cout << "Unserialized: " << unserialized << std::endl;	
	}
}