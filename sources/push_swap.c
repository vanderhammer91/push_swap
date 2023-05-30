/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:37 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 21:59:53 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

//frees the list pointed to by start.
void	ft_free_list(t_list *start)
{
	t_list	*current;
	t_list	*next;

	current = start;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

//linesaving function for NORM
void	free_and_error(t_list **stack_a)
{
	ft_free_list(*stack_a);
	ft_error();
}

//linesaving function for NORM
void	assign_helper(t_list **prev_node, t_list **current_node)
{
	*prev_node = *current_node;
	*current_node = NULL;
}

//populates our stack_a with content and index.
//doubly links each node element to their following and previous elements.
void	populate_stack_a(int argc, char **argv, t_list **stack_a)
{
	t_list	*current_node;
	t_list	*prev_node;
	int		i;

	current_node = NULL;
	prev_node = NULL;
	i = 1;
	while (i < argc)
	{
		current_node = ft_lstnew_plus_index(atoi(argv[i]), i - 1);
		if (!current_node)
			free_and_error(stack_a);
		if (current_node->index != 0 && prev_node)
		{
			current_node->prev = prev_node;
			current_node->prev->next = current_node;
		}
		ft_lstadd_back(stack_a, current_node);
		if (i == (argc - 1))
			current_node->next = NULL;
		else
			assign_helper(&prev_node, &current_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		cost_steps;

	stack_a = NULL;
	stack_b = NULL;
	cost_steps = 0;
	if (argc < 2)
		exit(1);
	ft_check_inputs(argv);
	populate_stack_a(argc, argv, &stack_a);
	if (ft_is_sorted(stack_a))
	{
		ft_free_list(stack_a);
		free(stack_b);
		return (0);
	}
	cost_sort(&stack_a, &stack_b, &cost_steps);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}
