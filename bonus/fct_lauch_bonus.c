/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_lauch_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:22:17 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 13:30:07 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	ok(char *inst, int pos)
{
	if (inst[pos] == '\n' || inst[pos] == '\0')
		return (1);
	return (0);
}

int	swap_launch(char *inst, t_stack *A, t_stack *B)
{
	if (*inst == 'a' && ok(inst, 1))
		return (swap(A), 3);
	if (*inst == 'b' && ok(inst, 1))
		return (swap(B), 3);
	if (*inst == 's' && ok(inst, 1))
		return (swap(A), swap(B), 3);
	return (-1);
}

int	push_launch(char *inst, t_stack *A, t_stack *B)
{
	if (*inst == 'a' && ok(inst, 1))
		return (push(B, A), 3);
	if (*inst == 'b' && ok(inst, 1))
		return (push(A, B), 3);
	return (-1);
}

int	rotate_launch(char *inst, t_stack *A, t_stack *B)
{
	if (*inst == 'a' && ok(inst, 1))
		return (rotate(A, 1), 3);
	if (*inst == 'b' && ok(inst, 1))
		return (rotate(B, 1), 3);
	if (*inst == 'r')
	{
		if (ok(inst, 1))
			return (rotate(B, 1), rotate(A, 1), 3);
		if (inst[1] == 'a' && ok(inst, 2))
			return (rotate(A, -1), 4);
		if (inst[1] == 'b' && ok(inst, 2))
			return (rotate(B, -1), 4);
		if (inst[1] == 'r' && ok(inst, 2))
			return (rotate(B, -1), rotate(A, -1), 4);
	}
	return (-1);
}