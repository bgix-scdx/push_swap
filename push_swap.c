/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:05:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/13 13:02:14 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
//all->a.Array[""]
//Cette fonction fait bcp de chose, voir les sous fonction pour plus de detail
//En gros ca init all pour qu'il soit pret a l'emplois
t_all	*all_init(int argc, char **argv)
{
	t_all		*all;
	int 		i;
	int 		flags_count;
	int 		e;
	
	all = malloc(sizeof(t_all));
	if (!all)
		return (write(1, "erreur malloc t_all init", 24), (t_all *)0);
	all->moves = 0;
	e += list_init(&all->list);
	all->list_move = ft_calloc(11, sizeof(int));
	all->flags = ft_calloc(5, 1);
	flags_count = parser(argc, argv, all);
	e += stack_init(all->s_max, all->s_max, &all->a);
	e += stack_init(all->s_max, 0, &all->b);
	if (e < 0 || flags_count <= -1)
		return ((t_all *)0);
	i = 0;
	while (i++ < all->s_max + 1)
		all->a.array[i - 1] = ft_atoi(argv[i + flags_count]);
	normaliser(all->a.array, all->a.s_max, all);	
	all->screen = screen_init(all->screen, 100, 20, ' ');
	return (all);
}

bool	check_double(t_stack *a)
{
	int		i;
	int		*list;
	bool	rval;

	rval = true;
	i = 0;
	list = malloc((a->s_max + 1) * sizeof(int));
	if (!list)
		return (false);
	ft_printf("test");
	while (i < a->s_max && rval == true)
	{
		if (list[a->array[i]] != 0)
			break;
		list[a->array[i]] = 1;
		i++;
	}
	if (rval == false)
		ft_printf("Found duplicated number of %d, stopping.\n", a->array[i]);
	else
		ft_printf("No duplications found !\n", a->array[i]);
	free(list);
	return (rval);
}

int	main(int argc, char **argv)
{
	t_all		*all;
	
	all = all_init(argc - 1, argv);
	if (!all)
		return (2);
	if (!check_double(&all->a))
		return (3);
	if (all->flags[4] == '1')
	{
		deb(all, 1);
		radix(all);
		deb(all, 1);
		screen_display(all->screen);
	}
	else
	{
		deb(all, 1);
		insert(all);
		put_moves(*all);
		deb(all, 1);
		printf("desordre = %d \n", disorder(all->a.array, all->s_max));
	}	
	// 	write(1, "\033[?1049l", 8);
	// else
	
	return (0);
}

// sa(&all);
// sb(&all);
// ss(&all);

// pa(&all);
// pb(&all);

// ra(&all);
// rb(&all);
// rr(&all);
// rra(&all);
// rrb(&all);
// rrr(&all);

// put_moves(all);