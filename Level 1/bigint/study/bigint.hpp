/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:08:10 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/26 16:01:12 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>

class	bigint {
private:
	std::vector<int>	digits;
	void	trim();
	int		to_int() const;

public:
	bigint();
	bigint(unsigned long long n);
	bigint(const std::string& s);
	bigint(const bigint& other);
	bigint&	operator=(const bigint& copy);
	~bigint();

	friend std::ostream&	operator<<(std::ostream& os, const bigint& b);
	bigint&	operator++();
	bigint	operator++(int);
	bigint	operator+(const bigint& b) const;
	bigint&	operator+=(const bigint& b);
	//digitshift
	bigint	operator<<(int shift) const;
	bigint	operator<<(const bigint& b) const;
	bigint	operator>>(int shift) const;
	bigint	operator>>(const bigint& b) const;
	bigint&	operator<<=(int shift);
	bigint&	operator<<=(const bigint& b);
	bigint&	operator>>=(int shift);
	bigint&	operator>>=(const bigint& b);

	bool	operator<(const bigint& b) const;
	bool	operator>(const bigint& b) const;
	bool	operator<=(const bigint& b) const;
	bool	operator>=(const bigint& b) const;
	bool	operator==(const bigint& b) const;
	bool	operator!=(const bigint& b) const;
};