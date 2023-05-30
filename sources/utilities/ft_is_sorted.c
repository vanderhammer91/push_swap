/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:29:57 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:39:38 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_is_sorted(t_list *stack_a)
{
	t_list	*stack;

	stack = stack_a;
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
