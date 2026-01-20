/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:01 by bgix              #+#    #+#             */
/*   Updated: 2026/01/20 10:18:53 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
//pour cette fonction et celle en desous, les -X \
correspond a la taille du text qui set la couleur \
qui faut enlever (car ils sont pas visible)
int	colone_one(int i, t_all all)
{
	char	*mod;
	char	*complexity;

	mod = ft_substr(all.screen->mod_difficulty, 0, 19);
	complexity = ft_substr(all.screen->mod_difficulty, 19, 26);
	if (i == 3)
		return (ft_printf("\033[1;37m║    \033[1;31mAlgorythm Used : \
\033[1;37m%s\033[0m", mod) + 1 - 25);
	else if (i == 6)
		return (ft_printf("\033[1;37m║    \033[1;31mAlgorythm Complexity : \
\033[1;37m%s\033[0m", complexity) + 1 - 25);
	else if (i == 9)
		return (ft_printf("\033[1;37m║    \033[1;31mTotal Moves : \
\033[1;37m%d\033[0m", all.moves) + 1 - 25);
	else if (i == 12)
		return (ft_printf("\033[1;37m║    \033[1;31mPre Sorting : \
\033[1;37m%d%%\033[0m", all.screen->disorder) + 1 - 25);
	else if (i == 15)
		return (ft_printf("\033[1;37m║    \033[1;31mPost Sorting : \
\033[1;37m%d%%\033[0m", disorder(all.a.array, all.a.s_max)) + 1 - 25);
	else if (i == 18)
		return (ft_printf("\033[1;37m║\033[0m") + 1 - 11);
	return (0);
}

int	colone_two(int i, t_all all)
{
	int	*l;	
	int	steps;

	l = all.list_move;
	if (i == 3)
		return (ft_printf("\033[1;31msa :  \033[6;37m%d\033[0m    \
\033[1;31msb :  \033[4;37m%d\033[0m", l[0], l[1]) - 36);
	else if (i == 6)
		return (ft_printf("\033[1;31mpa :  \033[4;37m%d\033[0m    \
\033[1;31mpb :  \033[4;37m%d\033[0m", l[3], l[4]) - 37);
	else if (i == 9)
		return (ft_printf("\033[1;31mra :  \033[4;37m%d\033[0m    \
\033[1;31mrb :  \033[4;37m%d\033[0m", l[5], l[6]) - 36);
	else if (i == 12)
		return (ft_printf("\033[1;31mrra :  \033[4;37m%d\033[0m    \
\033[1;31mrrb :  \033[4;37m%d\033[0m", l[8], l[9]) - 36);
	else if (i == 15)
		return (ft_printf("\033[1;31mss :  \033[4;37m%d\033[0m    \
\033[1;31mrr :  \033[4;37m%d\033[0m", l[2], l[7]) - 36);
	else if (i == 18)
		return (ft_printf("\033[1;31mrrr :  \033[4;37m%d\033[0m", l[10]) - 18);
	return (0);
}

void	print_column(t_all all, int index, int roof)
{
	int	steps;
	int	c2_pos;
	int	length;

	c2_pos = 60;
	steps = colone_one(index, all) - 1;
	steps = steps + ft_printf("%s", nxc(c2_pos - steps, ' '));
	length = steps + colone_two(index, all);
	ft_printf("%s\033[1;37m║\033[0m\n", nxc(roof - length + 1, ' '));
}

void	bench(t_all all)
{
	char	*hash;
	char	*space;
	int		i;
	int		lines;
	int		size;

	size = 100;
	lines = 20;
	i = 0;
	hash = nxc(size, '#');
	space = nxc(size - 2, ' ');
	while (i++ <= lines)
	{
		if (i == 1 || i == lines)
			ft_printf("\033[1;37m%s\033[0m\n", hash);
		else if (i % 3 == 0 && i < 19)
			print_column(all, i, size);
		else if (i < lines)
			ft_printf("\033[1;37m║%s║\n\033[0m", space);
	}
}
