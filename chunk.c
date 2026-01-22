/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:58:58 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 11:15:53 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	chunk(t_all *all)
{
	int	r;
	int	i;
	int	max;
	int	top;

	r = ft_sqrt(all->s_max);
	i = 0;
	while (i <= r)
	{
		max = all->s_max;
		while (max--)
		{
			top = all->a.array[all->a.top];
			if ((top <= (i + 1) * (r + 1)) && (top >= i * (r + 1)))
				pb(all);
			else
				ra(all);
		}
		i++;
	}
	deb(all, 1);
	pusha(all, &all->a, &all->b);
}
