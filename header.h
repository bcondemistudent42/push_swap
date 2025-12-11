/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:57:23 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/11 14:57:37 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

typedef struct s_stack
{
	int		*tab;
	int		size; // to modif in unsigned int
}		t_stack;

void	ft_print_tab(int *tab, int size);

void	ft_parser(char *str, t_stack *stack);

int		ft_putstr_fd(char *s, int fd);

void	ft_safe_write(int fd, char *str, int len);

float	ft_compute_disorder(t_stack stack);

void	sa(t_stack *a);

void	sb(t_stack *b);

void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *stack);

void	rb(t_stack *stack);

void	rr(t_stack *stack1, t_stack *stack2);

void	rra(t_stack *stack);

void	rrb(t_stack *stack);

void	rrr(t_stack *stack1, t_stack *stack2);

void	ft_select_sort(t_stack *stack_a, t_stack *stack_b);

#endif
