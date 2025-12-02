/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:15:00 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/02 14:27:06 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag& bag) : _bag(bag)
{}

set::set(const set& other) : _bag(other._bag)
{}

set::~set()
{}

void	set::insert(int value)
{
	if (!(_bag.has(value)))
		return (_bag.insert(value));
}

void	set::insert(int *array, int value)
{
	for(int i = 0; i < value; i++)
	{
		if (!(_bag.has(array[i])))
			_bag.insert(array[i]);
	}
}

void	set::print() const
{
	_bag.print();
}

void	set::clear()
{
	_bag.clear();
}

const searchable_bag& set::get_bag() const
{
	return _bag;
}

bool	set::has(int value) const
{
	return(_bag.has(value));
}