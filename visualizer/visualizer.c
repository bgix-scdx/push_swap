/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:12:24 by bgix              #+#    #+#             */
/*   Updated: 2026/01/27 15:52:20 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*void	print_stack(t_stack stack)
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

void	vizualize_line(int line, t_all *all)
{
	int	sep;
	
	sep = 125;
}

void	visualize(t_all *all)
{
	int	sep;
	int	i;


	i = 0;
	while (i < all->s_max)
	{
		vizualize_line(i, all);
		i++;
	}
	write(1,"\033c",5);
	usleep(10000);
}