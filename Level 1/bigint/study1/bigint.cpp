/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:46:43 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/27 01:12:21 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <climits>
#include <cstddef>
#include <algorithm>//hmm
#include <cctype>//hmm

void	bigint::trim()
{
	while (digits.size() > 1 && digits.back() == 0)
		digits.pop_back();
}

int		bigint::to_int() const
{
	long long res = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		res = res * 10 + digits[i];
		if (res > INT_MAX)
			return INT_MAX;
	}
	return res;
}

bigint::bigint() : digits(1, 0) {}

bigint::bigint(unsigned long long n)
{
	if (n == 0)
		digits.push_back(0);
	while(n)
	{
		digits.push_back(n % 10);
		n = n / 10;
	}
}

bigint::bigint(const std::string &s)
{
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if(std::isdigit(s[i]))
			digits.push_back(s[i] - '0');
	}
	if (digits.empty())
		digits.push_back(0);
	trim();
}

bigint::bigint(const bigint& other) :  digits(other.digits) {}

bigint&	bigint::operator=(const bigint& other)
{
	if (this != &other)
		digits = other.digits;
	return *this;
}

bigint::~bigint() {}

std::ostream&	operator<<(std::ostream& os, const bigint& other)
{
	for (int i = other.digits.size() - 1; i >= 0; i--)
		os << other.digits[i];
	return os;
}

//sum carry
bigint	bigint::operator+(const bigint& other) const
{
	size_t	size = std::max(digits.size(), other.digits.size());
	int		sum = 0;
	int		carry = 0;
	bigint	res;

	res.digits.clear();
	for (size_t i = 0; i < size || carry; i++)
	{
		sum = carry;
		if (i < other.digits.size())
			sum += other.digits[i];
		if (i < digits.size())
			sum += digits[i];
		res.digits.push_back(sum % 10);
		carry = sum / 10;
	}
	res.trim();
	return res;
}

bigint	bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}

bigint&	bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint tmp = *this;
	++(*this);
	return tmp;
}

bigint	bigint::operator<<(const int shift) const
{
	bigint res = *this;
	
	if (*this == bigint(0))
		return (bigint(0));
	res.digits.insert(res.digits.begin(), shift, 0);
	return res;
}

bigint	bigint::operator<<(const bigint& other) const
{
	bigint tmp = *this;
	tmp <<= other;
	return tmp;
}

bigint&	bigint::operator<<=(const int shift)
{
	*this = *this << shift;
	return *this;
}

bigint& bigint::operator<<=(const bigint& other)
{
	*this = *this << other.to_int();
	return *this;
}

bigint	bigint::operator>>(int shift) const
{
	bigint res = *this;
	if (shift >= (int)res.digits.size())
		return bigint(0);
	res.digits.erase(res.digits.begin(), res.digits.begin() + shift);
	res.trim();
	return (res);
}

bigint	bigint::operator>>(const bigint& other) const
{
	bigint tmp = *this;
	tmp >>= other;
	return tmp;
}

bigint&	bigint::operator>>=(const int shift)
{
	*this = *this >> shift;
	return *this;
}

bigint&	bigint::operator>>=(const bigint& other)
{
	*this = *this >> other.to_int();
	return *this;
}

bool	bigint::operator<(const bigint& other) const
{
	if (digits.size() != other.digits.size())
		return (digits.size() < other.digits.size());
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] != other.digits[i])
			return (digits[i] < other.digits[i]);
	}
	return false;
}
	
bool	bigint::operator>(const bigint& other) const
{
	if (digits.size() != other.digits.size())
		return (digits.size() > other.digits.size());
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] != other.digits[i])
			return (digits[i] > other.digits[i]);
	}
	return false;	
}

bool	bigint::operator<=(const bigint& other) const
{
	return(!(*this > other));
}

bool	bigint::operator>=(const bigint& other) const
{
	return(!(*this < other));
}

bool	bigint::operator==(const bigint& other) const
{
	if (digits.size() != other.digits.size())
		return (false);
	for (int i = 0; i < digits.size(); i++)
	{
		if (digits[i] != other.digits[i])
			return (false);
	}
	return true;
}

bool	bigint::operator!=(const bigint& other) const
{
	return(!(*this == other));
}