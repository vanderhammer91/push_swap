/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/25 17:41:10 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

t_list *ft_get_cheapest_node(t_list **stack_b)
{
	t_list	*return_node;
	t_list	*s_stack_b;
	int	min_cost;

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

//placeholder.
void	ft_rr_both_move(t_list **stack_a, t_list **stack_b, t_list *c_node, int *steps)
{
	int stack_a_diff;
	int stack_b_diff;
	int min;

	stack_a_diff = c_node->cur_target_index;
	stack_b_diff = c_node->index;
	min = stack_a_diff;
	if (stack_b_diff < min )
	{
		ft_rr_stacks(stack_a, stack_b, stack_b_diff, steps);
		stack_a_diff -= stack_b_diff;
		ft_r_stack_a(stack_a, stack_a_diff, steps);
	}	
	else
	{
		ft_rr_stacks(stack_a, stack_b, stack_a_diff, steps);
		stack_b_diff -= stack_a_diff;
		ft_r_stack_b(stack_b, stack_b_diff, steps);
	}
}

//Reminder: rrr pops bottom of the list to the top and shifts the whole list down 1.
void	ft_rrr_both_move(t_list **stack_a, t_list **stack_b, t_list *c_node, int *steps)
{
	int stack_a_diff;
	int stack_b_diff;
	int min;

	stack_a_diff = ft_lstsize(*stack_a) - c_node->cur_target_index;
	stack_b_diff = ft_lstsize(*stack_b) - c_node->index;
	min = stack_a_diff;

	if (stack_b_diff < min )
	{
		ft_rrr_stacks(stack_a, stack_b, stack_b_diff, steps);
		stack_a_diff -= stack_b_diff;
		ft_rr_stack_a(stack_a, stack_a_diff, steps);
	}	
	else
	{
		ft_rrr_stacks(stack_a, stack_b, stack_a_diff, steps);
		stack_b_diff -= stack_a_diff;
		ft_rr_stack_b(stack_b, stack_b_diff, steps);
	}
}

void	ft_standard_move(t_list **stack_a, t_list **stack_b, t_list *c_node, int *steps)
{
	int	temp;
	int	temp_diff;

	temp = c_node->cur_target_index;
	temp_diff = ft_lstsize(*stack_a) - c_node->cur_target_index;

	if (c_node->index <= ft_get_middex(stack_b))
		ft_r_stack_b(stack_b, c_node->index, steps);
	else
		ft_rr_stack_b(stack_b, (ft_lstsize(*stack_b) - c_node->index), steps);
	if (temp <= ft_get_middex(stack_a))
		ft_r_stack_a(stack_a, temp, steps);
	else
		ft_rr_stack_a(stack_a, temp_diff, steps);
}

//perform our cheapest move.
void	ft_cheapest_move(t_list **stack_a, t_list **stack_b, int *steps)
{
	t_list *c_node;
	c_node = ft_get_cheapest_node(stack_b);
	if(!c_node)
		printf("NOPE!\n");
	else if (c_node->format == 'U')
		ft_rr_both_move(stack_a, stack_b, c_node, steps);
	else if (c_node->format == 'D')
		ft_rrr_both_move(stack_a, stack_b, c_node, steps);
	else if (c_node->format == 'S')
		ft_standard_move(stack_a, stack_b, c_node, steps);
	else
	{
		ft_printf("ERROR: Format undefined!\n");
		exit(EXIT_FAILURE);
	} 
	c_node = NULL;
	*steps += ft_pa(stack_a, stack_b);
}
