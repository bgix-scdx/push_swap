/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_de_debuggage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:11 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/09 08:57:55 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "checker.h"
#include "../header/push_swap.h"

/*Ce fichier contient des fonctions servant au debuggage, 
il peut etre effacer sans perturber le fonctionement du code*/


/*affiche les stack en tenant compte:
	 de la position de la tete de liste,
	 de la taille des stack,
rotate une stack affectera cet affichage*/
void	put_lists(t_stack A, t_stack B)
{
	int	i;

	printf("-------------      -------------\n");
	printf("|  stack(A) |      |  stack(B) |\n");
	i = 0;
	while (i < A.size && i < B.size)
	{
		printf("|     %d     |      |     %d     |\n", A.array[A.top], B.array[B.top]);
		rotate(&A, 1);
		rotate(&B, 1);
		i += 1;
	}
	while (i < A.size)
	{
		printf("|     %d     |      |     /     |\n", A.array[A.top]);
		i += 1;
		rotate(&A, 1);
	}
	while (i < B.size)
	{
		printf("|     /     |      |     %d     |\n", B.array[B.top]);
		i += 1;
		rotate(&B, 1);
	}
}

/*affiche les stack de maniere plus "brute"
Ne tien pas compte de la position de top
ni de la longeur des stack (j'affiche size_max valeurs)
rotate une liste n'affectera pas cet affichage
Donne cependant les info des structs de stacks*/
void	print_all_stacks(t_stack A, t_stack B)
{
	int	i = 0;

	printf("\n");
	while (i < A.s_max)
		printf("| %d ", A.array[i++]);
	printf("|      topA = %d sizeA = %d s_max = %d\n", A.top, A.size, A.s_max);
	i = 0;
	while (i < B.s_max)
		printf("| %d ", B.array[i++]);
	printf("|      topB = %d sizeB = %d s_max = %d\n", B.top, B.size, B.s_max);
}

/*permet d'economiser des lignes et du temp*/
void	deb(t_stack A, t_stack B, int n)
{
	if (n == 1 || n == 3)
		put_lists(A, B);
	if (n >= 2)
		print_all_stacks(A, B);
}

int count_move(t_all all)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (i < 11)
		count += all.list_move[i++];
	return (count);
}

void	put_moves(t_all all)
{
	int i;

	i = 0;
	printf("\n----------------------------------------------------------------\
--------------\n");
	printf("|  sa  |  sb  |  ss  |  pa  |  pb  |  ra  |  rb  |  rr  | rra  | r\
rb  | rrr  |\n");
	while (i < 11)
		printf("|  %d   ", all.list_move[i++]);
	printf("|\n---------------------------------------------------------------\
---------------\n");
	all.moves = count_move(all);
	printf("moves total = %d\n", all.moves);
}
