/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bcondemi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:32:33 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/10 13:59:30 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
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
// 	ft_rrr(&test1, &test2);
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

// #include <time.h>
// int main ()
// {
// 	t_stack stack;
// 	stack.tab = malloc(1000 * sizeof(int));
// 	stack.size = 1000;
// 	for (int i = 0; i < 1000; i++) {
//    		stack.tab[i] = rand() % 10000;
// }	
// 	ft_print_tab(stack.tab, 1000);
// 	ft_printf("%d", ft_compute_disorder(&stack));
// }