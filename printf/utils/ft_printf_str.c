/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgix <bgix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:51:01 by bgix              #+#    #+#             */
/*   Updated: 2025/11/25 13:16:04 by bgix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_printf_str(int *length, va_list lst)
{
	char	*arg;
	size_t	len_dup;

	len_dup = *length;
	arg = va_arg(lst, char *);
	if (!arg)
	{
		*length += write(1, "(null)", 6);
		return ;
	}
	*length += write(1, arg, ft_strlen(arg));
}
