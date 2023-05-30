/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:42:02 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:43:22 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_sa(t_list *stack_a)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_a)) < 2)
		return (0);
	temp1 = stack_a->content;
	temp2 = stack_a->next->content;
	stack_a->content = temp2;
	stack_a->next->content = temp1;
	ft_printf("sa\n");
	return (1);
}

int	ft_sa_no_print(t_list *stack_a)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_a)) < 2)
		return (0);
	temp1 = stack_a->content;
	temp2 = stack_a->next->content;
	stack_a->content = temp2;
	stack_a->next->content = temp1;
	return (1);
}

int	ft_sb(t_list *stack_b)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_b)) < 2)
		return (0);
	temp1 = stack_b->content;
	temp2 = stack_b->next->content;
	stack_b->content = temp2;
	stack_b->next->content = temp1;
	ft_printf("sb\n");
	return (1);
}

int	ft_sb_no_print(t_list *stack_b)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_b)) < 2)
		return (0);
	temp1 = stack_b->content;
	temp2 = stack_b->next->content;
	stack_b->content = temp2;
	stack_b->next->content = temp1;
	return (1);
}

int	ft_ss(t_list *stack_a, t_list *stack_b)
{
	int	sa_check;
	int	sb_check;

	sa_check = 0;
	sb_check = 0;
	sa_check += ft_sa_no_print(stack_a);
	sb_check += ft_sb_no_print(stack_b);
	if (sa_check + sb_check == 2)
	{
		ft_printf("ss\n");
		return (1);
	}
	else
	{
		if (sa_check)
			ft_sa_no_print(stack_a);
		if (sb_check)
			ft_sb_no_print(stack_b);
		return (0);
	}
}
