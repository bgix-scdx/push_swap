/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 15:45:32 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void rr(t_all *all)
{
	rotate(&all->a, 1);
	rotate(&all->b, 1);
	all->list_move[7] += 1;
	printf("rr\n");
}

void rra(t_all *all)
{
	rotate(&all->a, -1);
	all->list_move[8] += 1;
	printf("rra\n");
}
void rrb(t_all *all)
{
	rotate(&all->b, -1);
	all->list_move[9] += 1;
	printf("rrb\n");
}
void rrr(t_all *all)
{
	rotate(&all->a, -1);
	rotate(&all->b, -1);
	all->list_move[10] += 1;
	printf("rrr\n");
}