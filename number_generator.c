/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:56:51 by bgix              #+#    #+#             */
/*   Updated: 2026/01/31 14:47:25 by vgerthof         ###   ########.fr       */
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

void	ft_putnumber(int n)
{
	char	towrite;

	if (n > 9)
		ft_putnumber(n / 10);
	towrite = n % 10 + '0';
	write(1, &towrite, 1);
}

void	print_list(int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnumber(list[i++]);
		write(1, "\n", 1);
	}
}

void	swap_rand(int stop, int max, int *list, int seed)
{
	int	r;
	int	tmp;

	while (stop != 0)
	{
		r = genrand(max - 1, seed);
		if (list[r] < list[r + 1])
		{
			tmp = list[r];
			list[r] = list[r + 1];
			list[r + 1] = tmp;
			stop = 0;
		}
	}
}

/*#include <stdio.h>*/
/*
printf("\ninversion de = %d paires \n\n", n_paire);
*/
int	main(int argc, char **argv)
{
	int	*liste;
	int	n;
	int	n_paire;
	int	i;

	if (argc < 3)
		return (1);
	n = ft_atoi(argv[1]);
	n_paire = ((n * (n - 1)) / 2 * ft_atoi(argv[2])) / 100;
	liste = malloc((1 + n) * sizeof(int));
	if (argv && argv[1])
		nombres_dans_lordre(liste, n);
	i = 0;
	while (i++ < n_paire)
	{
		if (i == 1)
			swap_rand(1, n, liste, ft_atoi(argv[3]));
		else
			swap_rand(1, n, liste, 0);
	}
	print_list(liste, n);
	return (free(liste), 0);
}
