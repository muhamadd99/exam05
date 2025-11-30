/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:41:33 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/30 15:03:42 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <limits.h>
#include <vector>

class bigint {
private:
	std::vector<int>	digits;
	int		to_int() const;
	void	trim();
public:
	bigint();
	bigint(unsigned long long n);
	bigint(const std::string& str);
	bigint(const bigint& other);
	bigint&	operator=(const bigint& other);
	~bigint();
	//addition
	friend	std::ostream& operator<<(std::ostream& os, const bigint& other);
	bigint	operator+(const bigint& other) const;
	bigint&	operator+=(const bigint& other);
	bigint&	operator++();
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
	bool	operator<=(const bigint& other) const;
	bool	operator>=(const bigint& other) const;
	bool	operator==(const bigint& other) const;
	bool	operator!=(const bigint& other) const;
};

#endif