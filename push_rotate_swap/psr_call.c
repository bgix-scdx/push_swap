/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/22 13:02:06 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

// all->flags[4] est un numbre magique
//faudrais trouver un moyen déclairsire
//si c'est possible du genre all->flags["bench"]
void	print_move_check(t_all *all, const char *move)
{
	if (!move || all->flags[4] == '1')
		return ;
	else
		ft_printf("%s\n", move);
}
