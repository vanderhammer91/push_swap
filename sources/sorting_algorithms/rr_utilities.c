/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/25 17:41:10 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

void	ft_r_stack_a(t_list **stack_a, int rotations, int *steps)
{
	int i;
	
	i = 0;
	while (i < rotations)
	{
		*steps += ft_ra(stack_a);
		i++;
	}	
}

void	ft_r_stack_b(t_list **stack_b, int rotations, int *steps)
{
	int i;
	
	i = 0;
	while (i < rotations)
	{
		*steps += ft_rb(stack_b);
		i++;
	}	
}

void	ft_rr_stacks(t_list **stack_a, t_list **stack_b, int rotations, int *steps)
{
	int i;
	
	i = 0;
	while (i < rotations)
	{
		*steps += ft_rr(stack_a, stack_b);
		i++;
	}	
}
