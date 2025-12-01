/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 15:57:11 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "./subject/searchable_bag.hpp"

class set {
private:
	searchable_bag&	_bag;
public:
	set(searchable_bag& bag);
	set(const set& other);
	set&	operator=(const set& other);
	~set();

	void	insert(int value);
	void	insert(int *array, int value);
	bool	has(int value);
	void	print() const;
	void	clear();
	const	searchable_bag&	get_bag() const;
};

#endif