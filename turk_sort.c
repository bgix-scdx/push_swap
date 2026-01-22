/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:10:03 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 12:10:23 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	n_iem(t_stack s, int n)
{
	return (s.array[(s.top + n) % s.size]);
}

int	find_target_index(t_stack a, int val, int max)
{
	int i;

	i = 0;
	
	while (n_iem(a, i) > n_iem(a, i - 1))
		i++;
	while (n_iem(a, i) < val && i < a.size)
		i++;	
	
	if (i > a.size / 2)
		return (i - a.size);
	printf("i = %d a.s_max = %d\n", i, a.size);
	return (i);
}

typedef	struct s_cost
{
	int costA;
	int costB;
	int bestA;
	int bestB;
	int cost;
	int	bestcost;
}t_cost;

void	searcha(int val, t_all *all)
{
	int i;
	t_stack s;
	
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

//gestion du malloc un peu bizzar parce que je veux pas perdre trop de lignes pour l'instant
void	turk_sort(t_all *all)
{
	t_stack	*a;
	t_stack *b;
	t_cost	c;
	int i;
	
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
			c.costB = i;
			if (i > b->size / 2)
				c.costB = i - b->size;
			c.costA = find_target_index(*a, n_iem(*b, i), all->s_max);
			c.cost = abs(c.costA) + abs(c.costB);
			if (c.costA * c.costB > 0)
				c.cost = max(abs(c.costA), abs(c.costB));
			printf("n = %d costA = %d costB = %d tot = %d\n", n_iem(*b, i), c.costA, c.costB, c.cost);	
			if (c.cost < c.bestcost)
			{
				c.bestcost = c.cost;
				c.bestA = c.costA;
				c.bestB = c.costB;
			}
			i++;	
		}
		printf("costi = %d best A = %d best B = %d\n", c.bestcost, c.bestA, c.bestB);
		while (c.bestA < 0 && c.bestB < 0)
		{
			c.bestA += rrr(all);
			c.bestB += 1;
		}
		while (c.bestA > 0 && c.bestB > 0)
		{
			c.bestA -= rr(all);
			c.bestB -= 1;
		}
		while (c.bestA < 0)
			c.bestA += rra(all);
		while (c.bestA > 0)
			c.bestA -= ra(all);
		while (c.bestB < 0)
			c.bestB += rrb(all);
		while (c.bestB > 0)
			c.bestB -= rb(all);
		pa(all);
	}
	while (a->array[a->top] != 1)
		searcha(1, all);
}
               