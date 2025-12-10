/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:20:53 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/10 21:58:06 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_select_sort(t_stack *stack_a, t_stack *stack_b)
{	
	int	i;
	int j;
	int	idx_min;

	j = 0;
	i = 0;
	idx_min = ft_find_idx_min(stack_a);
	while (i < stack_a->size)
	{
		idx_min = ft_find_idx_min(stack_a);
		if (idx_min < (stack_a->size / 2))
		{
			while (stack_a->tab[stack_a->size - 1] != stack_a->tab[idx_min])
			{
				ft_rotate(stack_a, "rotate\n");
				idx_min = ft_find_idx_min(stack_a);
				ft_print_tab(stack_a->tab, 10);
			}
			ft_push(stack_b, stack_a, "pa\n");
		}
		// else 
		// {
		// 	while (stack_a->tab[stack_a->size - 1] != stack_a->tab[idx_min])
		// 	{
		// 		ft_reverse_rotate(stack_a, "reverse rotate\n");
		// 		idx_min = ft_find_idx_min(stack_a);
		// 		ft_print_tab(stack_a->tab, 10);
		// 	}
		// 	ft_push(stack_b, stack_a, "pa\n");
		// }
		i++;
	}
}

int	ft_find_idx_min(t_stack *stack)
{
	int	i;
	int	min;
	int	idx_min;

	i = 0;
	min = stack->tab[0];
	idx_min = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] < min)
		{
			min = stack->tab[i];
			idx_min = i;
		}
		i++;
	}
	return (idx_min);
}

#include <time.h>
int main ()
{
	t_stack stack1;
	t_stack stack2;
	
	/*Test ft_find_idx_min*/
	// stack1.tab = malloc(10 * sizeof(int));
	// stack1.size = 10;
	// stack1.tab[0] = 12;
	// stack1.tab[1] = 13;
	// stack1.tab[2] = 0;
	// stack1.tab[3] = 9;
	// stack1.tab[4] = 8;
	// stack1.tab[5] = 25;
	// stack1.tab[6] = -12;
	// stack1.tab[7] = 22;
	// stack1.tab[8] = 99;
	// stack1.tab[9] = -13;
	// ft_printf("stack a == ");
	// ft_print_tab(stack1.tab, 10);
	// ft_printf("%d", ft_find_idx_min(&stack1));
	
	// /*Test FT_ROTATE*/	
	// stack1.tab = malloc(5 * sizeof(int));
	// stack1.size = 5;
	// stack1.tab[0] = 1;
	// stack1.tab[1] = 2;
	// stack1.tab[2] = 3;
	// stack1.tab[3] = 4;
	// stack1.tab[4] = 5;

	// ft_printf("stack a == ");
	// ft_print_tab(stack1.tab, 5);
	// ft_rotate(&stack1, "");
	// ft_printf("stack a == ");
	// ft_print_tab(stack1.tab, 5);

	/*Test FT_SELECT_SORT*/
	stack1.tab = malloc(10 * sizeof(int));
	stack1.size = 10;
	stack2.tab = malloc(10 * sizeof(int));
	stack2.size = 10;
	srand(time(NULL)); 
	for (int i = 0; i < 10; i++) {
		stack1.tab[i] = i + 1;
	}
	for (int i = 9; i > 0; i--) {
		int j = rand() % (i + 1);
		int tmp = stack1.tab[i];
		stack1.tab[i] = stack1.tab[j];
		stack1.tab[j] = tmp;
	}
	ft_printf("stack a == ");
	ft_print_tab(stack1.tab, 10);
	ft_select_sort(&stack1, &stack2);
	ft_printf("stack a == ");
	ft_print_tab(stack1.tab, 10);
	ft_printf("stack b == ");
	ft_print_tab(stack2.tab, 10);

	/* Test FT_PUSH*/
	// stack1.tab = malloc(sizeof(int) * 4);
	// stack2.tab = malloc(sizeof(int) * 4);
	// stack1.size = 4;
	// stack2.size = 4;
	// stack1.tab[0] = 5;
	// stack1.tab[1] = 6;
	// stack1.tab[2] = 7;
	// stack1.tab[3] = 8;
	
	// stack2.tab[0] = 9;
	// stack2.tab[1] = 10;
	// stack2.tab[2] = 11;
	// ft_printf("stack a == ");
	// ft_print_tab(stack1.tab, 4);
	// ft_printf("stack b == ");
	// ft_print_tab(stack2.tab, 4);
	// ft_push(&stack2, &stack1, "pa\n");
	// ft_printf("stack a == ");
	// ft_print_tab(stack1.tab, 4);
	// ft_printf("stack b == ");
	// ft_print_tab(stack2.tab, 4);
}
