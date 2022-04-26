/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:56:31 by soum              #+#    #+#             */
/*   Updated: 2022/04/26 13:32:49 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"
#include <ios>

Cast::Cast( std::string num_str )
{
	_cval = 0;
	_ival = 0;
	_fval = 0.0f;
	_dval = 0.0;
	_cvalOverFlowFlag = 0;
	_ivalOverFlowFlag = 0;
	_fvalOverFlowFlag = 0;
	checkNum(num_str);
	convert();
}

Cast::Cast( const Cast& cast )
{
	*this = cast;
}

Cast& Cast::operator=( const Cast &cast )
{
	_numStr = cast.getNumStr();
	checkNum(_numStr);
	convert();
	return (*this);
}

Cast::~Cast()
{}

std::string Cast::getType( void ) const
{
	return (_type);
}

std::string Cast::getNumStr( void ) const
{
	return (_numStr);
}

char Cast::getCval( void ) const
{
	return (_cval);
}

int Cast::getIval( void ) const
{
	return (_ival);
}
float Cast::getFval( void ) const
{
	return (_fval);
}
double Cast::getDval( void ) const
{
	return (_dval);
}

int Cast::getFlags( int idx ) const
{
	int result_flag = 0;

	if (idx == 0)
		result_flag = _cvalOverFlowFlag;
	else if (idx == 1)
		result_flag = _ivalOverFlowFlag;
	else if (idx == 2)
		result_flag = _fvalOverFlowFlag;
	return (result_flag);
}

Cast::MyException::MyException( const std::string err_msg )
	:_errMsg(err_msg)
{}

Cast::MyException::~MyException() throw()
{}

const char* Cast::MyException::what() const throw()
{
	return (_errMsg.c_str());
}

void Cast::checkNum( std::string num_str )
{
	std::stringstream string_s;
	int len = num_str.length();
	int idx = 0;

	if (len == 1 && !std::isdigit(num_str.at(0)))
	{
		_type = "ctype";
		_cval = num_str.at(0);
		_numStr = num_str;
		return ;
	}
	if (num_str.at(0) == '+' || num_str.at(0) == '-')
		idx++;
	_type = "itype";

	for (; idx < len; idx++)
	{
		if (num_str.at(idx) == '.' && _type != "dtype")
			_type = "dtype";
		else if (num_str.at(idx) == 'f' && idx == len -1)
		{
			_type = "ftype";
			break ;
		}
		else if (!std::isdigit(num_str.at(idx)))
		{
			_type = "unknown";
			break;
		}
	}

	if (_type == "unknown")
	{
		if (num_str == "nan"
				|| num_str == "inf"
				|| num_str == "+inf"
				|| num_str == "-inf")
		{
			_type = "dtype";
			_numStr = num_str;
			return ;
		}
		if (num_str == "nanf"
				|| num_str == "inff"
				|| num_str == "+inff"
				|| num_str == "-inff")
		{
			_type = "ftype";
			_numStr = num_str;
			_numStr.pop_back();
			return ;
		}
	}
	_numStr = num_str;

	if (_type == "itype")
	{
		long overflow_test;
		string_s.str(_numStr);
		while (string_s >> overflow_test);
		if (overflow_test > std::numeric_limits<int>::max()\
				|| overflow_test < std::numeric_limits<int>::min())
			throw MyException("overflow! you can not convert it");
	}
	else if(_type == "ftype")
	{
		double overflow_test;
		_numStr.pop_back();
		string_s.str(_numStr);
		while (string_s >> overflow_test);
		if (overflow_test > std::numeric_limits<float>::max()\
				|| overflow_test < std::numeric_limits<float>::min())
			throw MyException("overflow! you cna not convert it");
	}
	if (_type == "unknown")
		throw MyException("unknown type literal check string");
}

void Cast::convert( void )
{
	std::stringstream string_s;

	if (_type == "ctype")
		casting(_cval);
	else if (_type == "itype")
	{
		string_s.str(_numStr);
		while (string_s >> _ival);
		casting(_ival);
	}
	else if (_type == "dtype")
	{
		string_s.str(_numStr);
		while (string_s >> _dval);
		casting(_dval);
	}
	else if (_type == "ftype")
	{
		string_s.str(_numStr);
		while (string_s >> _fval);
		casting(_fval);
	}
}

void Cast::casting( char val )
{
	_ival = static_cast<int>(val);
	_fval = static_cast<float>(val);
	_dval = static_cast<double>(val);
}

void Cast::casting( int val )
{
	if (val > std::numeric_limits<char>::max() \
			|| val < std::numeric_limits<char>::min())
		_cvalOverFlowFlag = 1;
	else
		_cval = static_cast<char>(val);
	_fval = static_cast<float>(val);
	_dval = static_cast<double>(val);
}

void Cast::casting( float val )
{
	_dval = static_cast<double>(val);
	if (myIsnan(val) || myIsinf(val))
	{
		_cvalOverFlowFlag = 1;
		_ivalOverFlowFlag = 1;
		return ;
	}
	if (val > std::numeric_limits<char>::max() \
			|| val < std::numeric_limits<char>::min())
		_cvalOverFlowFlag = 1;
	else
		_cval = static_cast<char>(val);
	if (val > 2147483647.0 || val < -2147483648.0)
		_ivalOverFlowFlag = 1;
	else
		_ival = static_cast<int>(val);
}

void Cast::casting( double val )
{
	if (myIsnan(val) || myIsinf(val))
	{
		_cvalOverFlowFlag = 1;
		_ivalOverFlowFlag = 1;
		_fval = static_cast<float>(val);
		return ;
	}
	if (val > std::numeric_limits<char>::max() \
			|| val < std::numeric_limits<char>::min())
		_cvalOverFlowFlag = 1;
	else
		_cval = static_cast<char>(val);
	if (val > 2147483647.0 || val < -2147483648.0)
		_ivalOverFlowFlag = 1;
	else
		_ival = static_cast<int>(val);
	if (val > std::numeric_limits<float>::max() \
			|| val < std::numeric_limits<float>::min())
		_fvalOverFlowFlag = 1;
	else
		_fval = static_cast<float>(val);
}

bool Cast::myIsnan( float val )
{
	if ((*(int32_t *)(&val) & 0x7fffffff) == 0x7fffffff)
		return (true);
	return (false);
}

bool Cast::myIsnan( double val )
{
	if ((*(int64_t *)(&val) & 0x7fffffffffffffff) == 0x7fffffffffffffff)
		return (true);
	return (false);
}

bool Cast::myIsinf( float val )
{
	if ((*(int32_t *)(&val) & 0x7f800000) == 0x7f800000)
		return (true);
	if ((*(int32_t *)(&val) & 0xff800000) == 0xff800000)
		return (true);
	return (false);
}

bool Cast::myIsinf( double val )
{
	if ((*(int64_t *)(&val) & 0x7ff0000000000000) == 0x7ff0000000000000)
		return (true);
	if ((*(int64_t *)(&val) & 0xfff0000000000000) == 0xfff0000000000000)
		return (true);
	return (false);
}

std::ostream& operator<<(std::ostream &os, const Cast& cast)
{
	if (cast.getFlags(0))
		os << "char: impossible"  << std::endl;
	else if (!std::isprint(cast.getCval()))
		os << "char: " << "Non displayable" << std::endl;
	else
		os << "char: '" << cast.getCval() << "'" << std::endl;

	if (cast.getFlags(1))
		os << "int: impossible" << std::endl;
	else
		os << "int: " << cast.getIval() << std::endl;

	if (cast.getFlags(2))
		os << "float: impossible" << std::endl;
	else
	{
		if (cast.getType() == "itype" || cast.getType() == "ctype")
			os << "float: " << cast.getFval() << ".0";
		else
			os << "float: " << std::fixed << cast.getFval();
		os << "f" << std::endl;
	}

	if (cast.getType() == "itype" || cast.getType() == "ctype")
		os << "double: " << cast.getDval() << ".0";
	else
		os << "double: " << std::fixed << cast.getDval();
	return (os);
}
