/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 15:43:17 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void pa(t_all *all)
{
	push(&all->b, &all->a);
	all->list_move[3] += 1;
	printf("pa\n");
}
void pb(t_all *all)
{
	push(&all->a, &all->b);
	all->list_move[4] += 1;
	printf("pb\n");
}

void ra(t_all *all)
{
	rotate(&all->a, 1);
	all->list_move[5] += 1;
	printf("ra\n");
}

void rb(t_all *all)
{
	rotate(&all->b, 1);
	all->list_move[6] += 1;
	printf("rb\n");
}
