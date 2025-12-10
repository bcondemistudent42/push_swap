/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:57:23 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/10 13:23:26 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*tab;
	int		size;
}		t_stack;

int		ft_putstr_fd(char *s, int fd);

float	compute_disorder(t_stack stack);

void	print_tab(int *tab, int size);

void	parsing(char *str, t_stack *stack);

void	ft_rr(t_stack *stack1, t_stack *stack2);

void	ft_rotate(t_stack *stack, char *str);

void	ft_push(t_stack *a, t_stack *b, char *str);

void	ft_ss(t_stack *stack_0, t_stack *stack_1);

void	ft_swap(t_stack *stack, char *str);

void	ft_reverse_rotate(t_stack *stack, char *str);

void	ft_rrr(t_stack *stack1, t_stack *stack2);

#endif
