/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:38:55 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 20:06:32 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	rra (reverse rotate a): 
 *
 *	Shift down all elements of stack a by 1.
 *	
 *	The last element becomes the first one.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_rra(t_list **stack_a)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		a_len;

	a_len = ft_lstsize(*stack_a);
	if (a_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_a))->content;
	temp = ft_lstlast(*stack_a);
	i = 0;
	while (i < (a_len - 1) && temp->prev)
	{
		temp->content = temp->prev->content;
		temp = temp->prev;
	}
	temp = *stack_a;
	temp->content = last_content;
	ft_printf("rra\n");
	return (1);
}

int	ft_rra_no_print(t_list **stack_a)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		a_len;

	a_len = ft_lstsize(*stack_a);
	if (a_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_a))->content;
	temp = ft_lstlast(*stack_a);
	i = 0;
	while (i < (a_len - 1) && temp->prev)
	{
		temp->content = temp->prev->content;
		temp = temp->prev;
	}
	temp = *stack_a;
	temp->content = last_content;
	return (1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	rrb (reverse rotate a): 
 *
 *	Shift down all elements of stack a by 1.
 *	
 *	The last element becomes the first one.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_rrb(t_list **stack_b)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		b_len;

	b_len = ft_lstsize(*stack_b);
	if (b_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_b))->content;
	temp = ft_lstlast(*stack_b);
	i = 0;
	while (i < (b_len - 1) && temp->prev)
	{
		temp->content = temp->prev->content;
		temp = temp->prev;
	}
	temp = *stack_b;
	temp->content = last_content;
	ft_printf("rrb\n");
	return (1);
}

int	ft_rrb_no_print(t_list **stack_b)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		b_len;

	b_len = ft_lstsize(*stack_b);
	if (b_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_b))->content;
	temp = ft_lstlast(*stack_b);
	i = 0;
	while (i < (b_len - 1) && temp->prev)
	{
		temp->content = temp->prev->content;
		temp = temp->prev;
	}
	temp = *stack_b;
	temp->content = last_content;
	return (1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	rrr :
 *
 *	rra and rrb at the same time.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	int	rra_check;
	int	rrb_check;

	rra_check = 0;
	rrb_check = 0;
	rra_check += ft_rra_no_print(stack_a);
	rrb_check += ft_rrb_no_print(stack_b);
	if (rra_check + rrb_check == 2)
	{
		ft_printf("rrr\n");
		return (1);
	}
	else
	{
		if (rra_check)
			ft_ra_no_print(stack_a);
		if (rrb_check)
			ft_rb_no_print(stack_b);
		return (0);
	}
}
