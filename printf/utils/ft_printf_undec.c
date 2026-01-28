/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_undec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:45:12 by bgix              #+#    #+#             */
/*   Updated: 2026/01/28 14:45:02 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_undec(int *length, va_list lst)
{
	char			num[11];
	int				i;
	unsigned int	arg;

	arg = va_arg(lst, int);
	i = 0;
	while (arg >= 10)
	{
		num[i] = (arg % 10) + '0';
		arg /= 10;
		i++;
	}
	num[i] = (arg % 10) + '0';
	while (i >= 0)
	{
		*length += write(2, &num[i], 1);
		i--;
	}
}
