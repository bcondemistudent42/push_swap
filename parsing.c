/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramaroud <ramaroud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:21 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/09 13:39:23 by ramaroud         ###   ########lyon.fr   */
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

int	*parser(char *str, t_stack *stack)
{
	int	nbr;
	int	i;
	int	j;

	j = 0;
	i = -1;
	nbr = 0;
	while(str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i += ft_atoi((str + i), &nbr) - 1;
			j++;
		}
	}
	stack->size = j;
	stack->tab = malloc(j * sizeof(int));
	j = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i += ft_atoi((str + i), &nbr) - 1;
			stack->tab[j++] = nbr;
		}
	}
}

void	print_tab(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("%d\n", tab[i]);
}

int	main(int ac, char **av)
{
	t_stack	a;

	parser(av[1], &a);
	printf("size: %d\n", a.size);
	print_tab(a.tab, a.size);
}
