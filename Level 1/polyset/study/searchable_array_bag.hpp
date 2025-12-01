/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:46:27 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 18:32:25 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag {
public:
	searchable_array_bag();
	searchable_array_bag(const searchable_array_bag& other);
	searchable_array_bag&	operator=(const searchable_array_bag& other);
	~searchable_array_bag();
	bool has(int value) const;

};

#endif