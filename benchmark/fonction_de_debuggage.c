/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_de_debuggage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:11 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/09 13:24:54 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "checker.h"
#include "../header/push_swap.h"

/*Ce fichier contient des fonctions servant au debuggage, 
il peut etre effacer sans perturber le fonctionement du code*/

char *pad(int n)
{
	char pad[6];
	
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
	t_r	i;
	char *p1;
	char *p2;
	
	i = init_reserve();
	printf("-------------      -------------\n|  stack(A) |      |  stack(B) |\n");
	i.a = 0;
	while (i.a < A.size || i.a < B.size)
	{
		i.b = A.array[A.top];
		i.c = B.array[B.top];
		p1 = pad(i.b);
		p2 = pad(i.c);
		if (i.a >= B.size)
			printf("|     %d%s|      |     /     |\n", i.b, p1);
		else if (i.a >= A.size)
			printf("|     /     |      |     %d%s|\n", i.c, p2);
		else 	
			printf("|     %d%s|      |     %d%s|\n",i.b ,p1 ,i.c , p2);
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
