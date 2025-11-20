/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:21:19 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/20 13:59:13 by mbani-ya         ###   ########.fr       */
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
	vect2(int paramX, int paramY);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();
	//math
	vect2 operator+(const vect2& other) const;
	vect2 operator-(const vect2& other) const;
	vect2 operator*(const int nbr) const;
	//increment
	vect2&	operator++();
	vect2	operator++(int);
	vect2&	operator--();
	vect2	operator--(int);
	//equal
	vect2&	operator+=(const vect2& other);
	vect2&	operator-=(const vect2& other);
	vect2&	operator*=(const int scalar);
	bool	operator==(const vect2& other) const;
	bool	operator!=(const vect2& other) const;
	//subscript
	int			&operator[](int i);
	const int	&operator[](int i) const;
	//signed
	vect2	operator+() const;
	vect2	operator-() const;
	friend std::ostream&	operator<<(std::ostream& o, const vect2& other);
};

vect2 operator*(const int nbr, const vect2& other);

#endif