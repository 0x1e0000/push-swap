/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:55:39 by 0x10000           #+#    #+#             */
/*   Updated: 2021/05/23 00:57:42 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char *argv[])
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i][0]) && argv[i][0] != '-' && argv[i][0] != '+')
		{
			ft_putstr("Error\n");
			return (0);
		}
		j = 0;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr("Error\n");
				return (0);
			}
		}
	}
	return (1);
}

int main(int argc, char *argv[])
{
	// t_list *a;
	// t_list *b;

	if (argc > 1 && argv && !check_args(argv))
		return (0);

	return (0);
}
