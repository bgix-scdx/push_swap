/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/28 14:40:12 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	rr(t_all *all)
{
	rotate(&all->a, 1);
	rotate(&all->b, 1);
	all->list_move[7] += 1;
	all->moves += 1;
	print_move_check(all, "rr\n\0");
	return (1);
}

int	rra(t_all *all)
{
	rotate(&all->a, -1);
	all->list_move[8] += 1;
	all->moves += 1;
	print_move_check(all, "rra\n");
	return (1);
}

int	rrb(t_all *all)
{
	rotate(&all->b, -1);
	all->list_move[9] += 1;
	all->moves += 1;
	print_move_check(all, "rrb\n");
	return (1);
}

int	rrr(t_all *all)
{
	rotate(&all->a, -1);
	rotate(&all->b, -1);
	all->list_move[10] += 1;
	all->moves += 1;
	print_move_check(all, "rrr\n");
	return (1);
}
