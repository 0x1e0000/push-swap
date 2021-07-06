/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:02:15 by 0x10000           #+#    #+#             */
/*   Updated: 2021/07/06 12:15:50 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
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
int		fill_stack(char *argv[], t_list **stack);
void	error_(void);
int		get_next_line(int fd, char **line);
int		execute_instruction(char *instruction, t_list **a, t_list **b);
int		is_sorted(t_list *stack);

// Tmp
# include <stdio.h>
# define GREEN "\e[1;32m"
# define RED "\e[0;31m"
# define WHT "\e[0;37m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
void	visualize(t_list *a, t_list *b);

#endif
