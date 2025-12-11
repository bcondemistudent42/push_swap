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

<<<<<<< HEAD:structure_utils.c
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
	a->tab[0] = b->tab[b->size - 1];
	a->size++;
	b->size--;
	ft_putstr_fd(str, 1);
}

void	ft_reverse_rotate(t_stack *stack, char *str)
=======
void	ft_reverse_rotate(t_stack *stack)
>>>>>>> main:ft_reverse_rotate.c
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
