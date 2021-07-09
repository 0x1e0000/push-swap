/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:02:15 by 0x10000           #+#    #+#             */
/*   Updated: 2021/07/08 23:41:30 by 0x10000          ###   ########.fr       */
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
void	swap(t_list **stack, char *print);
void	ss(t_list **stack_a, t_list **stack_b, char *print);
void	push(t_list **from, t_list **to, char *print);
void	rotate(t_list **stack, char *print);
void	rr(t_list **stack_a, t_list **stack_b, char *print);
void	r_rotate(t_list **stack, char *print);
void	rrr(t_list **stack_a, t_list **stack_b, char *print);

// Sources
int		fill_stack(char *argv[], t_list **stack);
void	error_(void);
int		get_next_line(int fd, char **line);
int		execute_instruction(char *instruction, t_list **a, t_list **b);
int		is_sorted(t_list *stack);
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b, int argc);
void	sort_5(t_list **a, t_list **b, int argc);
void	big_sort(t_list **a, t_list **b, int argc);
void	exclude_min_max(t_list **a, t_list **b, int lenght, int i);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
int		get_middle(t_list *stack, int lenght);
int		get_index(t_list *a, int nbr);
int		get_closest_number(t_list *stack, int nbr);

// Tmp
# include <stdio.h>
# define GREEN "\e[1;32m"
# define RED "\e[0;31m"
# define WHT "\e[0;37m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
void	visualize(t_list *a, t_list *b);

#endif
