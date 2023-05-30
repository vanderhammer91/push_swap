/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_steps_to_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:21:31 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:13:21 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//calculate how many steps a given element requires to be rotated to 
//the top of its given stack.
int	ft_get_steps_to_top(t_list **stack_x, int m_index)
{
	if (m_index <= ft_get_middex(stack_x))
		return (m_index);
	else
		return (ft_lstsize(*stack_x) - m_index);
}
