/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normaliser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:20:17 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/27 15:59:08 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

/*
 * normalise the stack before puting it in the all->a.array.
 *
 * @param  list The list we want to normalise
 * @param  size size of the list 
 * @param  all all
 * @return 1.
 */
int	*normaliser(int *list, int size)
{
	t_norm	a;
	int		*new;

	new = malloc((size + 1) * sizeof(int));
	if (!new)
		return (NULL);
	a.n = 0;
	a.prev_min = -2147483648;
	while (a.n < size)
	{
		a.i = -1;
		a.min = 2147483647;
		while (++a.i < size)
		{
			if (list[a.i] < a.min && list[a.i] > a.prev_min)
			{
				a.min = list[a.i];
				a.min_index = a.i;
			}
		}
		a.prev_min = list[a.min_index];
		new[a.min_index] = ++a.n;
	}
	return (free(list), new);
}
