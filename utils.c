/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:59:41 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/26 16:33:34 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

//un petit atoi 
int	ft_atoi(char *nptr)
{
	int	sign;
	int	number;

	number = 0;
	sign = 1;
	if (!nptr)
		return (0);
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

/*retourne la n'iem valeur dans la stack s a partir du top
Utilise un modulo fait par mes soins*/
int	n_iem(t_stack s, int n)
{
	return (s.array[mod(s.top + n, s.size)]);
}
