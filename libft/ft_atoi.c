/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:36:59 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/25 21:54:01 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str, int *is_number)
{
	int				i;
	int				negativity;
	unsigned long	result;

	result = 0;
	negativity = 1;
	i = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
		negativity = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (!ft_isdigit(str[i]))
		is_number = 0;
	if (result > 2147483647 && negativity == 1)
		return (-1);
	if (result > 2147483648 && negativity == -1)
		return (0);
	return (result * negativity);
}
