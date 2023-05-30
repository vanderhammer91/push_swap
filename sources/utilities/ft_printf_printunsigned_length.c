/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printunsigned_length.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:24:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/01 21:54:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_printf_printunsigned_length(unsigned int n)
{
	int		print_length;	

	print_length = 0;
	if (n >= 10)
		print_length += ft_printf_printunsigned_length(n / 10);
	print_length += ft_printf_printchar_length(n % 10 + '0');
	return (print_length);
}
