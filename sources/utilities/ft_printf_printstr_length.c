/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printstr_length.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:40:46 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:26:53 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_printf_printstr_length(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
