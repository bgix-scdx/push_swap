/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:10:03 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/26 14:48:58 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	find_target_index(t_stack a, int val, int max)
{
	int	i;
	int	smallest;
	int smallest_greater;
	int	there;

	i = 0;
	smallest_greater = INTMAX;
	smallest = INTMAX;
	while (i < a.size)
	{
		there = n_iem(a, i);
		// ft_printf("smgr = %d val = %d there = %d\n", smallest_greater, val, there);
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
	// ft_printf("i = %d  gret = %d\n", i, smallest_greater);
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

void	find_best(t_cost *c, t_stack *a, t_stack *b, t_all *all)
{
	int		i;

	i = 0;
	c->bestcost = INTMAX;
	while (i < b->size)
	{
		c->cost_b = i;
		if (i > b->size / 2)
			c->cost_b = i - b->size;
		c->cost_a = find_target_index(*a, n_iem(*b, i), all->s_max);
		c->cost = abs(c->cost_a) + abs(c->cost_b);
		if (c->cost_a * c->cost_b > 0)
			c->cost = max(abs(c->cost_a), abs(c->cost_b));
		// ft_printf("n = %d costA = %d costB = %d tot = %d\n", n_iem(*b, i), c->cost_a, c->cost_b, c->cost);
		if (c->cost < c->bestcost)
		{
			c->bestcost = c->cost;
			c->best_a = c->cost_a;
			c->best_b = c->cost_b;
		}
		i++;
	}
}

//gestion du malloc un peu bizzar parce que je veux pas perdre trop de lignes pour l'instant
void	turk_sort(t_all *all)
{
	t_stack	*a;
	t_stack	*b;
	t_cost	c;
	int somme;

	a = &all->a;
	b = &all->b;
	while (all->a.size > 3)
		pb(all);	
	opti_3(all, a->array);
	somme = 0;
	while (b->size != 0)
	{
		find_best(&c, a, b, all);
		somme += c.bestcost;
		// ft_printf("costi = %d best A = %d best B = %d\n", c.bestcost, c.best_a, c.best_b);
		process(&c, all);
		pa(all);
	}
	while (a->array[a->top] != 1)
		search(1, all, all->a);
}
