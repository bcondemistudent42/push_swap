/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffilculty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:45:31 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/09 12:42:29 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack 
{
    int	*tab; //[1, 2, 9, 4, 3]
    int size; // 5
}	t_stack;

t_stack a;
t_stack b;

void	ft_swap(t_stack my_stack)
{
	int	temp;

	if (my_stack.size == 0 || my_stack.size == 1)
		return ;
	temp = my_stack.tab[1];
	my_stack.tab[1] = my_stack.tab[0];
	my_stack.tab[0] = temp;
	return ;
}

// void	ft_push(t_stack a, t_stack b)
// {
	
// }

#include <stdio.h>
int main()
{
	t_stack	test;

	test.size = 5;
	test.tab = [0, 1, 2, 3, 4];
	printf("my decimal == %d\nmy ptr == %d\n", test.tab[0], test.size);
}