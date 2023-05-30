/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:35 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:15:30 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//printers for debugging my code 
void	printer1(t_list *current_node)
{
	ft_printf("stack[%d] \t: %d ", current_node->index,
		current_node->content);
	ft_printf("\t, \tcur_targ_index:[%d], ",
		current_node->cur_target_index);
	ft_printf("\tsteps_cost: [%d], discount format[%c]\n",
		current_node->cost, current_node->format);
}

void	ft_print_status(t_list *stack_a, t_list *stack_b, char *title)
{
	int		i;
	t_list	*temp;

	ft_printf("\n*---%s---*\n*-----*\nstack a:\n*-----*\n", title);
	i = 0;
	temp = stack_a;
	while (i < ft_lstsize(stack_a))
	{
		printer1(temp);
		temp = temp->next;
		i++;
	}
	ft_printf("*-----*\nstack b:\n*-----*\n");
	i = 0;
	temp = stack_b;
	while (i < ft_lstsize(stack_b))
	{
		printer1(temp);
		temp = temp->next;
		i++;
	}
}
