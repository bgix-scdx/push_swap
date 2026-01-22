/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 11:03:50 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	pa(t_all *all)
{
	push(&all->b, &all->a);
	all->list_move[3] += 1;
	all->moves += 1;
	print_move_check(all, "pa");
	return (1);
}

int	pb(t_all *all)
{
	push(&all->a, &all->b);
	all->list_move[4] += 1;
	all->moves += 1;
	print_move_check(all, "pb");
	return (1);
}

int	ra(t_all *all)
{
	rotate(&all->a, 1);
	all->list_move[5] += 1;
	all->moves += 1;
	print_move_check(all, "ra");
	return (1);
}

int	rb(t_all *all)
{
	rotate(&all->b, 1);
	all->list_move[6] += 1;
	all->moves += 1;
	print_move_check(all, "rb");
	return (1);
}
