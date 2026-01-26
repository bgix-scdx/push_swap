/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:59:41 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/26 16:42:37 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	ft_atoi(char *nptr)
{
	int	sign;
	int	number;

	number = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = 10 * number + *nptr - 48;
		nptr++;
	}
	return (sign * number);
}

void	*ft_memmove(void *dest, void *src, int n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	while (n--)
		d[n] = s[n];
	return (dest);
}

void	*ft_calloc(int nmemb, int size)
{
	int		true_size;
	char	*tab;
	int		i_max;

	i_max = 2147483647;
	true_size = size * nmemb;
	if (true_size == 0)
		return (malloc(0));
	if (true_size > i_max || true_size < 0 || nmemb > i_max || size > i_max)
		return (NULL);
	tab = malloc(true_size);
	if (!tab)
		return (NULL);
	while (true_size--)
		tab[true_size] = 0;
	return (tab);
}

//pas de protection sur le calloc
/*
 * Init the stacks.
 *
 * @param  size it is the initial size of the stack 0 for B and arg_c - 1 for A
 * @param  size_max argc - 1 
 * @param  {int} optfilter the index of the 
 * column used to add a filter to the chart
 * @return return the initialisated stack.
 */
t_stack	stack_init(int size_max, int size)
{
	t_stack	new;

	new.top = 0;
	new.size = size;
	new.s_max = size_max;
	new.array = ft_calloc(size_max, sizeof(int));
	return (new);
}

t_r	init_reserve(void)
{
	t_r	new;

	new.a = 0;
	new.b = 0;
	new.c = 0;
	new.d = 0;
	new.e = 0;
	return (new);
}
