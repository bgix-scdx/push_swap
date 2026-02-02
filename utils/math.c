/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:17:36 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/30 16:36:27 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int	mod(int p, int q)
{
	p = p % q;
	if (p < 0)
		p += q;
	return (p);
}

int	genrand(int max, int seed)
{
	static int	r;
	int			ret;

	if (seed)
		r = seed;
	r = (r * 9301 + 49297) % 233280;
	ret = r % max;
	if (ret < 0)
		ret += max;
	return (ret);
}
