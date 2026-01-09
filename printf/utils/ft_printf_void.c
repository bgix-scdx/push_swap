/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:45:18 by bgix              #+#    #+#             */
/*   Updated: 2025/11/25 13:16:47 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	loop(int *length, unsigned long long arg, char *base)
{
	if (arg >= 16)
	{
		loop(length, arg / 16, base);
	}
	*length += write(1, &base[arg % 16], 1);
}

void	ft_printf_void(int *length, va_list lst)
{
	char	*hex;
	void	*arg;

	hex = "0123456789abcdef";
	arg = va_arg(lst, void *);
	if (!arg)
	{
		*length += write(1, "(nil)", 5);
		return ;
	}
	*length += write(1, "0x", 2);
	loop(length, (unsigned long long)arg, hex);
}
