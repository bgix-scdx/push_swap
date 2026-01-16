/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/13 17:12:41 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void insert(t_all *all)
{
	t_stack *a;
	t_stack *b;
	int		i;

	a = &all->a;
	b = &all->b;
	if (a->size < 2)
		return ;
	while (a->size != 2)
	{
		while (a->array[a->top] != b->size + 1)
			ra(all);
		pb(all);
	}
	if (a->array[a->top] > a->array[(a->top + 1) % a->size])
		sa(all);
	i = b->s_max - 1;
	while (i-- > 1)
		pa(all);
}
