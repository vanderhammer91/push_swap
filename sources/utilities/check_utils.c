/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:51:35 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 16:58:52 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//checks for duplicates in the rest of argv.
int	ft_duplicate_check(int tmp, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_inputs(char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_is_numeric(argv[i]))
			ft_error();
		else if (tmp < -2147483648 || tmp > 2147483647)
			ft_error();
		else if (ft_duplicate_check((int)tmp, argv, i))
			ft_error();
		i++;
	}
}
