/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:04:01 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//Retrieve the node that requires the least moves to be lined up with its 
//correct index in stack A.
t_list	*ft_get_cheapest_node(t_list **stack_b)
{
	t_list	*return_node;
	t_list	*s_stack_b;
	int		min_cost;

	return_node = *stack_b;
	s_stack_b = *stack_b;
	min_cost = s_stack_b->cost;
	while (s_stack_b != NULL)
	{
		if (s_stack_b->cost < min_cost)
		{
			return_node = s_stack_b;
			min_cost = return_node->cost;
		}
		s_stack_b = s_stack_b->next;
	}
	return (return_node);
}

//pops the top off and shifts the stack up. Saves moves by using rr.
void	ft_rr_both_move(t_list **stack_a, t_list **stack_b, t_list *c, int *st)
{
	int	stack_a_diff;
	int	stack_b_diff;
	int	min;

	stack_a_diff = c->cur_target_index;
	stack_b_diff = c->index;
	min = stack_a_diff;
	if (stack_b_diff < min)
	{
		ft_rr_stacks(stack_a, stack_b, stack_b_diff, st);
		stack_a_diff -= stack_b_diff;
		ft_r_stack_a(stack_a, stack_a_diff, st);
	}	
	else
	{
		ft_rr_stacks(stack_a, stack_b, stack_a_diff, st);
		stack_b_diff -= stack_a_diff;
		ft_r_stack_b(stack_b, stack_b_diff, st);
	}
}

//rrr pops bottom of the list to the top and shifts the whole list down 1.
//saves moves by using rrr.
void	ft_rrr_both_move(t_list **stack_a, t_list **stack_b, t_list *c, int *st)
{
	int	stack_a_diff;
	int	stack_b_diff;
	int	min;

	stack_a_diff = ft_lstsize(*stack_a) - c->cur_target_index;
	stack_b_diff = ft_lstsize(*stack_b) - c->index;
	min = stack_a_diff;
	if (stack_b_diff < min)
	{
		ft_rrr_stacks(stack_a, stack_b, stack_b_diff, st);
		stack_a_diff -= stack_b_diff;
		ft_rr_stack_a(stack_a, stack_a_diff, st);
	}	
	else
	{
		ft_rrr_stacks(stack_a, stack_b, stack_a_diff, st);
		stack_b_diff -= stack_a_diff;
		ft_rr_stack_b(stack_b, stack_b_diff, st);
	}
}

//Standard cost move: our desired element is in the a given half of their
//stack and our selected stack b node is in the opposite half of stack b.
void	ft_standard_move(t_list **stack_a, t_list **stack_b, t_list *c, int *st)
{
	int	temp;
	int	temp_diff;

	temp = c->cur_target_index;
	temp_diff = ft_lstsize(*stack_a) - c->cur_target_index;
	if (c->index <= ft_get_middex(stack_b))
		ft_r_stack_b(stack_b, c->index, st);
	else
		ft_rr_stack_b(stack_b, (ft_lstsize(*stack_b) - c->index), st);
	if (temp <= ft_get_middex(stack_a))
		ft_r_stack_a(stack_a, temp, st);
	else
		ft_rr_stack_a(stack_a, temp_diff, st);
}

//perform our cheapest move, by getting our cheapest node.
//its cost has been precalculated within ft_refresh_current_costs.
void	ft_cheapest_move(t_list **stack_a, t_list **stack_b, int *steps)
{
	t_list	*c;

	c = ft_get_cheapest_node(stack_b);
	if (!c)
		printf("NOPE!\n");
	else if (c->format == 'U')
		ft_rr_both_move(stack_a, stack_b, c, steps);
	else if (c->format == 'D')
		ft_rrr_both_move(stack_a, stack_b, c, steps);
	else if (c->format == 'S')
		ft_standard_move(stack_a, stack_b, c, steps);
	else
	{
		ft_printf("ERROR: Format undefined!\n");
		exit(EXIT_FAILURE);
	}
	c = NULL;
	*steps += ft_pa(stack_a, stack_b);
}
