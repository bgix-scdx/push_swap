/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:05:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/26 14:48:23 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

char	*adapt(char *flags, int disorder, t_all *all)
{
	int	sum;

	sum = flags[0] + flags[1] + flags[2];
	if (flags[3] == '1' || sum > '1' || sum == 0)
	{
		if (disorder < 20)
			return (turk_sort(all), "turk_sort           O(n²)");
		else if (disorder < 50)
			return (chunk(all), "chunk_sort         O(n√n)");
		else
			return (radix(all), "radix_sort         O(nlogn)");
	}
	if (flags[0] == '1')
		return (turk_sort(all), "turk_sort           O(n²)");
	if (flags[1] == '1')
		return (chunk(all), "chunk_sort          O(n√n)");
	if (flags[2] == '1')
		return (radix(all), "radix_sort         O(nlogn)");
	return ("Undefined    ");
}

char	*fonction_launch(t_all *all)
{
	if (all->screen->disorder == 0)
		return ("Pas d'algoritme    0");
	if (all->s_max == 2)
		return (sa(all), "Simple swap        O(1)");
	if (all->s_max == 3)
		return (opti_3(all, all->a.array), "opti_3             O(1)");
	if (all->s_max == 4)
		return (opti_4(all), "opti_4             O(1)");
	if (all->s_max == 5)
		return (opti_5(all), "opti_5             O(1)");
	return (adapt(all->flags, all->screen->disorder, all));
}

void	free_all(t_all *all)
{
	free(all->a.array);
	free(all->b.array);
	free(all->list_move);
	free(all->flags);
	free(all->screen);
	free(all);
}

int	main(int argc, char **argv)
{
	t_all		*all;

	all = all_init(argc - 1, argv);
	if (all->s_max == 0 || !all->a.array)
		return (write(0, "Error\n", 6), free_all(all), 0);
	if (!all)
		return (2);
	all->screen->disorder = disorder(all->a.array, all->s_max);
	if (all->screen->disorder == -1)
		return (free_all(all), 1);
	all->screen->mod_difficulty = fonction_launch(all);
	if (all->flags[4] == '1')
		return (bench(*all), free_all(all), 0);
	return (free_all(all), 0);
}
