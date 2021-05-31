/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:02:15 by 0x10000           #+#    #+#             */
/*   Updated: 2021/05/31 00:56:55 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Operations
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **from, t_list **to);
void	rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	r_rotate(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

// Sources
int		fill_and_check(char *argv[], t_list **stack);

// Tmp functions
# include <stdio.h>
void	print_stack(t_list *stack);

#endif
