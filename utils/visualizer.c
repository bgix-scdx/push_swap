/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:12:24 by bgix              #+#    #+#             */
/*   Updated: 2026/01/28 16:15:38 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	setcol(int amm, int div)
{
	int	perc;

	perc = ((amm * 100) / div);
	if (perc < 33)
		ft_printf("\033[38;2;%d;%d;%dm", (33 - perc) * 7, perc * 7, 0);
	else if (perc >= 100 / 3 && perc <= (100 / 3) * 2)
		ft_printf("\033[38;2;%d;%d;%dm"\
, 0, (33 - (perc - 33)) * 7, (perc - 33) * 7);
	else if (perc < 100)
		ft_printf("\033[38;2;%d;%d;%dm"\
, 0, (perc - 66) * 7, (33 - (perc - 66)) * 7);
	else
		ft_printf("\033[38;2;%d;%d;%dm", 0, 33 * 7, 0);
}

int	visualize_stack(int amm, t_all *all)
{
	int	i;

	i = 0;
	if (!all)
		return (0);
	setcol(amm, all->s_max);
	while (i++ < amm)
		write(1, "█", 4);
	while (i++ <= all->s_max)
		write(1, " ", 1);
	return (i);
}

void	vizualize_line(int line, t_all *all)
{
	int		sep;
	int		steps;
	char	*spaces;

	sep = all->s_max + 25;
	if (line < all->a.size)
		steps = visualize_stack(n_iem(all->a, line), all);
	else
		steps = 2;
	spaces = nxc(sep - steps, ' ');
	ft_printf("%s", spaces);
	if (line < all->b.size)
		visualize_stack(n_iem(all->b, line), all);
	else
		visualize_stack(0, all);
	if (spaces)
		free(spaces);
	write(1, "\n", 1);
}

void	ft_usleep(int amm)
{
	amm = amm * 10000000;
	while (amm != 0)
		amm--;
}

// Clear terminal ; \033c
void	visualize(t_all *all)
{
	int	i;

	i = 0;
	write(1, "\033[H", 3);
	while (i < all->s_max)
	{
		vizualize_line(i, all);
		i++;
	}
	i = 0;
	ft_usleep(1);
}
