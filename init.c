/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 09:42:28 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/24 09:42:59 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

/*
 * Init the stacks.
 *
 * @param  size it is the initial size of the stack 0 for B and arg_c - 1 for A
 * @param  size_max argc - 1 
 * @param  {int} optfilter the index of
the column used to add a filter to the chart
 * @return return the initialisated stack.
 */
int	stack_init(int size_max, int size, t_stack *new)
{
	new->top = 0;
	new->size = size;
	new->s_max = size_max;
	if (size == 0)
	{
		new->push = &pb;
		new->rotate = &rb;
		new->rrotate = &rrb;
	}
	else 
	{
		new->push = &pa;
		new->rotate = &ra;
		new->rrotate = &rra;
	}
	new->array = ft_calloc(size_max + 1, sizeof(int));
	if (!new->array)
		return (write(1, "malloc failed\n", 15), -1);
	return (0);
}

t_r	init_reserve(void)
{
	t_r	new;

	new.a = 0;
	new.b = 0;
	new.c = 0;
	new.d = 0;
	new.e = 0;
	return (new);
}

t_all	*all_init(int argc, char **argv)
{
	t_all		*all;
	int			i;
	int			flags_count;
	int			e;

	all = malloc(sizeof(t_all));
	if (!all)
		return (write(1, "erreur malloc t_all init", 24), (t_all *)0);
	all->moves = 0;
	all->list_move = ft_calloc(11, sizeof(int));
	all->flags = ft_calloc(NFLAGS, 1);
	flags_count = parser(argc, argv, all);
	e = stack_init(all->s_max, all->s_max, &all->a);
	e += stack_init(all->s_max, 0, &all->b);
	all->screen = malloc(sizeof(t_screen));
	if (e < 0 || flags_count == -1)
		return (write(1, "init failed\n", 13), (t_all *)0);
	i = 0;
	while (i++ < all->s_max + 1)
		all->a.array[i - 1] = ft_atoi(argv[i + flags_count]);
	all->a.array = normaliser(all->a.array, all->a.s_max);
	return (all);
}