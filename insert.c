/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:51:38 by bgix              #+#    #+#             */
/*   Updated: 2026/01/09 15:41:35 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"


void insert(t_all *all)
{
	t_stack *a;
	t_stack *b;

	a = &all->a;
	b = &all->b;

	while (b->size != b->s_max)
	{
		if (a->array[a->top] == b->size + 1)
			pb(all);
		ra(all);
	}
	while (b->s_max-- >= 1)
		pa(all);
}