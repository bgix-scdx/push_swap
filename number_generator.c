/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:56:51 by bgix              #+#    #+#             */
/*   Updated: 2026/01/21 14:00:47 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	nombres_dans_lordre(int *liste, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		liste[i] = i + 1;
		i++;
	}
}

void	print_list(int *list, int size)
{
	int i = 0;
	
	while (i < size)
		printf("%d\n", list[i++]);
}

int genrand(int max)
{
	static int	r;
	int 		ret;

	r = (r * 9301 + 49297) % 233280;
	ret = r % max;
	if (ret < 0)
		ret += max;
	return (ret);
}

int	ft_swap(int *a1, int *a2)
{
	int tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
	return (0);
}

void swap_rand(int sens, int max, int *list)
{
	int r;
	
	while (sens != 0)
	{
		r = genrand(max - 1);
		if (sens == 1)
		{
			if (list[r] > list[r + 1])
				sens = ft_swap(&list[r], &list[r + 1]);
		}
		else if (list[r] < list[r + 1])
			sens = ft_swap(&list[r], &list[r + 1]);
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	int *liste;
	int n = ft_atoi(argv[1]);
	int cible = ft_atoi(argv[2]);
	int ptot = (n * (n - 1)) / 2;
	int paire = (ptot * cible) / 100;
	
	liste = malloc((1 + n) * sizeof(int));
	if (argv && argv[1])
		nombres_dans_lordre(liste, n);
	//printf("\ninversion de = %d paires \n\n", ptot * cible / 100);
	for (int i = 0; i < (paire); i++)
		swap_rand(-1, n, liste);
	print_list(liste, n);
	// printf("desordre = %d", disorder(liste, n));
	return (0);
}
