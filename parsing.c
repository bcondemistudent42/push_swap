/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:21 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/09 17:57:46 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
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
	return (j);
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

void	parsing(int ac, char **av, int i)
{
	t_stack	a;
	t_stack b;
	if ((i + 1) == ac)
		parse_one(av[i], &a);
	else
		parse_multiple((av + i), (ac - i), &a);
	printf("size: %d\n", a.size);
	print_tab(a.tab, a.size);
}

void	print_tab(int *tab, int size)
{
	int	i;

	i = -1;
	printf("[ ");
	while (++i < size)
		printf("%d ", tab[i]);
	printf("]\n");
}

int	check_flag(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	flag = check_flag(av[i]);
	if (flag > 0)
		i++;
	printf("i: %d\nac: %d\n", i, ac);
	parsing(ac, av, i);
}
