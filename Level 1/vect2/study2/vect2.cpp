/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:42:13 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/20 23:08:32 by mbani-ya         ###   ########.fr       */
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
	return (*this);
}

vect2::~vect2()
{}

vect2 vect2::operator+(const vect2& other) const
{
	int x = _x + other._x;
	int y = _y + other._y;
	return (vect2(x, y));	
}

vect2&	vect2::operator+=(const vect2& other)
{
	*this = *this + other;
	return (*this);
}

vect2 vect2::operator-(const vect2& other) const
{
	int	x = _x - other._x;
	int	y = _y - other._y;
	return (vect2(x, y));
}

vect2& vect2::operator-=(const vect2& other)
{
	*this = *this - other;
	return *this;
}

vect2	vect2::operator*(const int nbr) const
{
	int x = _x * nbr;
	int y = _y * nbr;
	return(vect2(x, y)); 
}

vect2&	vect2::operator*=(const int nbr)
{
	*this = *this * nbr;
	return *this; 
}


vect2& vect2::operator++()
{
	_x++;
	_y++;
	return(*this);
}

vect2 vect2::operator++(int)
{
	vect2	old = *this;
	_x++;
	_y++;
	return (old);
}

vect2&	vect2::operator--()
{
	_x--;
	_y--;
	return(*this);
}

vect2	vect2::operator--(int)
{
	vect2	old = *this;
	_x--;
	_y--;
	return (old);
}

bool	vect2::operator==(const vect2& other) const
{
	return(other._x == _x && other._y == _y);
}

bool	vect2::operator!=(const vect2& other) const
{
	return!(other._x == _x && other._y == _y);
}

int&	vect2::operator[](int i)
{
	if (i == 0)
		return _x;
	else
		return _y; 
}

const int&	vect2::operator[](int i) const
{
	if (i == 0)
		return _x;
	else
		return _y;
}

vect2		vect2::operator+() const
{
	return (*this);
}

vect2		vect2::operator-() const
{
	int x = -_x;
	int y = -_y;
	return (vect2(x, y));
}

std::ostream& operator<<(std::ostream& os, const vect2& other)
{
	os << "{" << other[0] << ", " <<  other[1] << "} ";
	return os;
}


vect2	operator*(const int nbr, const vect2& other)
{
	return (other * nbr);
}