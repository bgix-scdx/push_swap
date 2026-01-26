/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:11 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/26 16:27:17 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "checker.h"
#include "../header/push_swap.h"

/*Ce fichier contient des fonctions servant au debuggage, 
il peut etre effacer sans perturber le fonctionement du code*/

char	*pad(int n)
{
	if (n < 10)
		return ("     ");
	if (n < 100)
		return ("    ");
	if (n < 1000)
		return ("   ");
	else
		return ("  ");
}

/*affiche les stack en tenant compte:
	 de la position de la tete de liste,
	 de la taille des stack,
rotate une stack affectera cet affichage*/
void	put_lists(t_stack A, t_stack B)
{
	t_r		i;
	char	*p1;
	char	*p2;

	i = init_reserve();
	ft_printf("-------------      -------------\n|");
	ft_printf("  stack(A) |      |  stack(B) |\n");
	i.a = 0;
	while (i.a < A.size || i.a < B.size)
	{
		i.b = A.array[A.top];
		i.c = B.array[B.top];
		p1 = pad(i.b);
		p2 = pad(i.c);
		if (i.a >= B.size)
			ft_printf("|     %d%s|      |     /     |\n", i.b, p1);
		else if (i.a >= A.size)
			ft_printf("|     /     |      |     %d%s|\n", i.c, p2);
		else
			ft_printf("|     %d%s|      |     %d%s|\n", i.b, p1, i.c, p2);
		rotate(&A, 1);
		i.a += rotate(&B, 1);
	}
}

/*affiche les stack de maniere plus "brute"
Ne tien pas compte de la position de top
ni de la longeur des stack (j'affiche size_max valeurs)
rotate une liste n'affectera pas cet affichage
Donne cependant les info des structs de stacks*/
void	print_all_stacks(t_stack A, t_stack B)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (i < A.s_max)
		ft_printf("| %d ", A.array[i++]);
	ft_printf("|  topA = %d sizeA = %d s_max = %d\n", A.top, A.size, A.s_max);
	i = 0;
	while (i < B.s_max)
		ft_printf("| %d ", B.array[i++]);
	ft_printf("|  topB = %d sizeB = %d s_max = %d\n", B.top, B.size, B.s_max);
}

/*permet d'economiser des lignes et du temp*/
void	deb(t_all *all, int n)
{
	int	d;

	if (n == 1 || n == 3)
		put_lists(all->a, all->b);
	if (n >= 2)
		print_all_stacks(all->a, all->b);
	d = disorder(all->a.array, all->s_max);
}

void	put_moves(t_all all)
{
	int	i;

	i = 0;
	ft_printf("\n----------------------------------------------------------------\
--------------\n");
	ft_printf("|  sa  |  sb  |  ss  |  pa  |  pb  |  ra  |  rb  |  rr  | rra  | r\
rb  | rrr  |\n");
	while (i < 11)
		ft_printf("|  %d   ", all.list_move[i++]);
	ft_printf("|\n---------------------------------------------------------------\
---------------\n");
	all.moves = count_move(all);
	ft_printf("moves total = %d\n", all.moves);
}
