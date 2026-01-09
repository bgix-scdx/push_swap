/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:51:01 by bgix              #+#    #+#             */
/*   Updated: 2025/11/25 12:17:51 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_char(int *length, va_list lst)
{
	unsigned char	arg;
	size_t			len_dup;

	len_dup = *length;
	arg = va_arg(lst, int);
	*length += write(1, &arg, 1);
	if (len_dup > *length)
		*length = -1;
}
