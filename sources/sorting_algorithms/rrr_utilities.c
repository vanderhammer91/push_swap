/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:10:48 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//reverse rotate stack a a given number of rotations.
void	ft_rr_stack_a(t_list **stack_a, int rotations, int *steps)
{
	int	i;

	i = 0;
	while (i < rotations)
	{
		*steps += ft_rra(stack_a);
		i++;
	}	
}

//reverse rotate stack b a given number of rotations.
void	ft_rr_stack_b(t_list **stack_b, int rotations, int *steps)
{
	int	i;

	i = 0;
	while (i < rotations)
	{
		*steps += ft_rrb(stack_b);
		i++;
	}	
}

//reverse rotate both stacks a given number of rotations.
void	ft_rrr_stacks(t_list **stack_a, t_list **stack_b, int rot, int *st)
{
	int	i;

	i = 0;
	while (i < rot)
	{
		*st += ft_rrr(stack_a, stack_b);
		i++;
	}	
}
