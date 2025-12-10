/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:45:31 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/10 13:22:34 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(t_stack *stack, char *str)
{
	int	temp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	temp = stack->tab[stack->size - 2];
	stack->tab[stack->size - 2] = stack->tab[stack->size - 1];
	stack->tab[stack->size - 1] = temp;
	ft_putstr_fd(str, 1);
	return ;
}

void	ft_ss(t_stack *stack_0, t_stack *stack_1)
{
	ft_swap(stack_1, "sb\n");
	ft_swap(stack_0, "sa\n");
	return ;
}

void	ft_push(t_stack *a, t_stack *b, char *str)
{
	if (b->size == 0)
		return ;
	a->tab[a->size - 1] = b->tab[b->size - 1];
	ft_putstr_fd(str, 1);
	a->size++;
	b->size--;
}

void	ft_rotate(t_stack *stack, char *str)
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
	ft_putstr_fd(str, 1);
	return ;
}

void	ft_rr(t_stack *stack1, t_stack *stack2)
{
	ft_rotate(stack1, "ra\n");
	ft_rotate(stack2, "rb\n");
	return ;
}
