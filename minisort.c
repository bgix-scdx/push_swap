/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:01:07 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/28 16:41:44 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	opti_3(t_all *all, int *l)
{
	int	i;
	int	*new;

	if (all->a.size != 3)
		return (write(2, "Error\n", 16), -1);
	i = all->a.top;
	new = malloc(3 * sizeof(int));
	if (!new)
		return (0);
	new[0] = l[i];
	new[1] = l[(i + 1) % 3];
	new[2] = l[(i + 2) % 3];
	new = normaliser(new, 3);
	if (new[0] == 1 && new[1] == 3)
		return (free(new), sa(all), ra(all), 1);
	else if (new[0] == 2 && new[1] == 1)
		return (free(new), sa(all), 1);
	else if (new[0] == 2 && new[1] == 3)
		return (free(new), rra(all), 1);
	else if (new[0] == 3 && new[1] == 2)
		return (free(new), sa(all), rra(all), 1);
	else if (new[0] == 3 && new[1] == 1)
		return (free(new), ra(all), 1);
	return (free(new), 0);
}

void	opti_4(t_all *all)
{
	if (all->s_max != 4)
	{
		write(2, "Error\n", 16);
		return ;
	}
	while (all->a.size > 3)
	{
		if (all->a.array[all->a.top] == 1)
			pb(all);
		else if (all->a.array[(all->a.top + 3) % 4] == 1)
			rra(all);
		else
			ra(all);
	}
	opti_3(all, all->a.array);
	pa(all);
}

void	opti_5(t_all *all)
{
	int	top;
	int	top1;

	if (all->a.size != 5)
	{
		write(2, "Error\n", 16);
		return ;
	}
	while (all->a.size > 3)
	{
		top = n_iem(all->a, 0);
		top1 = n_iem(all->a, 1);
		if (top == 1 || top == 2)
			pb(all);
		else if (top != 1 && top != 2 && top1 != 1 && top1 != 2)
			rra(all);
		else
			ra(all);
	}
	opti_3(all, all->a.array);
	if (all->b.array[all->b.top] == 1)
		sb(all);
	pa(all);
	pa(all);
}
