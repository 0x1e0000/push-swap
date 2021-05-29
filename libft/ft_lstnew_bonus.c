/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:15:22 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/29 15:03:50 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list			*list;

	if (!(list = (t_list*)malloc(sizeof(*list) + 1)))
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
