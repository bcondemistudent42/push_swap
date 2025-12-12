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

void	sa(t_stack *a, bool write_switch)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = tmp;
  if (write_switch)
    ft_safe_write(1, "sa\n", 3);
}

void	sb(t_stack *b, bool write_switch)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->tab[0];
	b->tab[0] = b->tab[1];
	b->tab[1] = tmp;
  if (write_switch)
    ft_safe_write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
  ft_safe_write(1, "ss\n", 3);
}

void	ra(t_stack *stack, bool write_switch)
{
  int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = 0;
	temp = stack->tab[0];
	while (i < (stack->size - 1))
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size - 1] = temp;
  if (write_switch)
    ft_safe_write(1, "ra\n", 3);
}

void	rb(t_stack *stack, bool write_switch)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = 0;
	temp = stack->tab[0];
	while (i < (stack->size - 1))
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size - 1] = temp;
  if (write_switch)
    ft_safe_write(1, "rb\n", 3);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	ra(stack1, 0);
	rb(stack2, 0);
  ft_safe_write(1, "rr\n", 3);
}

void	rra(t_stack *stack, bool write_switch)
{
  int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	temp = stack->tab[stack->size - 1];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = temp;
  if (write_switch)
    ft_safe_write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, bool write_switch)
{
  int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	temp = stack->tab[stack->size - 1];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = temp;
  if (write_switch)
    ft_safe_write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rra(stack1, 0);
	rrb(stack2, 0);
  ft_safe_write(1, "rrr\n", 4);
}
