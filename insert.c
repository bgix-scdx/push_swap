/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/13 09:59:17 by bgix             ###   ########.fr       */
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
}

void	insert_ext(t_all *all, t_stack *a, t_stack *b)
{
	int	i;
	int	m;

	while (a->size != 2)
	{
		i = 0;
		while (a->array[i] != b->size + 1)
			i++;
		m = (a->top + (a->size / 2)) % a->size;
		while (a->array[a->top] != b->size + 1)
			check_rotation(all, a, m, i);
		pb(all);
	}
}

void	insert(t_all *all)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = &all->a;
	b = &all->b;
	i = 0;
	if (a->size < 2)
		return ;
	insert_ext(all, a, b);
	if (a->array[a->top] > a->array[(a->top + 1) % a->size])
		sa(all);
	i = b->s_max - 1;
	while (i-- > 1)
		pa(all);
}
