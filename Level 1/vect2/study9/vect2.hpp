/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:01:49 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/02 11:41:30 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>

class vect2 {
private:
	int	_x;
	int	_y;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2&	operator=(const vect2& other);
	~vect2();
	//extra
	friend	std::ostream& operator<<(std::ostream& os, const vect2& other);
	const int&	operator[](int value) const;
	int&		operator[](int value);
	//increment, decrement
	vect2&	operator++();
	vect2	operator++(int);
	vect2&	operator--();
	vect2	operator--(int);
	//addition/substraction/multiplication
	vect2	operator+(const vect2& other) const;
	vect2&	operator+=(const vect2& other);
	vect2	operator-(const vect2& other) const;
	vect2&	operator-=(const vect2& other);
	vect2	operator*(int scalar) const;
	vect2&	operator*=(int scalar);
	//signed
	vect2	operator+() const;
	vect2	operator-() const;
	//comparison
	bool	operator==(const vect2& other) const;
	bool	operator!=(const vect2& other) const;
};

vect2	operator*(int scalar, const vect2& other);

#endif