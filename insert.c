/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/10 14:07:04 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"


//j'ai fais 2 3 modifs mais on est encore asser loin de l'objectif de performance donc faudra optimiser ca
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
