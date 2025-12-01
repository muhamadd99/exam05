/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:37:50 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 18:54:45 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
private:
	searchable_bag& _bag;
public:
	//reference cannot be null
	set(searchable_bag& bag);
	set(const set& other);
	//reference cannot be changed
	~set();

	void	insert(int value);
	void	insert(int *array, int value);
	void	print() const;
	void	clear();
	const searchable_bag&	get_bag() const;
	bool	has(int value) const;
};

#endif