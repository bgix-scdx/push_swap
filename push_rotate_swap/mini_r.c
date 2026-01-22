/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 11:04:27 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	rr(t_all *all)
{
	rotate(&all->a, 1);
	rotate(&all->b, 1);
	all->list_move[7] += 1;
	all->moves += 1;
	print_move_check(all, "rr");
	return (1);
}

int	rra(t_all *all)
{
	rotate(&all->a, -1);
	all->list_move[8] += 1;
	all->moves += 1;
	print_move_check(all, "rra");
	return (1);

}

int	rrb(t_all *all)
{
	rotate(&all->b, -1);
	all->list_move[9] += 1;
	all->moves += 1;
	print_move_check(all, "rrb");
	return (1);
}

int	rrr(t_all *all)
{
	rotate(&all->a, -1);
	rotate(&all->b, -1);
	all->list_move[10] += 1;
	all->moves += 1;
	print_move_check(all, "rrr");
	return (1);
}
