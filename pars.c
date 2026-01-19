/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 08:59:27 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/19 14:58:20 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	is_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (i < 3)
		return (0);
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

/*
*compare s1 () et s2, si elles sont egale,
*met '1' dans flags a l'index donner en argument
*return 0 si le flag a ete trouver 
*/
int	cmp_update(char *s1, char *s2, t_all *all, int index)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if ((unsigned char) s1[i] - (unsigned char) s2[i] == 0)
	{
		all->flags[index] = '1';
		return (1);
	}
	return (0);
}

int	flag_fill(char *s, t_all *all, int *flag_count)
{
	int	f;

	f = *flag_count;
	*flag_count += cmp_update(s, "--simple", all, 0);
	*flag_count += cmp_update(s, "--medium", all, 1);
	*flag_count += cmp_update(s, "--complex", all, 2);
	*flag_count += cmp_update(s, "--adaptive", all, 3);
	*flag_count += cmp_update(s, "--bench", all, 4);
	if (f == *flag_count)
		return (-1);
	return (1);
}

/*
*Lis les argument argv commencant par -- et remplis all->flags
*return flags_count ou alors -1 si quelquechose c'est mal passer
*/
int	parser(int argc, char **argv, t_all *all)
{
	int	i;
	int	flags_count;

	i = 1;
	flags_count = 0;
	while (is_flag(argv[i]))
	{
		if (flag_fill(argv[i], all, &flags_count) == -1)
			return (write(1, "wrong flag input please retry\n", 31), -1);
		i++;
	}
	all->s_max = argc - flags_count;
	return (flags_count);
}
