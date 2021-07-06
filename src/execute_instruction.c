/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:02:27 by mait-si-          #+#    #+#             */
/*   Updated: 2021/07/06 22:56:57 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap_(char *str, t_list **a, t_list **b)
{
	if (*str == 'a' && *(str + 1) == '\0')
	{
		swap(a, NULL);
		return (1);
	}
	else if (*str == 'b' && *(str + 1) == '\0')
	{
		swap(b, NULL);
		return (1);
	}
	else if (*str == 's' && *(str + 1) == '\0')
	{
		ss(a, b, NULL);
		return (1);
	}
	error_();
	return (0);
}

static int	push_(char *str, t_list **a, t_list **b)
{
	if (*str == 'a' && *(str + 1) == '\0')
	{
		push(b, a, NULL);
		return (1);
	}
	else if (*str == 'b' && *(str + 1) == '\0')
	{
		push(a, b, NULL);
		return (1);
	}
	error_();
	return (0);
}

static int	rotate_(char *str, t_list **a, t_list **b)
{
	if (*str == 'a' && *(str + 1) == '\0')
	{
		rotate(a, NULL);
		return (1);
	}
	else if (*str == 'b' && *(str + 1) == '\0')
	{
		rotate(b, NULL);
		return (1);
	}
	else if (*str == 'r' && *(str + 1) == '\0')
	{
		rr(a, b, NULL);
		return (1);
	}
	error_();
	return (0);
}

static int	r_rotate_(char *str, t_list **a, t_list **b)
{
	if (*str == 'a' && *(str + 1) == '\0')
	{
		r_rotate(a, NULL);
		return (1);
	}
	else if (*str == 'b' && *(str + 1) == '\0')
	{
		r_rotate(b, NULL);
		return (1);
	}
	else if (*str == 'r' && *(str + 1) == '\0')
	{
		rrr(a, b, NULL);
		return (1);
	}
	error_();
	return (0);
}

int	execute_instruction(char *instruction, t_list **a, t_list **b)
{
	if (*instruction == 's')
		return (swap_(++instruction, a, b));
	else if (*instruction == 'p')
		return (push_(++instruction, a, b));
	else if (*instruction == 'r' && ft_strlen(instruction) == 2)
		return (rotate_(++instruction, a, b));
	else if (*instruction++ == 'r' && *instruction == 'r')
		return (r_rotate_(++instruction, a, b));
	error_();
	return (0);
}
