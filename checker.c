/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:50:50 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/07 13:44:30 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	if (argc > 1 && argv && !fill_stack(argv, &a))
		return (0);
	if (is_sorted(a))
		return (0);
	while (get_next_line(0, &instruction))
	{
		execute_instruction(instruction, &a, &b);
		free(instruction);
	}
	free(instruction);
	if (!is_sorted(a))
	{
		write(2, RED, 7);
		write(2, "KO\n", 3);
		return (1);
	}
	write(2, GREEN, 7);
	write(2, "OK\n", 3);
	return (0);
}
