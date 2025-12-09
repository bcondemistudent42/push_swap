/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:11 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/09 15:28:53 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float	compute_disorder(t_stack stack)
{
	int	mistake;
	int	pairs;
	int	i;
	int	j;

	i = 0;
	j = 0;
	pairs = 0;
	mistake = 0;
	while (i < stack.size)
	{
		j = i + 1;
		while (j < stack.size)
		{
			pairs++;
			if (stack.tab[i] > stack.tab[j] && i != j)
				mistake++;
			j++;
		}
		i++;
	}
	return ((float)mistake / (float)pairs);
}
