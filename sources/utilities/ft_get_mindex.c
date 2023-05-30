/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:04:39 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:12:32 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//retrive the index of the node with the min content value in a given stack.
int	ft_get_mindex(t_list **stack_a)
{
	int		min_content;
	int		min_index;
	t_list	*temp;

	min_index = -1;
	temp = *stack_a;
	min_content = temp->content;
	min_index = temp->index;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->content < min_content)
		{
			min_content = temp->content;
			min_index = temp->index;
		}
		temp = temp->next;
	}
	return (min_index);
}
