/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:47:25 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/19 14:52:22 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	disorder(int *a, int max)
{
	t_r	i;

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

void	disorder_sample(int *a, int max)
{
	int	i;
	int	new_buffer[100];

	i = 0;
	if (max > 10)
	{
		while (i < 100)
		{
			new_buffer[i] = a[(max * i) / 100];
			i++;
		}
		disorder(new_buffer, 100);
	}
	else
		disorder(a, max);
}
