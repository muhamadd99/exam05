/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:20:05 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/28 23:02:10 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string> 
#include <vector>
#include "limits.h"

class bigint {
private:
	std::vector<int> digits;
	int		to_int() const;
	void	trim();
public:
	bigint();
	bigint(unsigned long long n);
	bigint(const std::string str);
	bigint(const bigint& other);
	bigint&	operator=(const bigint& other);
	~bigint();
	//addition, substraction
	bigint	operator+(const bigint& other) const;
	bigint	operator+=(const bigint& other);
	bigint&	operator++();
	bigint	operator++(int);
	friend	std::ostream& operator<<(std::ostream& os, const bigint& other);
	bigint	operator<<(int shift) const;
	bigint	operator<<(const bigint& other) const;
	bigint&	operator<<=(int shift);
	bigint&	operator<<=(const bigint& other);
	bigint	operator>>(int shift) const;
	bigint	operator>>(const bigint& other) const;
	bigint&	operator>>=(int shift);
	bigint&	operator>>=(const bigint& other);
	bool	operator<(const bigint& other) const;
	bool	operator>(const bigint& other) const;
	bool	operator==(const bigint& other) const;
	bool	operator!=(const bigint& other) const;
	bool	operator<=(const bigint& other) const;
	bool	operator>=(const bigint& other) const;
};

#endif