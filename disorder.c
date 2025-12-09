/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramaroud <ramaroud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:56:11 by ramaroud          #+#    #+#             */
/*   Updated: 2025/12/09 12:56:13 by ramaroud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	compute_disorder(t_stack stack)
{
	int	mistake;
	int	pairs;

	pairs = 0;
	mistake = 0;
	while (i < (stack.size - 1))
	{
		while (j < (stack.size - 1))
		{
			pairs++;
			if (stack.tab[i] > stack.tab[j])
				mistake++;
			j++;
		}
		i++;
	}
	return (mistake / pairs);
}
