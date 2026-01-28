/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:58:58 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/28 16:38:20 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

/*performs the most appropriate operation to find the value i in stack B
will likely go haywire if i is not present/in case of duplicates etc...*/
void	search(int val, t_all *all, t_stack s)
{
	int	top;
	int	i;

	i = 1;
	top = n_iem(s, 0);
	while (top != val)
		top = n_iem(s, i++);
	if ((i < (s.size / 2)))
		s.rotate(all);
	else
		s.rrotate(all);
}

void	pusha(t_all *all, t_stack *a, t_stack *b)
{
	int	i;

	i = b->size;
	while (b->size != 0)
	{
		if (b->array[b->top] == i)
		{
			pa(all);
			if (a->array[a->top] > a->array[(a->top + 1) % a->size])
				sa(all);
			i = b->size;
		}
		else if (b->array[b->top] == i - 1)
			pa(all);
		else
			search(i, all, all->b);
	}
}

void	push_chunk_a(t_all *all)
{
	int	there;
	int	low;

	low = 4 * ft_sqrt(all->s_max);
	while (all->a.size > 3)
	{
		there = n_iem(all->a, 0);
		if (there <= low && there < all->s_max - 2)
		{
			low += 1;
			pb(all);
			if (there % 2 == 0)
				rb(all);
		}
		else
			ra(all);
	}
}

/*
	pusha(all, &all->a, &all->b);
*/
void	chunk(t_all *all)
{
	push_chunk_a(all);
	opti_3(all, all->a.array);
	greedy_return(&all->a, &all->b, all);
}
