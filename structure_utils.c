/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:45:31 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/09 22:16:47 by bcondemi         ###   ########.fr       */
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

// int	main(int ac, char **av)
// {
// 	t_stack	a;
// 	t_stack b;

// 	parser(av[1], &a);
// 	printf("size: %d\n", a.size);
// 	b.tab = malloc(a.size * sizeof(int));
// 	b.size = a.size;
// 	//test
// 	print_tab(a.tab, a.size);
// }

// #include <stdio.h>
// int main()
// {
// 	t_stack	test1;
// 	t_stack test2;
// 	int *one = malloc(sizeof(int) * 4);
// 	one[0] = 11;
// 	one[1] = 12;
// 	one[2] = 13;
// 	one[3] = 18;
// 	one[4] = 19;
// 	int *two = malloc(sizeof(int) * 3);
// 	two[0] = 55;
// 	two[1] = 56;
// 	two[2] = 57;
// 	test2.size = 3;
// 	test1.size = 5;
// 	test1.tab = one;
// 	test2.tab = two;
// 	printf("my decimal == %d\n", test1.tab[4]);
// 	printf("my decimal == %d\n", test1.tab[3]);
// 	printf("my decimal == %d\n", test1.tab[2]);
// 	printf("my decimal == %d\n", test1.tab[1]);
// 	printf("my decimal == %d\n", test1.tab[0]);
// 	printf("2 my decimal == %d\n", test2.tab[2]);
// 	printf("2 my decimal == %d\n", test2.tab[1]);
// 	printf("2 my decimal == %d\n", test2.tab[0]);
// 	printf("--------------------------\n");
// 	ft_rr(&test1, &test2);
// 	printf("my decimal == %d\n", test1.tab[4]);
// 	printf("my decimal == %d\n", test1.tab[3]);
// 	printf("my decimal == %d\n", test1.tab[2]);
// 	printf("my decimal == %d\n", test1.tab[1]);
// 	printf("my decimal == %d\n", test1.tab[0]);
// 	printf("2 my decimal == %d\n", test2.tab[2]);
// 	printf("2 my decimal == %d\n", test2.tab[1]);
// 	printf("2 my decimal == %d\n", test2.tab[0]);
// 	free(test1.tab);
// 	free(test2.tab);
// }
