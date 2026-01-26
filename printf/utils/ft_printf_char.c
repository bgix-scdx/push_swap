/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:51:01 by bgix              #+#    #+#             */
/*   Updated: 2026/01/26 16:30:13 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_char(int *length, va_list lst)
{
	unsigned char	arg;

	arg = va_arg(lst, int);
	*length += write(1, &arg, 1);
}
