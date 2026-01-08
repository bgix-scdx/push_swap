/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:35:56 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 16:16:26 by vgerthof         ###   ########.fr       */
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
	printf("paires verif: %d\nTaille stack A: %d\n", i.d, max);
	return (i.c);
}
