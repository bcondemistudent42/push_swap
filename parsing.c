/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:21 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/10 13:42:20 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "header.h"

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
		if (write(fd, &s[i], 1) == -1)
			return ;//error case to handle
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
	return (j);
}

void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = -1;
	printf("[ ");
	while (++i < size)
		printf("%d ", tab[i]);
	printf("]\n");
}

int	ft_check_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--medium", 8) == 0)
		return (2);
	else if (ft_strncmp(str, "--complexe", 10) == 0)
		return (3);
	else if (ft_strncmp(str, "--adaptive", 10) == 0)
		return (4);
	return (-1);
}

void	ft_parse_one(char *str, t_stack *stack)
void	ft_parser(char *str, t_stack *stack)
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

void	ft_parse_multiple(char **av, int len, t_stack *stack)
void	ft_print_tab(int *tab, int size)
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

void	ft_cocktail_shaker(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] > stack_a->tab[i + 1])
		{
			tmp = stack_a->tab[i];
			stack_a->tab[i] = stack_a->tab[i + 1];
			stack_a->tab[i + 1] = tmp;
			swapped = true;
		}
		i++;
	}
}

void	ft_parsing(int ac, char **av, int i)
{
	t_stack	a;
	t_stack	b;

	if ((i + 1) == ac)
		parse_one(av[i], &a);
	else
		parse_multiple((av + i), (ac - i), &a);
	print_tab(a.tab, a.size);
	printf("%f\n", compute_disorder(a));
}

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	flag = check_flag(av[i++]);
	if (flag == -1)
		return (ft_putstr_fd("Error\n", 2));
	parsing(ac, av, i);
	i = -1;
	ft_printf("[ ");
	while (++i < size)
		ft_printf("%d ", tab[i]);
	ft_printf("]\n");
}
