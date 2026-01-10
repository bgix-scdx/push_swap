/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:06:23 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/10 13:35:59 by vgerthof         ###   ########.fr       */
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

//info relatives a une stack particuliere
typedef struct s_t
{
	int	*array;
	int	top;
	int	size;
	int	s_max;
}	t_stack;

//sert a sauvegarder la liste de coup avant de l'envoyer a l'optimiseur
typedef struct s_l
{
	char	*buffer;
	int		len;
	int		size;
}	t_l;

//info utile a tout le programes, notament les differente stack
typedef struct s_s
{
	t_stack	a;
	t_stack	b;
	int		moves;
	int		*list_move;
	char	*flags;
	int		s_max;
	t_l	list;
}	t_all;

//stock de variables pour plusieurs fonctions
typedef struct s_r
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
}	t_r;

//stock de variables pour la fonction normaliser
typedef	struct s_norm
{
	int	n;
	int min;
	int i;
	int	min_index;
	int prev_min;
}	t_norm;

void	*ft_calloc(int nmemb, int size);

void	disorder_sample(int *a, int max);
void	deb(t_stack A, t_stack B, int n);
void	push(t_stack *src, t_stack *dst);
void	disorder(int *a, int max);
void	put_moves(t_all all);
void 	insert(t_all *all);
void	swap(t_stack *s);
void 	rra(t_all *all);
void 	rrb(t_all *all);
void 	rrr(t_all *all);
void 	sa(t_all *all);
void 	sb(t_all *all);
void 	ss(t_all *all);
void	pb(t_all *all);
void	pa(t_all *all);
void 	ra(t_all *all);
void 	rb(t_all *all);
void 	rr(t_all *all);

int		stack_init(int size_max, int size, t_stack *new);
int 	normaliser(int *list, int size, t_all *all);
int		parser(int argc, char **argv, t_all *all);
int		l_add(t_l *l, char c);
int 	mod_ifier(int a, int size, int max);
int		rotate(t_stack *s, int val);
int		list_init(t_l *l);
int		ft_printf(const char *a, ...);
int		ft_atoi(char *nptr);

t_r		init_reserve(void);

#endif