/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:35:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/20 16:20:28 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public :
		static uintptr_t serialize(Data* ptr)
		{
			return (reinterpret_cast<uintptr_t>(ptr));
		}
		static Data* deserialize(uintptr_t raw)
		{
			return (reinterpret_cast<Data*>(raw));
		}
};

#endif