/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/19 14:46:11 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pa(t_all *all)
{
	push(&all->b, &all->a);
	all->list_move[3] += 1;
	all->moves += 1;
	print_move_check(all, "pa");
}

void	pb(t_all *all)
{
	push(&all->a, &all->b);
	all->list_move[4] += 1;
	all->moves += 1;
	print_move_check(all, "pb");
}

void	ra(t_all *all)
{
	rotate(&all->a, 1);
	all->list_move[5] += 1;
	all->moves += 1;
	print_move_check(all, "ra");
}

void	rb(t_all *all)
{
	rotate(&all->b, 1);
	all->list_move[6] += 1;
	all->moves += 1;
	print_move_check(all, "rb");
}
