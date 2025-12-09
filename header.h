/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:57:23 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/09 18:13:56 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int		*tab;
	int		size;
}		t_stack;

void	print_tab(int *tab, int size);

void	parser(char *str, t_stack *stack);

int	ft_putstr_fd(char *s, int fd);

#endif
