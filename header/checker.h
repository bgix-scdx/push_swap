/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:59:49 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/26 15:43:38 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_t
{
	int	*array;
	int	top;
	int	size;
	int	s_max;
}	t_stack;

typedef struct s_r
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
}	t_r;

t_stack	stack_init(int size_max, int size);

void	*ft_memmove(void *dest, void *src, int n);
void	print_all_stacks(t_stack A, t_stack B);
void	push(t_stack *src, t_stack *dst);
void	*ft_calloc(int nmemb, int size);
void	put_lists(t_stack A, t_stack B);
void	deb(t_stack A, t_stack B);
void	swap(t_stack *s);

int		ft_printf(const char *a, ...);
int		rotate_launch(char *inst, t_stack *A, t_stack *B);
int		push_launch(char *inst, t_stack *A, t_stack *B);
int		swap_launch(char *inst, t_stack *A, t_stack *B);
int		rotate(t_stack *s, int val);
int		ft_atoi(char *nptr);

t_r		init_reserve(void);

#endif