/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:30:18 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/11 14:42:11 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_swap(t_stack *stack)
{
	int	temp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	temp = stack->tab[stack->size - 2];
	stack->tab[stack->size - 2] = stack->tab[stack->size - 1];
	stack->tab[stack->size - 1] = temp;
	return ;
}

void	sa(t_stack *stack)
{
	ft_swap(stack);
	ft_safe_write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	ft_swap(stack);
	ft_safe_write(1, "sb\n", 3);
}

void	ss(t_stack *stack_0, t_stack *stack_1)
{
	sa(stack_0);
	sb(stack_1);
}
