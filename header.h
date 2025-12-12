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

# define BUFFER_SIZE 1
# define FLAG_BENCH    0x01
# define FLAG_SIMPLE   0x02
# define FLAG_MEDIUM   0x04
# define FLAG_COMPLEXE 0x08
# define FLAG_ADAPTIVE 0x10

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdbool.h>
#include <stdio.h>

typedef struct s_bench
{
	bool	b_switch;
	int		disorder;
	int		strats;
	int		ops[10];
}	t_bench;

typedef struct s_stack
{
	int		*tab;
	int		size; // to modif in unsigned int
}		t_stack;

/*-------------operation-------------*/
void	sa(t_stack *a, bool write_switch);
void	sb(t_stack *b, bool write_switch);
void	ss(t_stack *a, t_stack *b, bool write_switch);
void	pa(t_stack *a, t_stack *b, bool write_switch);
void	pb(t_stack *a, t_stack *b, bool write_switch);
void	ra(t_stack *b, bool write_switch);
void	rb(t_stack *b, bool write_switch);
void	rr(t_stack *a, t_stack *b, bool write_switch);
void	rra(t_stack *a, bool write_switch);
void	rrb(t_stack *b, bool write_switch);
void	rrr(t_stack *a, t_stack *b, bool write_switch);
/*-------------mandatory-------------*/
void	ft_safe_write(int fd, char *str, int len);
int		ft_putstr_fd(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_print_tab(int *tab, int size);
void	parse_one(char *str, t_stack *stack);
void	parse_multiple(char **av, int len, t_stack *stack);
t_stack	parsing(int *ac, char **av, int *i);
void	push_swap(t_stack *a, int flag, int disorder);
/*---------------bonus-----------------*/
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char s2[]);
int		ft_check_line(char *line);
void	ft_format(char **line, char buffer[]);
char	*get_next_line(int fd);

#endif
