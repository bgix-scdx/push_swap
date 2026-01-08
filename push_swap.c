/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:05:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 16:10:44 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

// typedef struct s_l
// {
// 	t_stack	a;
// 	t_stack	b;
// 	int		moves;
// 	int		*list_move;
// }	t_all;

//pas de protection apres la creation des array
t_all	all_init(int argc, char **argv)
{
	t_all	new;

	new.moves = 0;
	new.list_move = ft_calloc(11, sizeof(int));
	new.a = stack_init(argc - 1, argc - 1);
	new.b = stack_init(argc - 1, 0);
	while (argc-- > 1)
		new.a.array[argc - 1] = ft_atoi(argv[argc]);
	return (new);
}

int	main(int argc, char **argv)
{
	t_all	all;

	all = all_init(argc, argv);
	
	// rra(&all);
	// rrb(&all);
	deb(all.a, all.b, 0);
	printf("paires desordonee: %d\n", disorder(all.a.array, all.a.s_max));
	
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