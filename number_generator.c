#include "header/push_swap.h"

void	nombres_dans_lordre(int n)
{
	int i = 1;

	while (i <= n - 1)
		printf("%d\n", i++);
	printf("%d", i);
}

// int	*list_de_nombre(int n)
// {
// 	int *list;
// 	int	i;

// 	i = 1;
// 	list = ft_calloc(n, sizeof(int));
// 	if (!list)
// 		return ((int *)0);
// 	while (i <= n)
// 	{
// 		list[i] = i;
// 		i++;
// 	}
// 	return (list);
// }

// void	nombres_au_pif(int n, int seed)
// {
// 	int *list;
// 	int	i;

// 	list = list_de_nombre(n);
// 	while (i < n)
// 	{
// 		printf("%d\n", seed);
// 		i++;
// 	}
// }

int main(int argc, char **argv)
{
	(void) argc;
	if (argv && argv[1])
		nombres_dans_lordre(ft_atoi(argv[1]));
	return (0);
}