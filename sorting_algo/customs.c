/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:14:41 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/30 17:51:11 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*use a naive push_b strat, simply push smallest value at the bottom and the 
biggest at the top, then use greedy return */
void	naive_greedy(t_all *all)
{
	t_stack	*a;
	t_stack	*b;

	a = &all->a;
	b = &all->b;
	while (all->a.size > 3)
	{
		pb(all);
		if (n_iem(*b, 0) < (all->s_max / 2))
			rb(all);
	}
	greedy_return(a, b, all);
}

/*O(n^2) not really effective*/
void	insert(t_all *all)
{
	t_stack	*a;
	int		i;

	a = &all->a;
	i = 0;
	while (a->size > 3)
	{
		if (a->array[a->top] > all->s_max - 3)
			ra(all);
		else
		{
			pb(all);
			if (n_iem(all->b, 0) > (a->s_max / 2))
				rb(all);
		}
	}
	opti_3(all, a->array);
	pusha(all, &all->a, &all->b);
}

/*simple chunk sort*/
void	chunk(t_all *all)
{
	push_chunk_a(all);
	opti_3(all, all->a.array);
	pusha(all, &all->a, &all->b);
}

/*even though this is our most optimised sorting algoritme we choosed
not to put it in our default list because the complexity of greedy return
is hard to justify*/
void	ultra_opti_2000(t_all *all)
{
	push_chunk_a(all);
}
