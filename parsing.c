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
		return (-1);
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
	printf("]");
}

static void  ft_check2(int *flag, int *count, int flag_bits)
{
	if ((*flag) & (FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEXE | FLAG_ADAPTIVE))
  {
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
  }
  else
  {
    (*flag) |= flag_bits;
    (*count)++;
  }
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

	ret = ft_atoi(av[*i], &j);
	if (ret != -1)
		return (0);
	flag = 0;
	ret = 0;
	j = 0;
	while (av[*i + j] && j < 2)
	{
		ret += ft_check(av[(*i) + j], &flag);
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

int	max_index(t_stack *a)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	max = a->tab[i];
	while (i < a->size)
	{
		if (a->tab[i] > max)
		{
			max = a->tab[i];
			j = i;
		}
		i++;
	}
	return (j);
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

void	select_sort(t_stack *a, t_stack *b)
{
	int	index;

	while (a->size)
	{
		index = min_index(a);
		if (index <= (a->size / 2))
		{
			while (index-- > 0)
				ra(a);
		}
		else
		{
			index = a->size - index;
			while (index-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
}

void	parsing(int ac, char **av, int i)
{
	t_stack	a;
	t_stack	b;

	b.size = 0;
	if ((i + 1) == ac)
		parse_one(av[i], &a);
	else
		parse_multiple((av + i), (ac - i), &a);
	b.tab = malloc(a.size * sizeof(int));
	ft_print_tab(a.tab, a.size);
	printf("\n");
	select_sort(&a, &b);
	ft_print_tab(a.tab, a.size);
	printf("\n");
}

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ac < 1)
		return (ft_putstr_fd("Error\n", 2));
	flag = ft_check_flag(av, &i);
	if (flag == -1)
		return (ft_putstr_fd("Error\n", 2));
	parsing(ac, av, i);
}
