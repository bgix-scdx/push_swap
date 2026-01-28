/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:05:17 by bgix              #+#    #+#             */
/*   Updated: 2026/01/28 14:44:28 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*swap(char *s, int len, int arg, bool is_maj)
{
	int		i;
	char	temp;

	i = 0;
	while (is_maj == true && s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	if (arg >= 0)
		return (s);
	i = 0;
	while (i < len / 2)
	{
		temp = s[len - i - 1];
		s[len - i - 1] = s[i];
		s[i] = temp;
		i++;
	}
	return (s);
}

static void	negative(char *baka_base, int arg, int *length, int base_len)
{
	char	result[7];
	int		i;

	i = 0;
	while (i == 0 || ((arg > 0 || arg < 0) && i <= 7))
	{
		if (i == 0)
			result[i++] = baka_base[(arg % base_len)];
		else if (baka_base[(arg % base_len)])
			result[i++] = baka_base[(arg % base_len)];
		arg /= base_len;
	}
	while (i != 8)
		result[i++] = '\0';
	i--;
	while (i >= 0)
	{
		if (result[i])
			*length += write(2, &result[i], 1);
		else
			*length += write(2, &baka_base[0], 1);
		i--;
	}
}

void	ft_printf_base(int *length, va_list lst, char *baka_base, bool is_maj)
{
	char	result[7];
	int		arg;
	int		base_len;
	int		i;

	base_len = ft_strlen(baka_base);
	i = 0;
	arg = va_arg(lst, int);
	baka_base = swap(baka_base, base_len, arg, is_maj);
	if (arg < 0)
	{
		negative(baka_base, (arg * -1) - 1, length, base_len);
		return ;
	}
	while (i == 0 || (arg != 0 && i <= 7))
	{
		result[i++] = baka_base[((arg % base_len))];
		arg /= base_len;
	}
	while (i-- > 0)
		*length += write(2, &result[i], 1);
}
