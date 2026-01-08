/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:06:23 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 16:06:01 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


//  █████  ████████ ████████ ███████ ███    ██ ████████ ██  ██████  ███    ██     ██ ██ 
// ██   ██    ██       ██    ██      ████   ██    ██    ██ ██    ██ ████   ██     ██ ██ 
// ███████    ██       ██    █████   ██ ██  ██    ██    ██ ██    ██ ██ ██  ██     ██ ██ 
// ██   ██    ██       ██    ██      ██  ██ ██    ██    ██ ██    ██ ██  ██ ██           
// ██   ██    ██       ██    ███████ ██   ████    ██    ██  ██████  ██   ████     ██ ██ 
//au include                

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_t
{
	int	*array;
	int	top;
	int	size;
	int	s_max;
}	t_stack;

typedef struct s_l
{
	t_stack	a;
	t_stack	b;
	int		moves;
	int		*list_move;
}	t_all;

typedef struct s_r
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
}	t_r;

t_stack	stack_init(int size_max, int size);

void	*ft_calloc(int nmemb, int size);
void	deb(t_stack A, t_stack B, int n);
void	push(t_stack *src, t_stack *dst);
void	swap(t_stack *s);
void	put_moves(t_all all);
void 	sa(t_all *all);
void 	sb(t_all *all);
void 	ss(t_all *all);
void	pb(t_all *all);
void	pa(t_all *all);
void 	ra(t_all *all);
void 	rb(t_all *all);
void 	rr(t_all *all);
void 	rra(t_all *all);
void 	rrb(t_all *all);
void 	rrr(t_all *all);

int 	mod_ifier(int a, int size, int max);
int		rotate(t_stack *s, int val);
int		disorder(int *a, int max);
int		ft_atoi(char *nptr);

t_r		init_reserve(void);

#endif