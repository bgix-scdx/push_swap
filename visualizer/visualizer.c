/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:12:24 by bgix              #+#    #+#             */
/*   Updated: 2026/01/27 16:22:47 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*int	print_stack(t_stack stack)
{
	int	i;
	int s;
	int	p;
	
	s = 0;
	if (stack.size <= 0)
		return ;
	while (stack.array[s] != 1 && s < stack.size)
		s++;
	i = s;
	while (i < stack.size)
	{
		p = 0;
		ft_printf("║	 [%d] 		", stack.array[i]);
		while (p++ < stack.array[i])
				write(1,"█",4);
		write(1,"\n",1);
		i++;
	}
	i = 0;
	while (i < s)
	{
		p = 0;
		ft_printf("║	 [%d]		", stack.array[i]);
		while (p++ < stack.array[i])
			write(1,"█",4);
		write(1,"\n",1);
		i++;
	}
}*/

int	visualize_stack(int amm)
{
	int	i;
	
	i = 0;
	while (i++ < amm)
		write(1, "█", 4);
	return (i);
}

void	vizualize_line(int line, t_all *all)
{
	int	sep;
	int steps;
	char *spaces;
	steps = 0;
	sep = all->s_max + 10;

	steps += visualize_stack(all->a.array[line]);
	spaces = nxc(sep - steps, ' ');
	ft_printf("%s",spaces);
	visualize_stack(all->b.array[line]);
	write(1, "\n", 1);
}

void	ft_usleep(int amm)
{
	int i;

	i = 0;
	while (i < amm * 100000)
		i++;
}

void	visualize(t_all *all)
{
	int	i;

	if (all->s_max > 100)
		return ;
	i = 0;
	write(1,"\033c",3);
	while (i < all->s_max)
	{
		vizualize_line(i, all);
		i++;
	}
	ft_usleep(60);
}