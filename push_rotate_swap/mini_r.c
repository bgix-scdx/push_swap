/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/10 13:57:27 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void rr(t_all *all)
{
	rotate(&all->a, 1);
	rotate(&all->b, 1);
	all->list_move[7] += 1;
	ft_printf("rr\n");
}

void rra(t_all *all)
{
	rotate(&all->a, -1);
	all->list_move[8] += 1;
	ft_printf("rra\n");
}
void rrb(t_all *all)
{
	rotate(&all->b, -1);
	all->list_move[9] += 1;
	ft_printf("rrb\n");
}
void rrr(t_all *all)
{
	rotate(&all->a, -1);
	rotate(&all->b, -1);
	all->list_move[10] += 1;
	ft_printf("rrr\n");
}