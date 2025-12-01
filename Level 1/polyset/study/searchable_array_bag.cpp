/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:54:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 19:09:15 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag()
{}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other) : array_bag(other)
{}

searchable_array_bag&	searchable_array_bag::operator=(const searchable_array_bag& other)
{
	if (this != &other)
		array_bag::operator=(other);
	return *this;
}

searchable_array_bag::~searchable_array_bag()
{}


bool	searchable_array_bag::has(int value) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
			return true;
	}
	return false;
}