/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:55:35 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/02 11:45:21 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0)
{}

vect2::vect2(int x, int y) : _x(x), _y(y)
{}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y)
{}

vect2&	vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

vect2::~vect2()
{}

std::ostream&	operator<<(std::ostream& os, const vect2& other)
{
	os << "{" << other._x << ", " << other._y << "}";
	return os;
}

const int&	vect2::operator[](int value) const
{
	if (value == 0)
		return _x;
	return _y;
}

int&	vect2::operator[](int value)
{
	if (value == 0)
		return _x;
	return _y;
}

vect2&	vect2::operator++()
{
	_x++;
	_y++;
	return *this;
}

vect2	vect2::operator++(int)
{
	vect2 old = *this;
	_x++;
	_y++;
	return old;
}

vect2&	vect2::operator--()
{
	_x--;
	_y--;
	return *this;
}

vect2	vect2::operator--(int)
{
	vect2	old = *this;
	_x--;
	_y--;
	return old;
}

vect2	vect2::operator+(const vect2& other) const
{
	vect2	tmp;
	
	tmp._x = _x + other._x;
	tmp._y = _y + other._y;
	
	return tmp;
}

vect2&	vect2::operator+=(const vect2& other)
{
	_x = _x + other._x;
	_y = _y + other._y;
	return *this;
}

vect2	vect2::operator-(const vect2& other) const
{
	vect2	tmp;
	tmp._x = _x - other._x;
	tmp._y = _y - other._y;
	return tmp;
}

vect2&	vect2::operator-=(const vect2& other)
{
	_x = _x - other._x;
	_y = _y - other._y;
	return *this;
}

vect2	vect2::operator*(int scalar) const
{
	vect2 tmp;
	tmp._x = _x * scalar;
	tmp._y = _y * scalar;
	return tmp;
}

vect2&	vect2::operator*=(int scalar)
{
	_x = _x * scalar;
	_y = _y * scalar;
	return *this;
}

vect2	vect2::operator+() const
{
	return *this;
}

vect2	vect2::operator-() const
{
	vect2 tmp;
	
	tmp._x = -_x;
	tmp._y = -_y;
	return tmp;
}

bool	vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}

bool	vect2::operator!=(const vect2& other) const
{
	return (!(_x == other._x && _y == other._y));	
}

vect2	operator*(int scalar, const vect2& other)
{
	return (other * scalar);
}