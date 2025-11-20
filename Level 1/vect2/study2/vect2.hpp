/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:50:29 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/20 16:41:43 by mbani-ya         ###   ########.fr       */
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
	vect2	operator+(const vect2& other) const;
	vect2&	operator+=(const vect2& other);
	vect2	operator-(const vect2& other) const;
	vect2&	operator-=(const vect2& other);
	vect2	operator*(const int nbr) const;
	vect2&	operator*=(const int nbr);
	//increment,decrement
	vect2&	operator++();
	vect2	operator++(int);
	vect2&	operator--();
	vect2	operator--(int);
	//comparison
	bool	operator==(const vect2& other) const;
	bool	operator!=(const vect2& other) const;
	//subscript
	int &operator[](int i);
	const int &operator[](int i) const;
	//signed
	vect2	operator+() const;
	vect2	operator-() const;
	friend std::ostream& operator<<(std::ostream& os, const vect2& other);
};

vect2 operator*(const int nbr, const vect2& other);

#endif