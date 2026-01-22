/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:47:25 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 14:59:05 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	disorder(int *a, int max)
{
	t_r	i;

	if (!a || max == 0)
		return (0);
	i = init_reserve();
	while (i.a < max)
	{
		i.b = i.a + 1;
		while (i.b < max)
		{
			if (a[i.a] > a[i.b])
				i.c++;
			i.b++;
			i.d++;
		}
		i.a++;
	}
	if (i.d != 0)
		i.e = (100 * i.c) / i.d;
	else
		i.e = 0;
	return (i.e);
}

int	check_dup(int *a, int max)
{
	int	i;
	int	i_plus;

	i = 1;
	i_plus = 1;
	while (i < max)
	{
		while (i_plus < max)
		{
			if (i != i_plus && a[i_plus] == a[i])
				return (0);
			i_plus++;
		}
		i++;
	}
	return (1);
}

void	disorder_sample(int *a, int max)
{
	int	i;
	int	new_buffer[100];

	i = -1;
	if (max > 10)
	{
		while (++i < 100)
			new_buffer[i] = a[(max * i) / 100];
		disorder(new_buffer, 100);
	}
	else
		disorder(a, max);
}
