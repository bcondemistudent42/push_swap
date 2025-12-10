/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:29:01 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/10 21:11:31 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rotate(t_stack *stack, char *str)
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
	ft_putstr_fd(str, 1);
	return ;
}

void	ft_rrr(t_stack *stack1, t_stack *stack2)
{
	ft_reverse_rotate(stack1, "rra\n");
	ft_reverse_rotate(stack2, "rrb\n");
	return ;
}
