/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:10:31 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:47:18 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	ra (rotate a): 
 *
 *	Shift up all elements of stack a by 1.
 *	
 *	The first element becomes the last one.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_ra(t_list **stack_a)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_a) <= 0)
		return (0);
	first_content = (*stack_a)->content;
	first_cur_target = (*stack_a)->cur_target_index;
	temp = *stack_a;
	i = 0;
	while (i < ((ft_lstsize(*stack_a)) - 1) && temp->next)
	{
		temp->content = temp->next->content;
		temp->cur_target_index = temp->next->cur_target_index;
		temp = temp->next;
	}	
	temp = ft_lstlast(*stack_a);
	temp->content = first_content;
	temp->cur_target_index = first_cur_target;
	ft_printf("ra\n");
	return (1);
}

int	ft_ra_no_print(t_list **stack_a)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_a) <= 0)
		return (0);
	first_content = (*stack_a)->content;
	first_cur_target = (*stack_a)->cur_target_index;
	temp = *stack_a;
	i = 0;
	while (i < ((ft_lstsize(*stack_a)) - 1) && temp->next)
	{
		temp->content = temp->next->content;
		temp->cur_target_index = temp->next->cur_target_index;
		temp = temp->next;
	}	
	temp = ft_lstlast(*stack_a);
	temp->content = first_content;
	temp->cur_target_index = first_cur_target;
	return (1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	rb (rotate b): 
 *
 *	Shift up all elements of stack b by 1.
 *	
 *	The first element becomes the last one.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_rb(t_list **stack_b)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_b) <= 0)
		return (0);
	first_content = (*stack_b)->content;
	first_cur_target = (*stack_b)->cur_target_index;
	temp = *stack_b;
	i = 0;
	while (i < ((ft_lstsize(*stack_b)) - 1) && temp->next)
	{
		temp->content = temp->next->content;
		temp->cur_target_index = temp->next->cur_target_index;
		temp = temp->next;
	}
	temp = ft_lstlast(*stack_b);
	temp->content = first_content;
	temp->cur_target_index = first_cur_target;
	ft_printf("rb\n");
	return (1);
}

int	ft_rb_no_print(t_list **stack_b)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_b) <= 0)
		return (0);
	first_content = (*stack_b)->content;
	first_cur_target = (*stack_b)->cur_target_index;
	temp = *stack_b;
	i = 0;
	while (i < ((ft_lstsize(*stack_b)) - 1) && temp->next)
	{
		temp->content = temp->next->content;
		temp->cur_target_index = temp->next->cur_target_index;
		temp = temp->next;
	}
	temp = ft_lstlast(*stack_b);
	temp->content = first_content;
	temp->cur_target_index = first_cur_target;
	return (1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *	rr :
 *
 *	ra and rb at the same time. 
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	int	check_ra;
	int	check_rb;

	check_ra = 0;
	check_rb = 0;
	check_ra += ft_ra_no_print(stack_a);
	check_rb += ft_rb_no_print(stack_b);
	if (check_ra + check_rb == 2)
	{
		ft_printf("rr\n");
		return (1);
	}
	else
	{
		if (check_ra)
			ft_rra_no_print(stack_a);
		if (check_rb)
			ft_rrb_no_print(stack_b);
		return (0);
	}
}
