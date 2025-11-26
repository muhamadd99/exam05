/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:45:04 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/26 23:44:51 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

class bigint {
private:
	std::vector<int> digits;
	void	trim();
	int		to_int() const;
public:
	bigint();
	bigint(unsigned long long n);
	bigint(const std::string& s);
	bigint(const bigint& other);
	bigint&	operator=(const bigint& other);
	~bigint();
	friend std::ostream& operator<<(std::ostream& os, const bigint& other);
	bigint operator+(const bigint& other) const;
	bigint operator+=(const bigint& other);
	//increment, decrement
	bigint&	operator++();
	bigint	operator++(int);
	//digitshift
	bigint	operator<<(const int shift) const;
	bigint	operator<<(const bigint& other) const;
	bigint&	operator<<=(const int shift);
	bigint&	operator<<=(const bigint& other);
	bigint	operator>>(const int shift) const;
	bigint	operator>>(const bigint& other) const;
	bigint&	operator>>=(const int shift);
	bigint& operator>>=(const bigint& other);
	//comparison
	bool	operator<(const bigint& other) const;
	bool	operator>(const bigint& other) const;
	bool	operator<=(const bigint& other) const;
	bool	operator>=(const bigint& other) const;
	bool	operator==(const bigint& other) const;
	bool	operator!=(const bigint& other) const;
};
