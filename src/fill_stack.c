/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:02:52 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/06 12:59:35 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int check_number(char *argv[], char *nbr, int i)
{
	int is_number;
	long long number;
	int j;

	is_number = 0;
	number = ft_atoi(nbr, &is_number);
	if ((*nbr == '+' || *nbr == '-') && *++nbr == '\0')
		error_();
	if (is_number || number > MAX_INT || number < MIN_INT)
		error_();
	j = 1;
	while (j != i)
	{
		if (number == ft_atoi(argv[j++], 0))
		{
			write(2, "Duplicated Number\n", 18);
			exit(1);
		}
	}
	return ((int)number);
}

int fill_stack(char *argv[], t_list **stack)
{
	int i;
	t_list *node;
	t_list *head;

	i = 1;
	if (*stack == NULL)
	{
		*stack = (t_list *)malloc(sizeof(t_list *));
		(*stack)->content = check_number(argv, argv[i], i);
		(*stack)->next = NULL;
	}
	head = *stack;
	while (argv[++i])
	{
		node = (t_list *)malloc(sizeof(t_list *));
		node->content = check_number(argv, argv[i], i);
		node->next = NULL;
		(*stack)->next = node;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (1);
}
