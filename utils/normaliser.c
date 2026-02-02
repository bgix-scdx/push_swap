/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normaliser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:20:17 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/31 14:10:28 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	int		count;
	int		i;

	new = malloc((size + 1) * sizeof(int));
	if (!new)
		return (NULL);
	a.n = -1;
	while (++a.n < size)
	{
		i = -1;
		count = 0;
		while (++i < size)
		{
			if (list[i] <= list[a.n])
				count++;
		}
		new[a.n] = count;
	}
	return (free(list), new);
}
