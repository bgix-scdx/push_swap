/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/19 14:45:39 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rr(t_all *all)
{
	rotate(&all->a, 1);
	rotate(&all->b, 1);
	all->list_move[7] += 1;
	all->moves += 1;
	print_move_check(all, "rr");
}

void	rra(t_all *all)
{
	rotate(&all->a, -1);
	all->list_move[8] += 1;
	all->moves += 1;
	print_move_check(all, "rra");
}

void	rrb(t_all *all)
{
	rotate(&all->b, -1);
	all->list_move[9] += 1;
	all->moves += 1;
	print_move_check(all, "rrb");
}

void	rrr(t_all *all)
{
	rotate(&all->a, -1);
	rotate(&all->b, -1);
	all->list_move[10] += 1;
	all->moves += 1;
	print_move_check(all, "rrr");
}
