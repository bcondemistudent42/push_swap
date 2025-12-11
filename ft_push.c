/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:29:37 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/11 14:29:55 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_push(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[0] = b->tab[0];
	a->size++;
	i = 0;
	while (i < (b->size - 1))
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_safe_write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_safe_write(1, "pb\n", 3);
}
