/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:27:32 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/02 14:06:00 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG
#define	SEARCHABLE_TREE_BAG

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag {
public:
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag& other);
	searchable_tree_bag& operator=(const searchable_tree_bag& other);
	~searchable_tree_bag();
	
	bool has(int value) const;
};


#endif