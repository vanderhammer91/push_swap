/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_middex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:04:39 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:12:50 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//retrieve the middle index value of a given stack.
int	ft_get_middex(t_list **stack_x)
{
	return (ft_lstsize(*stack_x) / 2);
}
