/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:52:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/09/20 15:09:34 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ScalarConverter.hpp"

//// CONSTRUCTOR & DESTRUCTOR ////

ScalarConverter::ScalarConverter() : _charConvGood(false), _intConvGood(false), _floatConvGood(false), _doubleConvGood(false),
	_charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(0.0),
	_isLimitBool(false), _limit(""), _stringError(false), _outOfRange(false)
{
	return;
}

ScalarConverter::ScalarConverter(const char* value) : _charConvGood(false), _intConvGood(false), _floatConvGood(false), _doubleConvGood(false),
	_charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(0.0),
	_isLimitBool(false), _limit(""), _stringError(false), _outOfRange(false)
{
	int type;
	void (ScalarConverter::*functionArray[4])(const char *) = {&ScalarConverter::_convFromChar, &ScalarConverter::_convFromInt, &ScalarConverter::_convFromFloat, &ScalarConverter::_convFromDouble};

	if (_isLimit(value) == true)
		return;
	type = _getType(value);
	if (type == ScalarConverter::wrongType)
		_stringError = true;
	else
		(this->*(functionArray[type]))(value);
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

//// GETTERS ////

bool ScalarConverter::getOutOfRange(void) const
{
	return (this->_outOfRange);
}

bool ScalarConverter::getStringError(void) const
{
	return (this->_stringError);
}

//// FUNCTIONS ////

bool	ScalarConverter::_isLimit(const char* value)
{
	const std::string limitsArray[4] = {"inf", "+inf", "-inf", "nan"};
	int i = 0;

	while ( i < 4)
	{
		if (value == limitsArray[i] || value == limitsArray[i] + "f")
		{
			_isLimitBool = true;
			_limit = limitsArray[i];
			if (i == 1)
			_limit = limitsArray[0];
			_floatConvGood = true;
			_doubleConvGood = true;
			return (true);
		}
		i++;
	}
	return (false);
}

int		ScalarConverter::_getType(const char* value)
{
	int		i = 0;
	bool	isInt = true;
	bool	isFloat = false;
	bool	isNoNum = true;

	if (value[0] && value[1] == '\0' && (((value[i]) < '0' && (value[i]) > '9') || (value[i]) == ' '))
		return(ScalarConverter::charType);
	if (value[i] == '-' || value[i] == '+')
		i++;
	while (value[i] && value[i] >= '0' && value[i] <= '9')
	{
		i++;
		isNoNum = false;
	}
	if (value[i] == '.')
	{
		isInt = false;
		i++;
		while (value[i] && value[i] >= '0' && value[i] <= '9')
		{
			isInt = false;
			i++;
		}
	}
	if (value[i] == 'f')
	{
		isFloat = true;
		i++;
	}
	if (value[i] || isNoNum || (isFloat && isInt))
		return (ScalarConverter::wrongType);
	if (isFloat)
		return (ScalarConverter::floatType);
	if (isInt)
		return (ScalarConverter::intType);
	return (ScalarConverter::doubleType);
}

//// CONVERTER ////

void	ScalarConverter::_convFromChar(const char* value)
{
	_charValue = value[0];
	_charConvGood = true;
	_intValue = static_cast<int>(value[0]);
	_intConvGood = true;
	_floatValue = static_cast<float>(value[0]);
	_floatConvGood = true;
	_doubleValue = static_cast<double>(value[0]);
	_doubleConvGood = true;
}

void	ScalarConverter::_convFromInt(const char* value)
{
	if ((strlen(value) == 10 && strcmp(value, "2147483647") > 0)
		|| (value[0] == '-' && strlen(value) == 11 && strcmp(value + 1, "2147483648") > 0)
		|| (value[0] == '+' && strlen(value) == 11 && strcmp(value + 1, "2147483647") > 0))
	{
		_outOfRange = true;
		return ;
	}
	_intValue = atoi(value);
	_intConvGood = true;
	_floatValue = static_cast<float>(_intValue);
	_floatConvGood = true;
	_doubleValue = static_cast<double>(_intValue);
	_doubleConvGood = true;
	if (_intValue >= 0 && _intValue <= std::numeric_limits<char>::max())
	{
		_charValue = static_cast<char>(_intValue);
		_charConvGood = true;
	}
}

void	ScalarConverter::_convFromFloat(const char* value)
{
	char	*end = NULL;

	_floatValue =  std::strtof(value, &end);
	if (value == end)
	{
		_stringError = true;
		return ;
	}
	if (errno == ERANGE)
	{
		_outOfRange = true;
		return ;
	}
	_floatConvGood = true;
	_doubleValue = static_cast<double>(_floatValue);
	_doubleConvGood = true;
	if (_doubleValue >= std::numeric_limits<int>::min() && _doubleValue <= std::numeric_limits<int>::max())
	{
		_intValue = static_cast<int>(_floatValue);
		_intConvGood = true;
	}
	if (_intValue >= 0 && _intValue <= std::numeric_limits<char>::max())
	{
		_charValue = static_cast<char>(_intValue);
		_charConvGood = true;
	}
}

void	ScalarConverter::_convFromDouble(const char *value)
{
	char	*end = NULL;

	_doubleValue = std::strtod(value, &end);
	if (value == end)
	{
		_stringError = true;
		return ;
	}
	if (errno == ERANGE)
	{
		_outOfRange = true;
		return ;
	}
	_doubleConvGood = true;
	if (_doubleValue >= std::numeric_limits<float>::min() && _doubleValue <= std::numeric_limits<float>::max())
	{
		_floatValue =  static_cast<float>(_doubleValue);
		_floatConvGood = true;
	}
	if (_doubleValue >= std::numeric_limits<int>::min() && _doubleValue <= std::numeric_limits<int>::max())
	{
		_intValue = static_cast<int>(_floatValue);
		_intConvGood = true;
	}
	if (_intValue >= 0 && _intValue <= std::numeric_limits<char>::max())
	{
		_charValue = static_cast<char>(_floatValue);
		_charConvGood = true;
	}
}

//// PRINT ////

std::ostream	&operator<<(std::ostream &o, const ScalarConverter &ScalarConverter)
{
	if (ScalarConverter.getOutOfRange() == true)
		o << "Error: values out of range";
	else if (ScalarConverter.getStringError())
		o << "Error: string format error";
	else
	{
		ScalarConverter.printChar(o);
		ScalarConverter.printInt(o);
		ScalarConverter.printFloat(o);
		ScalarConverter.printDouble(o);
	}
	return (o);
};

void		ScalarConverter::printChar(std::ostream &o) const
{
	if (_charConvGood == false)
	{
		o << "char: Impossible" << std::endl;
		return;
	}
	else if (_charValue < 32 || _charValue > 126)
	{
		o << "char: Non Displayable" << std::endl;
		return;
	}
	else
	{
		o << "char: '" << _charValue << "'" << std::endl;
	}

}

void		ScalarConverter::printInt(std::ostream &o) const
{
	if (_intConvGood == false)
	{
		o << "int: Impossible" << std::endl;
		return;
	}
	else 
	{
		o << "int: " << _intValue << std::endl;
	}
}

void	ScalarConverter::printFloat(std::ostream &o) const
{
	if (_floatConvGood == false)
	{
		o << "float: impossible" << std::endl;
		return ;
	}
	if (_isLimitBool)
		o << "float: " << _limit + "f" << std::endl;
	else
	{
		o.precision(1);
		o << "float: " << std::fixed << _floatValue << "f" << std::endl;
	}
}

void	ScalarConverter::printDouble(std::ostream &o) const
{
	if (_doubleConvGood == false)
	{
		o << "double: impossible";
		return ;
	}
	if (_isLimitBool)
		o << "double: " << _limit;
	else
	{
		o.precision(1);
		o << "double: " << std::fixed << _doubleValue;
	}
}
