/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:58:06 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/20 16:03:18 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

class Data
{
	public :
		Data(int value) : _value(value) {}
		int	getvalue()
		{
			return(_value);
		}

	private :
		Data();
		Data(Data const& other);
		Data& operator=(Data const& other);
		int _value;
};

#endif