/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:33:29 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 16:17:36 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

#include "./../subject/searchable_bag.hpp"
#include "./../subject/array_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
public:
	searchable_array_bag();
	searchable_array_bag(const searchable_array_bag& other);
	searchable_array_bag&	operator=(const searchable_array_bag& other);

	bool	has(int value) const;
};

#endif