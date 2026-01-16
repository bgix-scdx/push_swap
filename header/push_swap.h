/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:06:23 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/16 09:30:54 by vgerthof         ###   ########.fr       */
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

typedef struct s_screen
{
	char	*mod_difficulty;
	int		disorder;
}	t_screen;

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
	t_screen	*screen;
	t_stack		a;
	t_stack		b;
	char		*flags;
	int			moves;
	int			*list_move;
	int			s_max;
	t_l			list;
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


t_screen	*screen_init(t_screen *screen, int w, int h, char bg);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		*ft_calloc(int nmemb, int size);
char		*nxc(int n, char c);
char		*ft_itoa(int n);

void		disorder_sample(int *a, int max);
void		push(t_stack *src, t_stack *dst);
void		deb(t_all *all, int n);
void		put_moves(t_all all);
void		radix_3(t_all *all);
void 		insert(t_all *all);
void		opti_4(t_all *all);
void		opti_5(t_all *all);
void		radix(t_all *all);
void		swap(t_stack *s);
void		bench(t_all all);
void 		rra(t_all *all);
void 		rrb(t_all *all);
void 		rrr(t_all *all);
void 		sa(t_all *all);
void 		sb(t_all *all);
void 		ss(t_all *all);
void		pb(t_all *all);
void		pa(t_all *all);
void 		ra(t_all *all);
void	 	rb(t_all *all);
void 		rr(t_all *all);

int			stack_init(int size_max, int size, t_stack *new);
int			parser(int argc, char **argv, t_all *all);
int			*normaliser(int *list, int size);
int			ft_printf(const char *a, ...);
int			rotate(t_stack *s, int val);
int			opti_3(t_all *all, int *l);
int			disorder(int *a, int max);
int 		count_move(t_all all);
int 		count_move(t_all all);
int			l_add(t_l *l, char c);
int			ft_atoi(char *nptr);
int			list_init(t_l *l);
int			ft_strlen(char *s);

t_r			init_reserve(void);

#endif