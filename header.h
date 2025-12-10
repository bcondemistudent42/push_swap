/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:57:23 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/10 13:35:42 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int		*tab;
	int		size;
}		t_stack;

void	ft_print_tab(int *tab, int size);

void	ft_parser(char *str, t_stack *stack);

void	ft_putstr_fd(char *s, int fd);

void	ft_rr(t_stack *stack1, t_stack *stack2);

void	ft_rotate(t_stack *stack, char *str);

void	ft_push(t_stack *a, t_stack *b, char *str);

void	ft_ss(t_stack *stack_0, t_stack *stack_1);

void	ft_swap(t_stack *stack, char *str);

void	ft_reverse_rotate(t_stack *stack, char *str);

void	ft_rrr(t_stack *stack1, t_stack *stack2);

int		ft_which_format(char c, va_list arg);

int		ft_int_to_hex(unsigned long ptr, int verif, int len);

int		ft_putstr(char *str);

int		ft_putchar(char c);

int		ft_len_hex(unsigned long n);

int		ft_putnbr(int n, int len);

int		ft_unsigned_putnbr(int n, int len);

int		ft_int_to_hex_maj(unsigned long ptr, int verif, int len);

int		ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));

#endif
