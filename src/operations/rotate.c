/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:22:27 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/30 21:51:59 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_list **stack)
{
	t_list *tmp;
	t_list *head;

	if (!*stack)
		return ;
	head = (*stack)->next; // seconde node is the head
	tmp = *stack;
	tmp->next = NULL;
	while (tmp)
		tmp = tmp->next;
	tmp = *stack;
	*stack = head;
}
