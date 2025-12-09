/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:45:31 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/09 18:13:17 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sa(t_stack *my_stack)
{
	int	temp;

	if (my_stack->size == 0 || my_stack->size == 1)
		return ;
	temp = my_stack->tab[1];
	my_stack->tab[1] = my_stack->tab[0];
	my_stack->tab[0] = temp;
	ft_printf("sa\n");
	return ;
}

void	ft_push(t_stack *a, t_stack *b)
{
	int	i;
	int	*new_tab;

	if (b->size == 0)
	{
		// to see if we need to free(b.tab);
		return ;
	}
	new_tab = malloc((sizeof(int)) * (a->size + 1));
	if (!new_tab)
	{
		// mayb free a.tab to see with other function
		return ;
	}
	i = 1;
	new_tab[0] = b->tab[0];
	while (i - 1 < a->size)
	{
		new_tab[i] = a->tab[i - 1];
		i++;
	}
	free(a->tab);
	a->tab = new_tab;
	a->size++;
	return ;
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack b;

	parser(av[1], &a);
	printf("size: %d\n", a.size);
	b.tab = malloc(a.size * sizeof(int));
	b.size = a.size;
	//test
	print_tab(a.tab, a.size);
}
