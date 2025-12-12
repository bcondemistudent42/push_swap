/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:21 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/11 13:18:37 by ramaroud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_safe_write(int fd, char *str, int len)
{
	if (write(fd, str, len) == -1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
	return (i);
}

float	ft_compute_disorder(t_stack stack)
{
	int	mistake;
	int	pairs;
	int	i;
	int	j;

	i = 0;
	j = 0;
	pairs = 0;
	mistake = 0;
	while (i < (stack.size - 1))
	{
		while (j < (stack.size - 1))
		{
			pairs++;
			if (stack.tab[i] > stack.tab[j])
				mistake++;
			j++;
		}
		i++;
	}
	return ((float)mistake / (float)pairs);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str, int *nbr)
{
	int	sign;
	int	i;
	int	j;

	i = 0;
	j = 0;
	sign = 1;
	*nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*nbr = *nbr * 10 + (str[i++] - 48);
		j++;
	}
	*nbr *= sign;
	if (j == 0)
    exit(write(2, "Error\n", 6));
	return (j);
}

void	ft_print_tab(int *tab, int size)
{
	size--;
	printf("[");
	while (size >= 0)
	{
		if (size == 0)
			printf("%d", tab[size--]);
		else
			printf("%d, ", tab[size--]);
	}
	printf("]\n");
}

static void  ft_check2(int *flag, int *count, int flag_bits)
{
  if (flag_bits == FLAG_BENCH)
  {
    (*flag) |= flag_bits;
    (*count)++;
    return ;
  }
	if ((*flag) & (FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEXE | FLAG_ADAPTIVE))
    exit(write(2, "Error\n", 6));
  (*flag) |= flag_bits;
  (*count)++;
}

static int	ft_check(char *str, int *flag)
{
	int	count;

	count = 0;
	if (strcmp(str, "--bench") == 0)
		ft_check2(flag, &count, FLAG_BENCH);
	else if (strcmp(str, "--simple") == 0)
		ft_check2(flag, &count, FLAG_SIMPLE);
	else if (strcmp(str, "--medium") == 0)
		ft_check2(flag, &count, FLAG_MEDIUM);
	else if (strcmp(str, "--complexe") == 0)
		ft_check2(flag, &count, FLAG_COMPLEXE);
	else if (strcmp(str, "--adaptive") == 0)
		ft_check2(flag, &count, FLAG_ADAPTIVE);
  else
    exit(write(2, "Error\n", 6));
	return (count);
}

int	ft_check_flag(char **av, int *i)
{
	int	flag;
	int	ret;
	int	j;

  if (av[*i][0] != '-' && av[*i][1] != '-')
    return (0);
	flag = 0;
	ret = 0;
	j = 0;
	while (av[*i + j] && j < 2)
	{
    if (av[*i + j][0] == '-' && av[*i + j][1] == '-')
      ret += ft_check(av[(*i) + j], &flag);
    else
      break ;
		j++;
	}
	(*i) += ret;
	return (flag);
}

void	parse_one(char *str, t_stack *stack)
{
	int	nbr;
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i += ft_atoi((str + i), &nbr) - 1;
			j++;
		}
	}
	stack->tab = malloc(j * sizeof(int));
	stack->size = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i += ft_atoi((str + i), &nbr) - 1;
			stack->tab[stack->size++] = nbr;
		}
	}
}

void	parse_multiple(char **av, int len, t_stack *stack)
{
	int	nbr;
	int	i;

	i = 0;
	stack->size = len;
	stack->tab = malloc(len * sizeof(int));
	while (i < len)
	{
		ft_atoi(av[i], &nbr);
		stack->tab[i] = nbr;
		i++;
	}
}

int	min_index(t_stack *a)
{
	int	min;
	int	i;
	int	j;

	i = 1;
	j = 0;
	min = a->tab[0];
	while (i < a->size)
	{
		if (a->tab[i] < min)
		{
			min = a->tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	select_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	index;

  (void)bench;
	while (a->size)
	{
		index = min_index(a);
		if (index <= (a->size / 2))
		{
			while (index-- > 0)
				ra(a, 1);
		}
		else
		{
			index = a->size - index;
			while (index-- > 0)
				rra(a, 1);
		}
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
}

t_stack parsing(int *ac, char **av, int *i)
{
	t_stack	a;
  int flag;

	flag = ft_check_flag(av, i);
	if (flag == -1)
		exit(write(2, "Error\n", 6));
	if (((*i) + 1) == (*ac))
		parse_one(av[(*i)], &a);
	else
		parse_multiple((av + (*i)), ((*ac) - (*i)), &a);
  (*i) = ft_compute_disorder(a);
  (*ac) = flag;
  return (a);
}

void  choose_algo(t_stack *a, t_stack *b, int flag, int disorder)
{
  t_bench bench;

  (void)disorder;
  //if (flag & FLAG_BENCH)
    //setup benchmark
  if (flag & FLAG_SIMPLE)
    select_sort(a, b, &bench);
  else if (flag & FLAG_MEDIUM)
    select_sort(a, b, &bench);
  else if (flag & FLAG_COMPLEXE)
    select_sort(a, b, &bench);
  else if (flag & FLAG_ADAPTIVE)
    select_sort(a, b, &bench);
  else
    select_sort(a, b, &bench);
}

void  push_swap(t_stack *a, int flag, int disorder)
{
  t_stack b;

  b.size = 0;
  b.tab = malloc(a->size * sizeof(int));
  if (!b.tab)
    exit(write(2, "Error\n", 6));
  choose_algo(a, &b, flag, disorder);
}
