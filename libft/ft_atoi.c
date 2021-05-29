/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:36:59 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/28 00:26:16 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int whitespace(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

unsigned long ft_atoi(const char *str, int *is_number)
{
	int i;
	int negativity;
	unsigned long result;

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
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		*is_number = 1;
	return (result * negativity);
}
