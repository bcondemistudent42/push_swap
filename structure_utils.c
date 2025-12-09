/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:45:31 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/09 13:34:46 by bcondemi         ###   ########.fr       */
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

void	ft_push(t_stack a, t_stack b)
{
	int	i;
	int new_tab[a.size + 1];

	if (b.size == 0)
		return ;
	i = 1;
	new_tab[0] = b.tab[0];
	while (i <= a.size)
	{
		new_tab[i] = a.tab[i - 1];
		i++;
	}
	a.tab = new_tab;
	a.size++;
	return ;
}

#include <stdio.h>
int main()
{
	t_stack	test1;
	t_stack test2;
	int one[] = {1, 1};
	int two[] = {5} ;
	
	test2.size = 1;
	test1.size = 2;
	test1.tab = one;
	test2.tab = two;
	
	printf("my decimal == %d\n", test1.tab[0]);
	printf("my decimal == %d\n", test1.tab[1]);
	printf("my decimal == %d\n", test1.tab[2]);
	// printf("my decimal == %d\n", test1.tab[4]);
	printf("--------------------------\n");
	ft_push(test1, test2);
	// printf("my decimal == %d\nmy ptr == %d\n", test.tab[2], test.size);
	printf("my decimal == %d\n", test1.tab[0]);
	printf("my decimal == %d\n", test1.tab[1]);
	printf("my decimal == %d\n", test1.tab[2]);
	// printf("my decimal == %d\n", test1.tab[4]);
}
