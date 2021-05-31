/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:55:39 by 0x10000           #+#    #+#             */
/*   Updated: 2021/05/31 01:05:32 by 0x10000          ###   ########.fr       */
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
	printf("***\n");
	print_stack(b);
	printf("------------\n");



	// swap(&a);
	// ss(&a, &b);
	// push(&a, &b);
	// rotate(&a);
	// rr(&a, &b);
	// r_rotate(&a);
	rrr(&a, &b);

	print_stack(a);
	printf("***\n");
	print_stack(b);
	return (0);
}
