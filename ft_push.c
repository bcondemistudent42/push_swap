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

void	ft_push(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->size++;
	a->tab[a->size - 1] = b->tab[b->size - 1];
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
