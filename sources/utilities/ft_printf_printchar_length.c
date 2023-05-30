/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printchar_length.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:46 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/01 21:54:33 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_printf_printchar_length(char n)
{
	if (write(1, &n, 1) < 0)
		return (-1);
	return (1);
}
