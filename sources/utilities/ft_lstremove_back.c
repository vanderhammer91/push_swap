/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:49:16 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:15:01 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//removes the last element in a given linked list.
void	ft_lstremove_back(t_list **lst)
{
	t_list	*temp;
	t_list	*curr;

	if (*lst == NULL)
		return ;
	temp = (ft_lstlast(*lst))->prev;
	if (temp)
		temp->next = NULL;
	free (temp);
	curr = *lst;
	while (curr != NULL)
	{
		curr->index = (curr->index) + 1;
		curr = curr->next;
	}
}
