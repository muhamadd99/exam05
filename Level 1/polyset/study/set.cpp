/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:49:55 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 19:08:09 by mbani-ya         ###   ########.fr       */
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
		_bag.insert(value);
}

void	set::insert(int *array, int size)
{
	for (int i = 0; i < size; i++)
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

const searchable_bag&	set::get_bag() const
{
	return _bag;
}

bool	set::has(int value) const
{
	return(_bag.has(value));
}