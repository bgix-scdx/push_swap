/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:51:01 by bgix              #+#    #+#             */
/*   Updated: 2026/01/28 14:47:41 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	putnbr(int *length, int arg)
{
	char	num[11];
	int		i;

	i = 0;
	if (arg < 0)
	{
		*length += write(2, "-", 1);
		arg *= -1;
	}
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

void	ft_printf_dec(int *length, va_list lst)
{
	int		arg;

	arg = va_arg(lst, int);
	if (arg <= -2147483648)
	{
		*length += write(2, "-2147483648", 11);
		return ;
	}
	else if (arg >= 2147483647)
	{
		*length += write(2, "2147483647", 10);
		return ;
	}
	putnbr(length, arg);
}
