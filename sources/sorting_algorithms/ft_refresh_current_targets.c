/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_current_targets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:17:30 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:09:22 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//target calc for any element not end of the linked list. 
int	ft_next_notnull_case(t_list **stack_a, t_list *s_a, t_list *s_b)
{
	if (ft_is_sorted(*stack_a))
	{
		if (s_b->content < s_a->content && s_a->index == 0)
		{	
			s_b->cur_target_index = 0;
			return (1);
		}
	}
	if (s_b->content > s_a->content
		&& s_b->content < s_a->next->content)
	{
		s_b->cur_target_index = s_a->index + 1;
		return (1);
	}
	else if (s_b->content > s_a->content
		&& s_a->next->index == ft_get_mindex(stack_a))
	{
		s_b->cur_target_index = s_a->index + 1;
		return (1);
	}
	return (0);
}

//target calc logic for end of linked list.
int	ft_next_null_case(t_list **stack_a, t_list *s_a, t_list *s_b)
{
	if (ft_is_sorted(*stack_a))
	{
		if (s_b->content > s_a->content)
		{	
			s_b->cur_target_index = 0;
			return (1);
		}
	}
	if (s_b->content < (*stack_a)->content
		&& s_b->content > s_a->content)
		s_b->cur_target_index = 0;
	if (s_b->content > s_a->content
		&& ft_is_sorted(*stack_a))
	{
		s_b->cur_target_index = (s_a->index + 1);
	}
	return (0);
}

//target calc logic for special case.
int	ft_final_check(t_list *s_a, t_list *s_b, int m_mindex)
{
	if (s_a->index == m_mindex && s_b->content < s_a->content)
	{
		s_b->cur_target_index = s_a->index;
		return (1);
	}
	return (0);
}

//caller function for our cases.
int	checker(t_list **stack_a, t_list *s_a, t_list *s_b, int m_mindex)
{
	if (s_a->next != NULL)
	{
		if (ft_next_notnull_case(stack_a, s_a, s_b))
			return (1);
	}
	else
	{	
		if (ft_next_null_case(stack_a, s_a, s_b))
			return (1);
	}
	if (ft_final_check(s_a, s_b, m_mindex))
		return (1);
	return (0);
}

//refresh the nodes within stack b with their current target index'
//within stack a.
void	ft_refresh_current_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*s_b;
	t_list	*s_a;
	int		m_mindex;

	s_b = *stack_b;
	m_mindex = ft_get_mindex(stack_a);
	while (s_b != NULL)
	{
		s_a = *stack_a;
		while (s_a != NULL)
		{
			if (checker(stack_a, s_a, s_b, m_mindex))
				break ;
			s_a = s_a->next;
		}
		s_b = s_b->next;
	}
}
