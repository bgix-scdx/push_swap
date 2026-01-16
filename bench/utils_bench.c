#include "../header/push_swap.h"

static char	*verif(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		return (verif());
	}
	if (len > s_len - start)
		len = s_len - start;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

static char	*ft_itoa2(int n, int sign)
{
	char	*str;
	int		i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	i += sign;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (n > 0)
	{
		str[--i] = '0' + (n % 10);
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		sign;

	if (n == 0)
		return ("0");
	sign = 0;
	if (n <= 0)
	{
		sign = 1;
		n = -n;
	}
	return (ft_itoa2(n, sign));
}

int count_move(t_all all)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (i < 11)
		count += all.list_move[i++];
	return (count);
}
