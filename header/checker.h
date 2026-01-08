/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:59:49 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 08:49:33 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CHECKER_H
# define 	CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_t
{
	int *array;
	int	top;
	int size;
	int s_max;
}t_stack;

t_stack	stack_init(int size_max, int size);

void	*ft_memmove(void *dest,void *src, int n);
void	print_all_stacks(t_stack A, t_stack B);
void	push(t_stack *src, t_stack *dst);
void	*ft_calloc(int nmemb, int size);
void	put_lists(t_stack A, t_stack B);
void	deb(t_stack A, t_stack B);
void	swap(t_stack *s);

int		rotate_launch(char *inst, t_stack *A, t_stack *B);
int		push_launch(char *inst, t_stack *A, t_stack *B);
int 	swap_launch(char *inst, t_stack *A, t_stack *B);
int 	mod_ifier(int a, int size, int max);
int		plus_mod(int n, int val, int mod);
int		rotate(t_stack *s, int val);
int		ft_atoi(char *nptr);

#endif