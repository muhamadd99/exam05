/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:44:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/01 11:03:43 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

#include "./../subject/searchable_bag.hpp"
#include "./../subject/tree_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag {
public:
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag& other);
	searchable_tree_bag&	operator=(const searchable_tree_bag& other);
	~searchable_tree_bag();

	bool	has(int) const;
};

#endif