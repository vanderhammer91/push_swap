/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:04:39 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:11:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//retrieve the node with the maximum content value within a given stack.
int	ft_get_maxdex(t_list **stack_a)
{
	int		max_content;
	int		max_index;
	t_list	*temp;

	max_index = -1;
	temp = *stack_a;
	max_content = temp->content;
	max_index = temp->index;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->content > max_content)
		{
			max_content = temp->content;
			max_index = temp->index;
		}
		temp = temp->next;
	}
	return (max_index);
}
