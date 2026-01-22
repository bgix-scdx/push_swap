/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 11:04:48 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sa(t_all *all)
{
	swap(&all->a);
	all->list_move[0] += 1;
	all->moves += 1;
	print_move_check(all, "sa");
	return (1);
}

int	sb(t_all *all)
{
	swap(&all->b);
	all->list_move[1] += 1;
	all->moves += 1;
	print_move_check(all, "sb");
	return (1);
}

int	ss(t_all *all)
{
	swap(&all->a);
	swap(&all->b);
	all->list_move[2] += 1;
	all->moves += 1;
	print_move_check(all, "ss");
	return (1);
}
