/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bcondemi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:32:33 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/11 15:03:03 by bcondemi         ###   ########.fr       */
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
// #include <time.h>
// int main ()
// {
// 	t_stack stack1;
// 	t_stack stack2;
// 	/*Test ft_find_idx_min*/
// 	// stack1.tab = malloc(10 * sizeof(int));
// 	// stack1.size = 10;
// 	// stack1.tab[0] = 12;
// 	// stack1.tab[1] = 13;
// 	// stack1.tab[2] = 0;
// 	// stack1.tab[3] = 9;
// 	// stack1.tab[4] = 8;
// 	// stack1.tab[5] = 25;
// 	// stack1.tab[6] = -12;
// 	// stack1.tab[7] = 22;
// 	// stack1.tab[8] = 99;
// 	// stack1.tab[9] = -13;
// 	// ft_printf("stack a == ");
// 	// ft_print_tab(stack1.tab, 10);
// 	// ft_printf("%d", ft_find_idx_min(&stack1));
// 	// /*Test FT_ROTATE*/	
// 	// stack1.tab = malloc(5 * sizeof(int));
// 	// stack1.size = 5;
// 	// stack1.tab[0] = 1;
// 	// stack1.tab[1] = 2;
// 	// stack1.tab[2] = 3;
// 	// stack1.tab[3] = 4;
// 	// stack1.tab[4] = 5;
// 	// ft_printf("stack a == ");
// 	// ft_print_tab(stack1.tab, 5);
// 	// ft_rotate(&stack1, "");
// 	// ft_printf("stack a == ");
// 	// ft_print_tab(stack1.tab, 5);
// 	/*Test FT_SELECT_SORT*/
// 	stack1.tab = malloc(10 * sizeof(int));
// 	stack1.size = 10;
// 	stack2.tab = malloc(10 * sizeof(int));
// 	stack2.size = 10;
// 	srand(time(NULL)); 
// 	for (int i = 0; i < 10; i++) {
// 		stack1.tab[i] = i + 1;
// 	}
// 	for (int i = 9; i > 0; i--) {
// 		int j = rand() % (i + 1);
// 		int tmp = stack1.tab[i];
// 		stack1.tab[i] = stack1.tab[j];
// 		stack1.tab[j] = tmp;
// 	}
// 	ft_printf("stack a == ");
// 	ft_print_tab(stack1.tab, 10);
// 	ft_select_sort(&stack1, &stack2);
// 	ft_printf("stack a == ");
// 	ft_print_tab(stack1.tab, 10);
// 	ft_printf("stack b == ");
// 	ft_print_tab(stack2.tab, 10);
// 	/* Test FT_PUSH*/
// 	// stack1.tab = malloc(sizeof(int) * 4);
// 	// stack2.tab = malloc(sizeof(int) * 4);
// 	// stack1.size = 4;
// 	// stack2.size = 4;
// 	// stack1.tab[0] = 5;
// 	// stack1.tab[1] = 6;
// 	// stack1.tab[2] = 7;
// 	// stack1.tab[3] = 8;
// 	// stack2.tab[0] = 9;
// 	// stack2.tab[1] = 10;
// 	// stack2.tab[2] = 11;
// 	// ft_printf("stack a == ");
// 	// ft_print_tab(stack1.tab, 4);
// 	// ft_printf("stack b == ");
// 	// ft_print_tab(stack2.tab, 4);
// 	// ft_push(&stack2, &stack1, "pa\n");
// 	// ft_printf("stack a == ");
// 	// ft_print_tab(stack1.tab, 4);
// 	// ft_printf("stack b == ");
// 	// ft_print_tab(stack2.tab, 4);
// }
