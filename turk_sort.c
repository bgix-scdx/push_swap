/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:10:03 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 10:34:12 by vgerthof         ###   ########.fr       */
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
	while (n_iem(a, i) < val && i < a.size)
		i++;
	//printf("i = %d a.s_max = %d\n", i, a.size);
	if (i > a.size / 2)
		return (i - a.size);
	return (i);
}

typedef	struct s_cout
{
	int coutA;
	int coutB;
	
}t_cout;




//gestion du malloc un peu bizzar parce que je veux pas perdre trop de lignes pour l'instant
void	turk_sort(t_all *all)
{
	t_stack	*a;
	t_stack *b;
	int i;
	int coutB;
	int coutA;
	int *couts;
	
	a = &all->a;
	b = &all->b;
	while (a->size > 3)
		pb(all);
	opti_3(all, a->array);
	i = 0;
	couts = malloc((b->s_max - 3) * sizeof(int));
	if (!couts)
		return ;
	while (i < b->size)
	{
		coutB = i;
		if (i > b->size / 2)
			coutB = i - b->size;
		coutA = find_target_index(*a, n_iem(*b, i), all->s_max);
		printf("n = %d coutA = %d coutB = %d \n", n_iem(*b, i), coutA, coutB);
		couts[i] = abs(coutA) + abs(coutB);
		if (coutA * coutB > 0)
			couts[i] = max(abs(coutA), abs(coutB));
		printf("couti = %d\n", couts[i]);
		
		i++;	
	}
	
	deb(all, 1);
	
}