
#include "header.h"

int checker(t_stack *a)
{
  char  *line;

  while (1)
  {
    line = get_next_line(0);
    if (!line)
      break ;
    printf("%s", line);
    free(line);
  }
  (void)a;
  return (0);
}

int main(int ac, char **av)
{
  t_stack a;

  if (ac < 2)
    return (EXIT_FAILURE);
	if (ac == 2)
		parse_one(av[1], &a);
	else
		parse_multiple((av + 1), (ac - 1), &a);
  ft_print_tab(a.tab, a.size);
  checker(&a);
}
