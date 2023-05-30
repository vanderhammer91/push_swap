/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:29:05 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 22:15:11 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

//removes the first element of a given linked list.
void	ft_lstremove_front(t_list **lst)
{
	t_list	*temp;
	t_list	*curr;

	if (*lst == NULL)
		return ;
	temp = *lst;
	*lst = temp->next;
	if (*lst)
		(*lst)->prev = NULL;
	free (temp);
	curr = *lst;
	while (curr != NULL)
	{
		curr->index = (curr->index) - 1;
		curr = curr->next;
	}
}
