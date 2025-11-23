/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:16:26 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/23 12:58:23 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
private:
	int _x;
	int _y;
public:
	vect2();
	vect2(int paramX, int paramY);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();
	//addition
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);
	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);
	vect2 operator*(const int scalar) const;
	vect2& operator*=(const int scalar);
	//subscript
	int& operator[](int i);
	const int& operator[](int i) const;
	//comparison
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;
	//signed
	vect2 operator+() const;
	vect2 operator-() const;
	//incrementation
	vect2& operator++();
	vect2  operator++(int);
	vect2& operator--();
	vect2  operator--(int);
	friend std::ostream& operator<<(std::ostream& os, const vect2& other);
	
};

vect2	operator*(const int scalar, const vect2& other);

#endif