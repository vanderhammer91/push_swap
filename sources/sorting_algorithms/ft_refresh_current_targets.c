/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_current_targets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:17:30 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/24 15:27:00 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//refresh the element we are currently targeting within stack_a.
void	ft_refresh_current_targets(t_list **stack_a, t_list **stack_b)
{
	t_list 	*s_stack_b;
	t_list	*s_stack_a;
	int 	m_mindex;

	s_stack_b = *stack_b;
	m_mindex = ft_get_mindex(stack_a);
	while (s_stack_b != NULL)
	{
		s_stack_a = *stack_a;
		while (s_stack_a != NULL)
		{
			if (s_stack_a->next != NULL)
			{
				if (ft_is_sorted(*stack_a))
				{ 
					if (s_stack_b->content < s_stack_a->content
					&& s_stack_a->index == 0)
					{	
						s_stack_b->cur_target_index = 0;
						break;
					}
				}
				if  (s_stack_b->content > s_stack_a->content
					&& s_stack_b->content 
					< s_stack_a->next->content)
				{
					s_stack_b->cur_target_index = s_stack_a->index + 1;
					break;
				}
				else if	(s_stack_b->content > s_stack_a->content
					&& s_stack_a->next->index == ft_get_mindex(stack_a))
				{
					s_stack_b->cur_target_index = s_stack_a->index + 1;
					break;
				}
			}
			else
			{
				if (ft_is_sorted(*stack_a))
				{ 
					if (s_stack_b->content > s_stack_a->content)
					{	
						s_stack_b->cur_target_index = 0;
						break;
					}
				}
				if (s_stack_b->content < (*stack_a)->content
					&& s_stack_b->content > s_stack_a->content)
					s_stack_b->cur_target_index = 0;
				if (s_stack_b->content > s_stack_a->content
					&& ft_is_sorted(*stack_a))
				{
					s_stack_b->cur_target_index = (s_stack_a->index + 1);
				}
			}	
			if (s_stack_a->index  == m_mindex 
				&& s_stack_b->content 
				< s_stack_a->content)
			{
				s_stack_b->cur_target_index = s_stack_a->index;
				break;
			}
			s_stack_a = s_stack_a->next;
		}
		s_stack_b = s_stack_b->next;
	}
}
