/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_de_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:09 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 13:30:19 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

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

/*rotate n'affecte pas l'ordre des elements des stacks
on bouge simplement la tete de liste
La complexiter de rotate ce trouve en fait dans la fonction mod_ifier()
qui permet l'acces a des valeurs de la liste ce trouvant derriere top

exemple ->            | / | 3 | top | 2 |

Ici en partant de top la fonction doit revenir sur la valeur 3 apres avoir passer
le 2 pour cela elle utilisse mod_ifier().
*/
int	rotate(t_stack *s, int val)
{
	s->top = mod_ifier(s->top + val, s->size, s->s_max);
	return (val);
}
