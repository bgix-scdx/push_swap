/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:09:12 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/30 16:42:06 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*optimal push_b function, calculate the cost to push each value
then perform the cheaper one. Return the sum of all the cost
the return value is useless unless you want to test the performances of
the greedy return alone (youd have to take the sum+opti_3+n-3)
The performance of this strategie has been modelised and is approximatively
0.3 * n^(1.5)   wich is O(n^1.5) */
int	greedy_return(t_stack	*a, t_stack	*b, t_all *all)
{
	int		sum;
	t_cost	c;

	sum = 0;
	opti_3(all, a->array);
	while (b->size != 0)
	{
		find_best(&c, a, b);
		sum += c.bestcost;
		process(&c, all);
		pa(all);
	}
	while (a->array[a->top] != 1)
		search(1, all, all->a);
	return (sum);
}

/*Search for the 2 biggest value in the stack b and push it,
when they land in the wrong order in a, they are swapped.*/
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

/*search for value in a certain interval, each time a value is pushed
the search interval enlarge, the 3 biggest value are left in the stack a*/
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
