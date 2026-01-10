/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:16:28 by bgix              #+#    #+#             */
/*   Updated: 2026/01/10 15:11:23 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../header/push_swap.h"

char	*ft_strdup(char *s)
{
	char	*mal;
	int		i;

	i = 0;
	mal = malloc(ft_strlen(s) + 1 * (sizeof(char)));
	if (!mal)
		return (NULL);
	while (s[i])
	{
		mal[i] = s[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

void	arg_check(char asc, int *length, va_list lst)
{
	char	*mal;

	mal = ft_strdup("0123456789abcdef");
	if (!mal)
		return ;
	if (asc == 'c')
		ft_printf_char(length, lst);
	else if (asc == 's')
		ft_printf_str(length, lst);
	else if (asc == 'i' || asc == 'd')
		ft_printf_dec(length, lst);
	else if (asc == 'p')
		ft_printf_void(length, lst);
	else if (asc == 'u')
		ft_printf_undec(length, lst);
	else if (asc == 'x')
		ft_printf_base(length, lst, mal, false);
	else if (asc == 'X')
		ft_printf_base(length, lst, mal, true);
	else if (asc == '%')
		*length += write(1, "%", 1);
	else
		*length = -1;
	free(mal);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	int		len;

	if (!str)
		return (-1);
	va_start(lst, str);
	len = 0;
	i = 0;
	while (str[i] && len >= 0)
	{
		if (str[i] == '%' && str[i + 1])
		{
			arg_check(str[i + 1], &len, lst);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(lst);
	return (len);
}
