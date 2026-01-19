/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/19 14:44:59 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sa(t_all *all)
{
	swap(&all->a);
	all->list_move[0] += 1;
	all->moves += 1;
	print_move_check(all, "sa");
}

void	sb(t_all *all)
{
	swap(&all->b);
	all->list_move[1] += 1;
	all->moves += 1;
	print_move_check(all, "sb");
}

void	ss(t_all *all)
{
	swap(&all->a);
	swap(&all->b);
	all->list_move[2] += 1;
	all->moves += 1;
	print_move_check(all, "ss");
}
