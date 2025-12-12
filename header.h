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
# include <string.h>
#include <stdio.h>
#define FLAG_BENCH    (1 << 0)  // 00001
#define FLAG_SIMPLE   (1 << 1)  // 00010
#define FLAG_MEDIUM   (1 << 2)  // 00100
#define FLAG_COMPLEXE (1 << 3)  // 01000
#define FLAG_ADAPTIVE (1 << 4)  // 10000

typedef struct s_bench
{
  bool  b_switch;
  int disorder;
  int strats;
  int ops[10];
} t_bench;

typedef struct s_stack
{
	int		*tab;
	int		size; // to modif in unsigned int
}		t_stack;

/*-------------operation-------------*/
void	sa(t_stack *a, bool write_switch);
void	sb(t_stack *b, bool write_switch);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *stack, bool write_switch);
void	rb(t_stack *stack, bool write_switch);
void	rr(t_stack *stack1, t_stack *stack2);
void	rra(t_stack *stack, bool write_switch);
void	rrb(t_stack *stack, bool write_switch);
void	rrr(t_stack *stack1, t_stack *stack2);
/*-------------mandatory-------------*/
void	ft_safe_write(int fd, char *str, int len);
int	ft_putstr_fd(char *s, int fd);
void	ft_print_tab(int *tab, int size);
void	parse_one(char *str, t_stack *stack);
void	parse_multiple(char **av, int len, t_stack *stack);
t_stack parsing(int *ac, char **av, int *i);
void  push_swap(t_stack *a, int flag, int disorder);
/*---------------bonus-----------------*/
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char s2[]);
int		ft_check_line(char *line);
void	ft_format(char **line, char buffer[]);
char	*get_next_line(int fd);


#endif
