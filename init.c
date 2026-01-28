/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 09:42:28 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/27 17:10:57 by vgerthof         ###   ########.fr       */
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
		return (write(2, "malloc failed\n", 15), -1);
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

/*
	fill the array a with the value given in argv
	return -1 if a value doesnt fit in an int
	return -1 if a value is duplicated
	return 1 if everything is fine
*/
int	init_array_a(char **argv, int flagcount, t_all *all)
{
	int				*sa;
	int				i;
	long long int	new;
	int				k;
	
	sa = all->a.array;
	i = 0;
	while (i++ < all->s_max)
	{
		if (ft_strlen(argv[i + flagcount]) > 11)
			return (-1);
		new = ft_atoi(argv[i + flagcount]);
		if (new < (-INTMAX - 1) || new > INTMAX)
			return (-1);
		k = 0;
		while (k < i - 1)
		{
			if (sa[k++] == new || new == 0)
				return (-1);
		}
		sa[i - 1] = new;
	}
	return (1);
}

t_all	*all_init(int argc, char **argv)
{
	t_all		*all;
	int			flags_count;
	int			e;
	
	all = malloc(sizeof(t_all));
	if (!all)
		return (write(2, "erreur malloc t_all init", 24), (t_all *)0);
	all->moves = 0;
	all->list_move = ft_calloc(11, sizeof(int));
	all->flags = ft_calloc(NFLAGS, 1);
	flags_count = parser(argc, argv, all);
	if (flags_count == -1)
		return ((t_all *)0);
	e = stack_init(all->s_max, all->s_max, &all->a);
	e += stack_init(all->s_max, 0, &all->b);
	all->screen = malloc(sizeof(t_screen));
	if (e < 0)
		return (write(2, "init failed\n", 13), (t_all *)0);
	if (init_array_a(argv, flags_count, all) == -1)
		return (write(2, "Error\n", 7), (t_all *)0);
	all->a.array = normaliser(all->a.array, all->a.s_max);
	return (all);
}

