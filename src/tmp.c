/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:26:54 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/06 12:16:48 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	visualize(t_list *a, t_list *b)
{
	t_list *curr_a;
	t_list *curr_b;

	int size_a = ft_lstsize(a);
	int size_b = ft_lstsize(b);
	int size = (size_a > size_b) ? size_a : size_b;

	curr_a = a;
	curr_b = b;
	printf("%s", YEL);
	printf(" ----- STACK_A -----   ||   ----- STACK_B -----\n");
	write(1, WHT, ft_strlen(WHT));
	for (int i = 0; i < size; i++)
	{
		printf("%s||        %-10s|| ~ ||        %-10s||\n", BLU, (size_a > i) ? ft_itoa(curr_a->content) : " ", (size_b > i) ? ft_itoa(curr_b->content) : " ");
		if (a && curr_a->next != NULL)
			curr_a = curr_a->next;
		if (b && curr_b->next != NULL)
			curr_b = curr_b->next;
	}
	printf("%s", YEL);
	printf("-----------------------------------------------\n");
	write(1, WHT, ft_strlen(WHT));
}
