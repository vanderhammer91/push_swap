/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:07:04 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/02 18:14:02 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
PROTOTYPE
	int ft_lstsize(t_list *lst);

PARAMETERS
	lst: The beginning of the list.

RETURN VALUE
	The length of the list.

DESCRIPTION
	Counts the number of nodes in a list.
   */
#include "../../includes/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	while (lst)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}
