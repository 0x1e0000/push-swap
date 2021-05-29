/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:55:39 by 0x10000           #+#    #+#             */
/*   Updated: 2021/05/28 01:33:34 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_and_check(char *argv[], t_list **stack)
{
	int				i;
	int				j;
	int				is_number;
	unsigned long	number;
	t_list			*node;

	i = 0;
	while (argv[++i])
	{
		is_number = 0;
		node = NULL;
		(*stack)->content = ft_atoi(argv[i], &is_number);
		if (is_number || (*stack)->content > INT32_MAX)
		{
			ft_putstr("Error\n");
			return (0);
		}
		j = 1;
		while (j != i)
			if ((*stack)->content == ft_atoi(argv[j++], 0))
			{
				ft_putstr("Duplicated Number\n");
				return (0);
			}
	}
	return (1);
}

void	sa(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return ;

}

int main(int argc, char *argv[])
{
	t_list *a;
	// t_list *b;

	// Check Argunebts are only numbers
	// a = (t_list *)malloc((argc - 1) * sizeof(t_list *));
	a = NULL;
	if (argc > 1 && argv && !fill_and_check(argv, &a))
		return (0);
	sa(&a);
	return (0);
}
