#include "header.h"

int	main(int ac, char **av)
{
	int	i;
  t_stack a;

	i = 1;
	if (ac < 1)
		return (ft_putstr_fd("Error\n", 2));
	a = parsing(&ac, av, &i);
  push_swap(&a, ac, i);
  //ft_print_tab(a.tab, a.size);
}
