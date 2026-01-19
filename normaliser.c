/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normaliser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:20:17 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/19 14:56:01 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

/*
 * normalise the stack before puting it in the all->a.array.
 *
 * @param  list The list we want to normalise
 * @param  size size of the list 
 * @param  all all
 * @return 1.
 */
int	*normaliser(int *list, int size)
{
	t_norm	a;
	int		*new;

	new = malloc(size * sizeof(int));
	if (!new)
		return (write(1, "erreur malloc\n", 15), NULL);
	a.n = 0;
	a.prev_min = -2147483648;
	while (a.n < size)
	{
		a.i = -1;
		a.min = 2147483647;
		while (++a.i < size)
		{
			if (list[a.i] < a.min && list[a.i] > a.prev_min)
			{
				a.min = list[a.i];
				a.min_index = a.i;
			}
		}
		a.prev_min = list[a.min_index];
		new[a.min_index] = ++a.n;
	}
	return (free(list), new);
}

//permet d'ajouter un carctere a un t_l sans risque 
//de depasser la taille du buffer
int	l_add(t_l *l, char c)
{
	char	*new;
	int		i;

	if (!l->buffer)
		return (-1);
	if (l->len + 1 > l->size)
	{
		l->size *= 10;
		new = malloc(l->size);
		if (!new)
			return (write(1, "realloc error", 14), -1);
		i = -1;
		while (++i < l->len)
			new[i] = l->buffer[i];
		free(l->buffer);
		l->buffer = new;
	}
	l->buffer[l->len] = c;
	return (l->size);
}

//initialise le t_l
//Dedans je stock la taille dispo (size) et la taille effective (len)
//Et bien sur le buffer lui meme
int	list_init(t_l *l)
{
	l->len = 0;
	l->size = 100;
	l->buffer = malloc(l->size);
	if (!l->buffer)
		return (write(1, "malloc list init failed\n", 25), -1);
	return (0);
}
