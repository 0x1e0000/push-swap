/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:55:39 by 0x10000           #+#    #+#             */
/*   Updated: 2021/07/09 00:29:31 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	if (argc > 1 && argv && !fill_stack(argv, &a))
		return (0);
	// if (is_sorted(a))
	// 	return (0);
	// Sort Algorithm HERE
	if (--argc == 2)
		swap(&a, "sa");
	else if (argc == 3)
		sort_3(&a);
	else if (argc == 4)
		sort_4(&a, &b, argc);
	else if (argc == 5)
		sort_5(&a, &b, argc);
	else if (argc <= 500)
		big_sort(&a, &b, --argc);
	visualize(a, b);
	return (0);
}
