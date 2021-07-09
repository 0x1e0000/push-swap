/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:22:22 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/09 01:05:15 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_list **from, t_list **to, char *print)
{
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	if (print)
	{
		ft_putstr(print);
		write(1, "\n", 1);
	}
}
