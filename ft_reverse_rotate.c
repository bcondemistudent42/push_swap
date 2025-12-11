/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:36:03 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/11 14:40:49 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;
	int	temp2;

	if (stack->size == 0)
		return ;
	i = stack->size;
	temp = stack->tab[stack->size - 1];
	while (i > 0)
	{
		temp2 = stack->tab[i];
		stack->tab[i] = stack->tab[i - 1];
		stack->tab[i - 1] = temp2;
		i--;
	}
	stack->tab[0] = temp;
	return ;
}

void	rra(t_stack *stack)
{
	ft_reverse_rotate(stack);
	ft_safe_write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	ft_reverse_rotate(stack);
	ft_safe_write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rra(stack1);
	rrb(stack2);
}
