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

void	pa(t_stack *a, t_stack *b)
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
	b->size--;
	i = 0;
	while (i < b->size)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	ft_safe_write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[0] = a->tab[0];
	b->size++;
	a->size--;
	i = 0;
	while (i < a->size)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	ft_safe_write(1, "pb\n", 3);
}

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size == 0 || a->size == 1)
		return ;
	tmp = a->tab[a->size - 2];
	a->tab[a->size - 2] = a->tab[a->size - 1];
	a->tab[a->size - 1] = tmp;
	ft_safe_write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size == 0 || b->size == 1)
		return ;
	tmp = b->tab[b->size - 2];
	b->tab[b->size - 2] = b->tab[b->size - 1];
	b->tab[b->size - 1] = tmp;
	ft_safe_write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	ra(t_stack *stack)
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
	ft_safe_write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
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
	ft_safe_write(1, "rb\n", 3);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	ra(stack1);
	rb(stack2);
}

void	rra(t_stack *stack)
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
	ft_safe_write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
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
	ft_safe_write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rra(stack1);
	rrb(stack2);
}
