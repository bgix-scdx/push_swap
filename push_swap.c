/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:05:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/10 14:32:40 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

//Cette fonction fait bcp de chose, voir les sous fonction pour plus de detail
//En gros ca init all pour qu'il soit pret a l'emplois
t_all	*all_init(int argc, char **argv)
{
	t_all	*all;
	int i;
	int flags_count;
	int e;

	all = malloc(sizeof(t_all));
	if (!all)
		return (write(1, "erreur malloc t_all init", 24), NULL);
	all->moves = 0;
	e += list_init(&all->list);
	all->list_move = ft_calloc(11, sizeof(int));
	all->flags = ft_calloc(5, 1);
	flags_count = parser(argc, argv, all);
	e += stack_init(all->s_max, all->s_max, &all->a);
	e += stack_init(all->s_max, 0, &all->b);
	if (e < 0 || flags_count == -1)
		return (write(1, "init failed\n", 13), (t_all *)0);
	i = 0;
	while (i++ < all->s_max + 1)
		all->a.array[i - 1] = ft_atoi(argv[i + flags_count]);
	normaliser(all->a.array, all->a.s_max, all);	
	return (all);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = all_init(argc - 1, argv);
	
	deb(all->a, all->b, 1);
	insert(all);
	ft_printf("aa%d", 1); // Le ft_printf ne marche pas jsp pourquoi
	deb(all->a, all->b, 1);

	//disorder(all->a.array, all->a.s_max);
	//disorder_sample(all->a.array, all->a.s_max);
	
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