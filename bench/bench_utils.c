/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:11 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/30 09:28:41 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	spe_char(char *str)
{
	if (ft_strncmp((const char *)str, "O(n²)", ft_strlen("O(n²)")) == 0)
		return (1);
	else if (ft_strncmp((const char *)str, "O(n√n)", ft_strlen("O(n√n)")) == 0)
		return (2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	i = 0;
	if (n < 0)
	{
		if (s1_len > s2_len)
			n = s1_len;
		else
			n = s2_len;
	}
	while (i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

char	*nxc(int n, char c)
{
	char	*s;

	s = malloc(n + 1);
	if (!s)
		return (write(2, "Error\n", 15), NULL);
	s[n--] = '\0';
	while (n >= 0)
		s[n--] = c;
	return (s);
}
