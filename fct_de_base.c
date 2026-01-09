/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_de_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/09 16:08:03 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	int	i;

	i = dst->size;
	while (i > 0)
	{
		dst->array[i] = dst->array[i - 1];
		i--;
	}
	i = src->top;
	dst->array[0] = src->array[i];
	while (i < src->size)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	dst->size += 1;
	src->size -= 1;
}

void	swap(t_stack *s)
{
	int	tmp;
	int	next;
	int	current;

	current = s->array[s->top];
	next = s->array[mod_ifier(s->top + 1, s->size, s->s_max)];
	if (next == 0 || current == 0)
		return ;
	tmp = current;
	s->array[s->top] = next;
	s->array[mod_ifier(s->top + 1, s->size, s->s_max)] = tmp;
}

/*Un genre de modulo mais d'une maniere qui m'arrange plus
permet de revenir sur les premiere valeur non null de ma stack
evite aussi les valeurs negatives*/
int	mod_ifier(int a, int size, int max)
{
	if (a >= max)
		a = max - size;
	else if (a < max - size)  //ne jamais rotate de autre chose que 1 ou -1
		a = max - 1;
	return (a);
}

int	rotate(t_stack *s, int val)
{
	if (s->size == 0)
		return 1;
	s->top = (s->top + 1) % s->size;
	return (val);
}