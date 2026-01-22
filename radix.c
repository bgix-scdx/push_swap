/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:05:16 by bgix              #+#    #+#             */
/*   Updated: 2026/01/22 13:05:18 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	radix(t_all *all)
{
	int	i;
	int	e;
	int	top;

	e = 1;
	while (e <= all->s_max && disorder(all->a.array, all->s_max) != 0)
	{
		i = 0;
		while (i < all->s_max)
		{
			if ((all->a.array[all->a.top] & e) != e)
			{
				if (i < all->s_max - 1)
					pb(all);
			}
			else
				ra(all);
			i++;
		}
		i = 0;
		while (all->b.size != 0)
			pa(all);
		e *= 2;
	}
}

void	radix_2(t_all *all, int *e, int *botb, int *topb)
{
	int	i;
	int	top;

	i = 0;
	while (i < all->s_max)
	{
		top = (all->a.array[all->a.top] / *e) % 3;
		if (top == 0)
		{
			*botb += 1;
			pb(all);
			rb(all);
		}
		else if (top == 1)
		{
			*topb += 1;
			pb(all);
		}
		else
			ra(all);
		i++;
	}
}

void	radix_3(t_all *all)
{
	int	i;
	int	e;
	int	topb;
	int	botb;

	e = 1;
	while (e / 3 <= all->s_max)
	{
		topb = 0;
		botb = 0;
		radix_2(all, &e, &botb, &topb);
		i = 0;
		while (topb-- != 0)
			pa(all);
		while (all->b.size != 0)
		{
			rrb(all);
			pa(all);
		}
		e *= 3;
	}
}
