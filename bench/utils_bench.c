#include "../header/push_swap.h"

char	*nxc(int n, char c)
{
	char *s;

	s = malloc(n + 1);
	if (!s)
		return(write(1, "erreur malloc\n", 15), NULL);
	s[n] = '\0';
	while (n-- >= 0)
		s[n] = c;
	return (s);
}

void	contour(t_screen *screen, int w, int h)
{
	int 		i;
	char		*equals;
	
	i = 0;
	equals = nxc(98, '=');
	while (i < h)
	{
		if (i == 0 || i == h - 1)
			putstr_screen(screen, 1, i, equals);
		putstr_screen(screen, 0, i, "#");
		putstr_screen(screen, 99, i++, "#");
	}
}
