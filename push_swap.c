/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:05:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/20 10:20:34 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

//Cette fonction fait bcp de chose, voir les sous fonction pour plus de detail
//En gros ca init all pour qu'il soit pret a l'emplois
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
	e += list_init(&all->list);
	all->list_move = ft_calloc(11, sizeof(int));
	all->flags = ft_calloc(5, 1);
	flags_count = parser(argc, argv, all);
	e += stack_init(all->s_max, all->s_max, &all->a);
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

char	*fonction_launch(t_all *all)
{
	if (all->screen->disorder == 0)
		return ("Pas d'algoritme    O(0)");
	if (all->s_max == 2)
		return (sa(all), "Simple swap        O(1)");
	if (all->s_max == 3)
		return (opti_3(all, all->a.array), "opti_3             O(1)");
	if (all->s_max == 4)
		return (opti_4(all), "opti_4             O(1)");
	if (all->s_max == 5)
		return (opti_5(all), "opti_5             O(1)");
	if (all->flags[3] == '1')
		return ("adaptive");
	if (all->flags[0] == '1')
		return (insert(all), "simple             O(n²)");
	if (all->flags[1] == '1')
		return (insert(all), "medium        O(n√n)");
	if (all->flags[2] == '1')
		return (radix(all), "complex            O(nlogn)");
	return ("simple             O(n²)");
}

void	free_all(t_all *all)
{
	free(all->a.array);
	free(all->b.array);
	free(all->list_move);
	free(all->flags);
	free(all);
}

//all->moves = count_move(*all);   // compte les coups
int	main(int argc, char **argv)
{
	t_all		*all;

	all = all_init(argc - 1, argv);
	if (!all)
		return (2);
	deb(all, 0);
	all->screen->disorder = disorder(all->a.array, all->s_max);
	if (all->screen->disorder == 0)
		return (write(0, "Error\n", 7), 0);
	radix(all);
	all->screen->mod_difficulty = fonction_launch(all);
	deb(all, 0);
	if (all->flags[4] == '1')
		bench(*all);
	free(all);
	return (0);
}
