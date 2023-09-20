/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:52:10 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/20 14:38:16 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cerrno>
# include <cstdlib>
# include <limits>
# include <cstring>

class ScalarConverter
{
	public :
		ScalarConverter(const char* value);
		virtual ~ScalarConverter();

		void		printChar(std::ostream &o = std::cout) const;
		void		printInt(std::ostream &o = std::cout) const;
		void		printFloat(std::ostream &o = std::cout) const;
		void		printDouble(std::ostream &o = std::cout) const;
		
		bool		getOutOfRange(void) const;
		bool		getStringError(void) const;

		static const int	charType = 0;
		static const int	intType = 1;
		static const int	floatType = 2;
		static const int	doubleType = 3;
		static const int	wrongType = 4;


	private :

		bool		_charConvGood;
		bool		_intConvGood;
		bool		_floatConvGood;
		bool		_doubleConvGood;

		char		_charValue;
		int			_intValue;
		float		_floatValue;
		double		_doubleValue;

		int			_isLimitBool;
		std::string	_limit;
		bool		_stringError;
		bool		_outOfRange;

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);

		bool		_isLimit(const char* value);
		int			_getType(const char* value);

		void		_convFromChar(const char* value);
		void		_convFromInt(const char* value);
		void		_convFromFloat(const char* value);
		void		_convFromDouble(const char* value);
};

std::ostream	&operator<<(std::ostream &o, const ScalarConverter &scalarconverter);

#endif