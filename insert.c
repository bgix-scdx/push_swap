/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/26 14:44:15 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

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
			pb(all);
	}
	opti_3(all, a->array);
	pusha(all, &all->a, &all->b);
}
