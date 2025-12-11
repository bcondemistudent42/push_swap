/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:33:09 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/11 14:41:17 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rotate(t_stack *stack)
{
	int	i;
	int	temp;
	int	temp2;

	if (stack->size == 0)
		return ;
	i = 0;
	temp = stack->tab[0];
	while (i < stack->size)
	{
		temp2 = stack->tab[i + 1];
		stack->tab[i + 1] = stack->tab[i];
		stack->tab[i] = temp2;
		i++;
	}
	stack->tab[stack->size - 1] = temp;
	return ;
}

void	ra(t_stack *stack)
{
	ft_rotate(stack);
	ft_safe_write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	ft_rotate(stack);
	ft_safe_write(1, "rb\n", 3);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	ra(stack1);
	rb(stack2);
}
