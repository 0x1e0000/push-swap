/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:55:39 by 0x10000           #+#    #+#             */
/*   Updated: 2021/05/30 21:29:53 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	// Check Arguments
	if (argc > 1 && argv && !fill_and_check(argv, &a))
		return (0);
	fill_and_check(argv, &b);
	print_stack(a);
	// printf("***\n");
	// print_stack(b);
	printf("------------\n");
	// swap(&a);
	// ss(&a, &b);
	// push(&a, &b);
	rotate(&a);
	print_stack(a);
	// printf("***\n");
	// print_stack(b);
	return (0);
}
