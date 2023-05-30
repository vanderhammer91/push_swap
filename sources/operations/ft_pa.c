/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:17:56 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:50:55 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	pa (push a):
 *
 *	Take the first element at the top of b and put it at the top of a.
 *	Do nothing if b is empty.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) <= 0)
		return (0);
	temp = ft_lstnew_plus_index((*stack_b)->content, 0);
	if (*stack_a == NULL)
	{
		ft_lstadd_front(stack_a, temp);
		*stack_a = temp;
	}
	else
	{
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		*stack_a = temp;
		temp = temp->next;
		while (temp != NULL)
		{
			temp->index += 1;
			temp = temp->next;
		}
	}
	ft_lstremove_front(stack_b);
	ft_printf("pa\n");
	return (1);
}

int	ft_pa_no_print(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) <= 0)
		return (0);
	temp = ft_lstnew_plus_index((*stack_b)->content, 0);
	if (*stack_a == NULL)
	{
		ft_lstadd_front(stack_a, temp);
		*stack_a = temp;
	}
	else
	{
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		*stack_a = temp;
		temp = temp->next;
		while (temp != NULL)
		{
			temp->index += 1;
			temp = temp->next;
		}
	}
	ft_lstremove_front(stack_b);
	return (1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	pb (push b): 
 *
 *	Take the first element at the top of a and put it at the top of b.
 *	Do nothing if a is empty.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 0)
		return (0);
	temp = ft_lstnew_plus_index((*stack_a)->content, 0);
	if (*stack_b == NULL)
	{
		ft_lstadd_front(stack_b, temp);
		*stack_b = temp;
	}
	else
	{
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
		*stack_b = temp;
		temp = temp->next;
		while (temp != NULL)
		{
			temp->index += 1;
			temp = temp->next;
		}
	}
	ft_lstremove_front(stack_a);
	ft_printf("pb\n");
	return (1);
}

int	ft_pb_no_print(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 0)
		return (0);
	temp = ft_lstnew_plus_index((*stack_a)->content, 0);
	if (*stack_b == NULL)
	{
		ft_lstadd_front(stack_b, temp);
		*stack_b = temp;
	}
	else
	{
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
		*stack_b = temp;
		temp = temp->next;
		while (temp != NULL)
		{
			temp->index += 1;
			temp = temp->next;
		}
	}
	ft_lstremove_front(stack_a);
	return (1);
}
