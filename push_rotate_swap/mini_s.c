/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/12 18:21:05 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void sa(t_all *all)
{
	swap(&all->a);
	all->list_move[0] += 1;
	ft_printf("sa\n");
}

void sb(t_all *all)
{
	swap(&all->b);
	all->list_move[1] += 1;
	ft_printf("sb\n");
}

void ss(t_all *all)
{
	swap(&all->a);
	swap(&all->b);
	all->list_move[2] += 1;
	ft_printf("ss\n");
}
