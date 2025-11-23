/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:17:29 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/23 12:58:32 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0)
{}

vect2::vect2(int paramX, int paramY) : _x(paramX), _y(paramY)
{}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y)
{}

vect2& vect2::operator=(const vect2& other)
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

vect2 vect2::operator+(const vect2& other) const
{
	int x = _x + other._x;
	int y = _y + other._y;
	return vect2(x, y);
}

vect2& vect2::operator+=(const vect2& other)
{
	_x = _x + other._x;
	_y = _y + other._y;
	return *this;
}

vect2 vect2::operator-(const vect2& other) const
{
	int x = _x - other._x;
	int y = _y - other._y;
	return vect2(x,  y);
}

vect2& vect2::operator-=(const vect2& other)
{
	_x = _x - other._x;
	_y = _y - other._y;
	return *this;
}

vect2 vect2::operator*(const int scalar) const
{
	int x = _x * scalar;
	int y = _y * scalar;
	return vect2(x, y);
}

vect2& vect2::operator*=(const int scalar)
{
	_x = _x * scalar;
	_y = _y * scalar;
	return *this;	
}

int& vect2::operator[](int i)
{
	if (i == 0)
		return _x;
	return _y;	
}

const int& vect2::operator[](int i) const
{
	if (i == 0)
		return _x;
	return _y;
}

bool	vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}

bool	vect2::operator!=(const vect2& other) const
{
	return !(_x == other._x && _y == other._y);
}

vect2	vect2::operator+() const
{
	return *this;
}

vect2	vect2::operator-() const
{
	int x = -_x;
	int y = -_y;
	return vect2(x, y);
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
	vect2 old = *this;
	_x--;
	_y--;
	return old;
}

std::ostream&	operator<<(std::ostream& os, const vect2& other)
{
	os << "{" << other._x << ", " << other._y << "}";
	return os; 
}

vect2	operator*(const int scalar, const vect2& other)
{
	return (other * scalar);
}