/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/13 15:55:32 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	check_rotation(t_all *all, t_stack *a, int m, int i)
{
	if (m < a->top)
	{
		if (i < m || i > a->top)
			ra(all);
		else
			rra(all);
	}
	else
	{
		if (i > m || i < a->top)
			rra(all);
		else
			ra(all);
	}
	//deb(all, 1);
}

void	insert_ext(t_all *all, t_stack *a, t_stack *b, t_r *list)
{
	list->e = a->s_max / 2;
	list->f = a->s_max / 2 + 1;
	while (a->size > 1)
	{
		list->b = 0;
		while (a->array[list->b] != list->e && a->array[list->b] != list->f)
			list->b++;
		printf("%d\n", a->array[list->b]);
		if (a->array[list->b] == list->e)
		{
			list->c = list->e;
			list->e = list->e - 1;
		}
		else
		{
			list->c = list->f;
			list->f = list->f + 1;
		}
		while (a->array[a->top] != list->c)
			check_rotation(all, a, list->c, list->b);
		pb(all);
		if (b->array[b->top] < b->array[(b->top + 1) / b->size])
			rb(all);
		deb(all, 1);
	}
}

void	insert(t_all *all)
{
	t_stack	*a;
	t_stack	*b;
	t_r		list;

	a = &all->a;
	b = &all->b;
	if (a->size < 2)
		return ;
	insert_ext(all, a, b, &list);
	if (a->array[a->top] > a->array[(a->top + 1) % a->size])
		sa(all);
	list.a = b->s_max - 1;
	while (list.a-- > 0)
		pa(all);
	
}
