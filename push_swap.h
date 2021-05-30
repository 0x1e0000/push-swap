/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:02:15 by 0x10000           #+#    #+#             */
/*   Updated: 2021/05/30 17:49:03 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Operations
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack);

// Sources
int		fill_and_check(char *argv[], t_list **stack);

// Tmp functions
# include <stdio.h>
void	print_stack(t_list *stack);

#endif
