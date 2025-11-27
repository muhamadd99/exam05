/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:41:57 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/27 19:36:18 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
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
	//addition,substraction
	bigint	operator+(const bigint& other) const;
	bigint	operator+=(const bigint& other);
	//digitshift
	bigint	operator<<(const bigint& other) const;
	bigint	operator<<(const int shift) const;
	bigint&	operator<<=(const bigint& other);
	bigint&	operator<<=(const int shift);
	bigint	operator>>(const bigint& other) const;
	bigint	operator>>(const int shift) const;
	bigint&	operator>>=(const bigint& other);
	bigint&	operator>>=(const int shift);
	//increment, decrement
	bigint&	operator++();
	bigint	operator++(int);
	friend	std::ostream& operator<<(std::ostream& os,const bigint& other);
	//comparison
	bool	operator<(const bigint& other) const;
	bool	operator>(const bigint& other) const;
	bool	operator<=(const bigint& other) const;
	bool	operator>=(const bigint& other) const;
	bool	operator==(const bigint& other) const;
	bool	operator!=(const bigint& other) const;
};


#endif