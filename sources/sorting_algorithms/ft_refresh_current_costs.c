/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_current_costs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 18:04:48 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//getting the cost to rotate stack a and stack b to the top for a given element
//placement. In this case there is discount due to rr, rrr being used.
void	ft_set_top_rot_cost(t_list **stack_a, t_list **stack_b, t_list *s_b)
{
	int	cost_stack_a;
	int	cost_stack_b;
	int	max_cost;

	cost_stack_a = ft_get_steps_to_top(stack_a, s_b->cur_target_index);
	max_cost = cost_stack_a;
	cost_stack_b = ft_get_steps_to_top(stack_b, s_b->index);
	if (cost_stack_b > max_cost)
		max_cost = cost_stack_b;
	s_b->cost = max_cost;
	if ((s_b->index <= ft_get_middex(stack_b))
		&& s_b->cur_target_index <= ft_get_middex(stack_a))
		s_b->format = 'U';
	else if ((s_b->index > ft_get_middex(stack_b))
		&& s_b->cur_target_index > ft_get_middex(stack_a))
		s_b->format = 'D';
	else
		ft_set_standard_costs(stack_a, stack_b, s_b);
}

//updating the costs for a given element of stack b that is in less than ideal 
//conditions
void	ft_set_standard_costs(t_list **stack_a, t_list **stack_b, t_list *s_b)
{
	int	cost_stack_a;
	int	cost_stack_b;

	cost_stack_a = ft_get_steps_to_top(stack_a, s_b->cur_target_index);
	cost_stack_b = ft_get_steps_to_top(stack_b, s_b->index);
	s_b->cost = cost_stack_a + cost_stack_b;
	s_b->format = 'S';
}

//sets the current costs of moving a given element to its desired place in
//stack A.
void	ft_refresh_current_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*s_b;

	s_b = *stack_b;
	ft_refresh_current_targets(stack_a, stack_b);
	while (s_b != NULL)
	{
		if ((s_b->index <= ft_get_middex(stack_b))
			&& s_b->cur_target_index <= ft_get_middex(stack_a))
			ft_set_top_rot_cost(stack_a, stack_b, s_b);
		else if ((s_b->index > ft_get_middex(stack_b))
			&& s_b->cur_target_index > ft_get_middex(stack_a))
			ft_set_top_rot_cost(stack_a, stack_b, s_b);
		else
			ft_set_standard_costs(stack_a, stack_b, s_b);
		s_b = s_b->next;
	}
}
