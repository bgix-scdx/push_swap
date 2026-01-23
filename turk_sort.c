/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:10:03 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/23 10:38:14 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	n_iem(t_stack s, int n)
{
	return (s.array[mod(s.top + n, s.size)]);
}

int	find_target_index(t_stack a, int val, int max)
{
	int	i;
	int	smallest_greater;
	int	there;

	i = 0;
	smallest_greater = 0;
	while (i < a.size)
	{
		there = n_iem(a, i);
		if (there < smallest_greater && there > val)
			smallest_greater = there;
		i++;
	}
	i = 0;
	while (n_iem(a, i) != smallest_greater)
		i++;
	ft_printf("i = %d  gret = %d\n", i, smallest_greater);
	if (i > a.size / 2)
		return (i - a.size);
	return (i);
}

void	searcha(int val, t_all *all)
{
	int		i;
	t_stack	s;

	i = 0;
	s = all->a;
	while (s.array[i] != val)
		i++;
	if (s.top < (s.size / 2))
	{
		if (i < s.top || i > ((s.top + (s.size / 2)) % s.size))
			rra(all);
		else
			ra(all);
	}
	else
	{
		if ((i > s.top) || (i < (s.top - (s.size / 2))))
			ra(all);
		else
			rra(all);
	}
}

//gestion du malloc un peu bizzar
//je veux pas perdre trop de lignes pour l'instant
void	turk_sort(t_all *all)
{
	t_stack	*a;
	t_stack	*b;
	t_cost	c;
	int		i;

	a = &all->a;
	b = &all->b;
	while (a->size > 3)
		pb(all);
	opti_3(all, a->array);
	while (b->size != 0)
	{
		i = 0;
		c.bestcost = 2147483647;
		deb(all, 1);
		while (i < b->size)
		{
			c.cost_b = i;
			if (i > b->size / 2)
				c.cost_b = i - b->size;
			c.cost_a = find_target_index(*a, n_iem(*b, i), all->s_max);
			c.cost = abs(c.cost_a) + abs(c.cost_b);
			if (c.cost_a * c.cost_b > 0)
				c.cost = max(abs(c.cost_a), abs(c.cost_b));
			ft_printf("n = %d costA = %d costB = %d tot = %d\n", \
n_iem(*b, i), c.cost_a, c.cost_b, c.cost);
			if (c.cost < c.bestcost)
			{
				c.bestcost = c.cost;
				c.best_a = c.cost_a;
				c.best_b = c.cost_b;
			}
			i++;
		}
		ft_printf("costi = %d best A = %d best B = %d\n", \
c.bestcost, c.best_a, c.best_b);
		while (c.best_a < 0 && c.best_b < 0)
		{
			c.best_a += rrr(all);
			c.best_b += 1;
		}
		while (c.best_a > 0 && c.best_b > 0)
		{
			c.best_a -= rr(all);
			c.best_b -= 1;
		}
		while (c.best_a < 0)
			c.best_a += rra(all);
		while (c.best_a > 0)
			c.best_a -= ra(all);
		while (c.best_b < 0)
			c.best_b += rrb(all);
		while (c.best_b > 0)
			c.best_b -= rb(all);
		pa(all);
	}
	while (a->array[a->top] != 1)
		searcha(1, all);
}
