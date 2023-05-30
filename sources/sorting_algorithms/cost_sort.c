/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:47:38 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 20:08:40 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

/*FUNCTION: COST_SORT
 *	1. CALCULATE THE COST TO MOVE A GIVEN ELEMENT FROM THE 
 *			STACK B INTO THEIR CORRECT SPOT ON STACK A
 *	
 *	2. PROCEED WITH THE CHEAPEST MOVE. LEAVE STACK A IN ORDERED PLACE.
 *	 (CONSIDERING DISCOUNT CASES)	
 *
 *	3.REFRESH TARGET-COST VALUES IN NODES WITHIN STACK B 
 *		BASED UPON CURRENT ROTATION OF A AND NEW NODES.
 *
 *	4.REPEAT STEPS 4 TO 6 UNTIL [SOLVED]. (Recall: STACK_A STAYS SORTED,
 *	(BUT NOT ALWAYS ROTATED CORRECTLY)
 */

void	cost_sort(t_list **stack_a, t_list **stack_b, int *steps)
{
	int	i;

	if (ft_is_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
		return ;
	while ((ft_lstsize(*stack_a)) > 3)
		*steps += ft_pb(stack_a, stack_b);
	ft_short_sort(stack_a, steps);
	ft_refresh_current_costs(stack_a, stack_b);
	i = 0;
	while (ft_lstsize(*stack_b) > 0)
	{
		ft_cheapest_move(stack_a, stack_b, steps);
		ft_refresh_current_costs(stack_a, stack_b);
		i++;
	}
	if (ft_get_mindex(stack_a) <= ft_get_middex(stack_a))
	{
		while (ft_get_mindex(stack_a) != 0)
			*steps += ft_ra(stack_a);
	}
	else
	{
		while (ft_get_mindex(stack_a) != 0)
			*steps += ft_rra(stack_a);
	}
}
