/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:10:03 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/28 16:37:10 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	find_target_index(t_stack a, int val)
{
	int	i;
	int	smallest;
	int	smallest_greater;
	int	there;

	i = 0;
	smallest_greater = INTMAX;
	smallest = INTMAX;
	while (i < a.size)
	{
		there = n_iem(a, i);
		if (there < smallest_greater && there > val)
			smallest_greater = there;
		if (there < smallest)
			smallest = there;
		i++;
	}
	if (smallest_greater == INTMAX)
		smallest_greater = smallest;
	i = 0;
	while (n_iem(a, i) != smallest_greater)
		i++;
	if (i > a.size / 2)
		return (i - a.size);
	return (i);
}

void	process(t_cost *c, t_all *all)
{
	while (c->best_a < 0 && c->best_b < 0)
	{
		c->best_a += rrr(all);
		c->best_b += 1;
	}
	while (c->best_a > 0 && c->best_b > 0)
	{
		c->best_a -= rr(all);
		c->best_b -= 1;
	}
	while (c->best_a < 0)
		c->best_a += rra(all);
	while (c->best_a > 0)
		c->best_a -= ra(all);
	while (c->best_b < 0)
		c->best_b += rrb(all);
	while (c->best_b > 0)
		c->best_b -= rb(all);
}

void	find_best(t_cost *c, t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	c->bestcost = INTMAX;
	while (i < b->size)
	{
		c->cost_b = i;
		if (i > b->size / 2)
			c->cost_b = i - b->size;
		c->cost_a = find_target_index(*a, n_iem(*b, i));
		c->cost = abs(c->cost_a) + abs(c->cost_b);
		if (c->cost_a * c->cost_b > 0)
			c->cost = max(abs(c->cost_a), abs(c->cost_b));
		if (c->cost < c->bestcost)
		{
			c->bestcost = c->cost;
			c->best_a = c->cost_a;
			c->best_b = c->cost_b;
		}
		i++;
	}
}

void	greedy_return(t_stack	*a, t_stack	*b, t_all *all)
{
	int		sum;
	t_cost	c;

	sum = 0;
	while (b->size != 0)
	{
		find_best(&c, a, b);
		sum += c.bestcost;
		process(&c, all);
		pa(all);
	}
	while (a->array[a->top] != 1)
		search(1, all, all->a);
}

void	turk_sort(t_all *all)
{
	t_stack	*a;
	t_stack	*b;

	a = &all->a;
	b = &all->b;
	while (all->a.size > 3)
	{
		pb(all);
		if (n_iem(*b, 0) < (all->s_max / 2))
			rb(all);
	}
	opti_3(all, a->array);
	greedy_return(a, b, all);
}
