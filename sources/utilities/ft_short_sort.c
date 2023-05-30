/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:40:57 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:26:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//sort stack_a with only 3 elements.
void	ft_short_sort(t_list **stack_a, int *steps)
{
	int	maxdex;
	int	mindex;

	maxdex = -1;
	mindex = -1;
	if (ft_is_sorted(*stack_a))
		return ;
	maxdex = ft_get_maxdex(stack_a);
	if (maxdex == 1)
		*steps += ft_rra(stack_a);
	if (maxdex == 0)
		*steps += ft_ra(stack_a);
	mindex = ft_get_mindex(stack_a);
	if (mindex == 1)
		*steps += ft_sa(*stack_a);
}
