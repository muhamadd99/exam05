/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:42:26 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/28 11:28:17 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "limits.h"

class bigint {
private:
	std::vector<int> digits;
	void	trim();
	int		to_int() const;
public:
	bigint();
	bigint(unsigned long long n);
	bigint(const std::string& str);
	bigint(const bigint& other);
	bigint&	operator=(const bigint& other);
	~bigint();
	friend	std::ostream& operator<<(std::ostream& os, const bigint& other);
	bigint	operator+(const bigint& other) const;
	bigint&	operator+=(const bigint& other);
	bigint	operator++();
	bigint	operator++(int);
	//digitshift
	bigint	operator<<(int shift) const;
	bigint	operator<<(const bigint& other) const;
	bigint&	operator<<=(int shift);
	bigint&	operator<<=(const bigint& other);
	bigint	operator>>(int shift) const;
	bigint	operator>>(const bigint& other) const;
	bigint&	operator>>=(int shift);
	bigint&	operator>>=(const bigint& other);
	//comparison
	bool	operator<(const bigint& other) const;
	bool	operator>(const bigint& other) const;
	bool	operator==(const bigint& other) const;
	bool	operator!=(const bigint& other) const;
	bool	operator<=(const bigint& other) const;
	bool	operator>=(const bigint& other) const;
};

#endif