/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/22 11:17:23 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

//performs the most appropriate operation to find the value i in stack B
//will likely go haywire if i is not present/in case of duplicates etc...
void	search(int val, t_all *all)
{
	int		i;
	t_stack	s;

	i = 0;
	s = all->b;
	while (s.array[i] != val)
		i++;
	if (s.top < (s.size / 2))
	{
		if (i < s.top || i > ((s.top + (s.size / 2)) % s.size))
			rrb(all);
		else
			rb(all);
	}
	else
	{
		if ((i > s.top) || (i < (s.top - (s.size / 2))))
			rb(all);
		else
			rrb(all);
	}
}

/*repush everithing in the stack a, 
it start by searching the higher value to push it
but if the next is found first it is push and then will be swap in a*/
void	pusha(t_all *all, t_stack *a, t_stack *b)
{
	int		i;

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
			search(i, all);
	}
}

/*push everithing in stack a 
(exept 3 last elements that are sorted with opti_3) 
then repush in the right order */
void	insert(t_all *all)
{
	t_stack	*a;
	int		i;

	a = &all->a;
	i = 0;
	while (a->size > 3)
	{
		if (a->array[a->top] > all->s_max - 3)
			ra(all);
		else
			pb(all);
	}
	opti_3(all, a->array);
	pusha(all, &all->a, &all->b);
}
