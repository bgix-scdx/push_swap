/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_de_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/09 13:51:45 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	if (src->array[src->top] == 0)
		return ;
	dst->size++;
	src->size--;
	rotate(dst, -1);
	dst->array[dst->top] = src->array[src->top];
	src->array[src->top] = 0;
	src->top += 1;
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
	s->top = mod_ifier(s->top + val, s->size, s->s_max);

	return (val);
}