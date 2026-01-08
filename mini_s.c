/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 14:15:00 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  █████  ████████ ████████ ███████ ███    ██ ████████ ██  ██████  ███    ██     ██ ██ 
// ██   ██    ██       ██    ██      ████   ██    ██    ██ ██    ██ ████   ██     ██ ██ 
// ███████    ██       ██    █████   ██ ██  ██    ██    ██ ██    ██ ██ ██  ██     ██ ██ 
// ██   ██    ██       ██    ██      ██  ██ ██    ██    ██ ██    ██ ██  ██ ██           
// ██   ██    ██       ██    ███████ ██   ████    ██    ██  ██████  ██   ████     ██ ██ 
//les printf ici sont reel il faudra les remplacer par des ft_printf

#include "header/push_swap.h"

void sa(t_all *all)
{
	swap(&all->a);
	all->list_move[0] += 1;
	printf("sa\n");
}

void sb(t_all *all)
{
	swap(&all->b);
	all->list_move[1] += 1;
	printf("sb\n");
}

void ss(t_all *all)
{
	swap(&all->a);
	swap(&all->b);
	all->list_move[2] += 1;
	printf("ss\n");
}
