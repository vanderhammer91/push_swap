/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_plus_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:24:52 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/04 12:51:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
PROTOTYPE
	t_list *ft_lstnew_plus_index(int content, int index);

PARAMETERS
	content: The content to create the node with.

RETURN 
	The new node.

EXTERNAL FUNCTIONS
	malloc

DESCRIPTION
	Allocates (with (malloc(3)) and returns a new node.
	The member variable 'content' is initialized with the value
	of the parameter 'content'. The variable 'next' is initialized to
	NULL.
*/
#include "../../includes/push_swap.h"

t_list	*ft_lstnew_plus_index(int content, int index)
{
	t_list	*my_list;

	my_list = (t_list *)malloc(sizeof(t_list));
	if (!my_list)
		return (NULL);
	my_list->content = content;
	my_list->index = index;
	my_list->prev = NULL;
	my_list->next = NULL;
	return (my_list);
}
