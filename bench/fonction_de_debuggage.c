/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_de_debuggage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:11 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/27 12:11:24 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	spe_char(char *str)
{
	if (ft_strncmp((const char *)str, "O(n²)", 5) == 0)
		return (1);
	else if (ft_strncmp((const char *)str, "O(n√n)", 5) == 0)
		return (2);
	return (0);
}
