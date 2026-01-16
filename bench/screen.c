#include "../header/push_swap.h"

void	colone_one(int i, t_all all)
{
	char *mod;
	char *complexity;

	mod = ft_substr(all.screen->mod_difficulty, 0, 19);
	complexity = ft_substr(all.screen->mod_difficulty, 19, 10);	
	if (i == 3)
		ft_printf("   algoritme utiliser: %s \n", mod);
	else if (i == 6)
		ft_printf("   complexiter: %s\n", complexity);
	else if (i == 9)
		ft_printf("   nombre total de coups: %d\n", all.moves);
	else if (i == 12)
		ft_printf("   desordre avant : %d%%\n", all.screen->disorder);
	else if (i == 15)
		ft_printf("   desordre apres : bah 0%% ducoup\n");
	else if (i == 18)
		ft_printf("   moves totals:%d\n", all.moves);
}

void	colone_two(int i, t_all all)
{
	int	*l;	

	l = all.list_move;	
	if (i == 4)
		ft_printf("%ssa :  %d    sb :  %d\n", nxc(60, ' '), l[0], l[1]);
	else if (i == 7)
		ft_printf("%spa :  %d    pb :  %d\n", nxc(60, ' '), l[3], l[4]);
	else if (i == 10)
		ft_printf("%sra :  %d    rb :  %d\n", nxc(60, ' '), l[5], l[6]);
	else if (i == 13)
		ft_printf("%srra :  %d    rrb :  %d\n", nxc(60, ' '), l[8], l[9]);
	else if (i == 16)
		ft_printf("%sss :  %d    rr :  %d\n", nxc(60, ' '), l[2], l[7]);
	else if (i == 19)
		ft_printf("%srrr :  %d         \n", nxc(60, ' '), l[10]);
}

void	bench(t_all all)
{
	char *hash;
	char *space;
	int i;

	i = 0;
	hash = nxc(100, '#');
	space = nxc(98, ' ');
	while (i++ < 25)
	{
		if (i == 1 || i == 25)
			ft_printf("%s\n", hash);
		else if (i % 3 == 0 && i < 19)
			colone_one(i, all);
		else if (i % 3 ==  1 && i < 20)
			colone_two(i, all);
		else 
			ft_printf("%s\n", space);
	}
}

