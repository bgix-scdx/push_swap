/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:05:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/09 13:49:33 by bgix             ###   ########.fr       */
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
t_all	*all_init(int argc, char **argv)
{
	t_all	*new;
	
	new = malloc(sizeof(t_all));
	if (!new)
		return (write(1, "erreur malloc t_all init", 24), NULL);
	new->moves = 0;
	new->list_move = ft_calloc(11, sizeof(int));
	new->a = stack_init(argc, argc);
	new->b = stack_init(argc, 0);
	while (argc-- > 0)
		new->a.array[argc] = ft_atoi(argv[argc + 1]);
	return (new);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = all_init(argc - 1, argv);
	
	insert(all);
	//disorder(all->a.array, all->a.s_max);
	deb(all->a, all->b, 1);
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