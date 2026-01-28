/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:51:01 by bgix              #+#    #+#             */
/*   Updated: 2026/01/28 14:44:36 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_char(int *length, va_list lst)
{
	unsigned char	arg;

	arg = va_arg(lst, int);
	*length += write(2, &arg, 1);
}
