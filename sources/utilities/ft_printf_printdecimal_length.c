/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printdecimal_length.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/01 22:10:58 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_printf_printdecimal_length(int n)
{
	int	length;

	length = 1;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		length += ft_printf_printdecimal_length(n);
	}
	else if (n == 0)
		ft_putchar('0');
	else if (n >= 10)
	{
		length += ft_printf_printdecimal_length(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n % 10 + '0');
	return (length);
}
