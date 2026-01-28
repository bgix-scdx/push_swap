/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:06:23 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/28 13:41:49 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NFLAGS 6   
# ifndef INTMAX
#  define INTMAX 2147483647
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_s	t_all;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	best_a;
	int	best_b;
	int	cost;
	int	bestcost;
}	t_cost;

typedef struct s_screen
{
	char	*mod_difficulty;
	char	*sort_algo;
	int		disorder;
}	t_screen;

//info relatives a une stack particuliere
typedef struct s_t
{
	int	*array;
	int	top;
	int	size;
	int	s_max;
	int	(*rotate)(t_all *all);
	int	(*rrotate)(t_all *all);
	int	(*push)(t_all *all);
}	t_stack;

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
typedef struct s_norm
{
	int	n;
	int	min;
	int	i;
	int	min_index;
	int	prev_min;
}	t_norm;

t_all	*all_init(int argc, char **argv);

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*nxc(int n, char c);
char	*ft_itoa(int n);

void	greedy_return(t_stack	*a, t_stack	*b, t_all *all);
void	print_move_check(t_all *all, const char *move);
void	pusha(t_all *all, t_stack *a, t_stack *b);
void	search(int val, t_all *all, t_stack s);
void	disorder_sample(int *a, int max);
void	push(t_stack *src, t_stack *dst);
void	*ft_calloc(int nmemb, int size);
void	push_chunk_a(t_all *all);
void	deb(t_all *all, int n);
void	visualise(t_all *all);
void	turk_sort(t_all *all);
void	radix_3(t_all *all);
void	insert(t_all *all);
void	opti_4(t_all *all);
void	opti_5(t_all *all);
void	chunk(t_all *all);
void	radix(t_all *all);
void	swap(t_stack *s);
void	bench(t_all all);

int		ft_strncmp(const char *s1, const char *s2, int n);
int		stack_init(int size_max, int size, t_stack *new);
int		parser(int argc, char **argv, t_all *all);
int		*normaliser(int *list, int size);
int		ft_printf(const char *a, ...);
int		rotate(t_stack *s, int val);
int		opti_3(t_all *all, int *l);
int		check_dup(int *a, int max);
int		disorder(int *a, int max);
int		n_iem(t_stack s, int n);
int		count_move(t_all all);
int		ft_atoi(char *nptr);
int		max(int n1, int n2);
int		ft_strlen(char *s);
int		mod(int p, int q);
int		rra(t_all *all);
int		rrb(t_all *all);
int		rrr(t_all *all);
int		sa(t_all *all);
int		sb(t_all *all);
int		ss(t_all *all);
int		pb(t_all *all);
int		pa(t_all *all);
int		ra(t_all *all);
int		rb(t_all *all);
int		rr(t_all *all);
int		ft_sqrt(int n);
int		abs(int n);

t_r		init_reserve(void);

#endif