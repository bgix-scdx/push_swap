/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_de_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 12:59:17 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

void	push(t_stack *src, t_stack *dst)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dst->size;
	while (i > dst->top)
	{
		dst->array[i] = dst->array[i - 1];
		i--;
	}
	i = src->top;
	dst->array[dst->top] = src->array[i];
	while (i < src->size)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	dst->size += 1;
	src->size -= 1;
	if (src->size != 0)
		src->top = src->top % src->size;
}

void	swap(t_stack *s)
{
	t_r	i;

	i = init_reserve();
	i.d = s->top;
	i.e = (s->top + 1) % s->size;
	if (s->array[i.e] == 0)
		return ;
	i.a = s->array[i.d];
	s->array[i.d] = s->array[i.e];
	s->array[i.e] = i.a;
}

int	rotate(t_stack *s, int val)
{
	if (s->size == 0)
		return (1);
	s->top = (s->top + val) % s->size;
	if (s->top < 0)
		s->top += s->size;
	return (val);
}
