#include "header/push_swap.h"

void	radix(t_all *all)
{
	int i;
	int e;
	int top;

	e = 1;
	while (e <= all->s_max && disorder(all->a.array, all->s_max) != 0)
	{
		i = 0;
		while (i < all->s_max)
		{
			if ((all->a.array[all->a.top] & e) != e)
			{
				if (i < all->s_max - 1)
					pb(all);
			}
			else 
				ra(all);
			i++;
		}
		// top = all->a.top;
		// if (all->a.array[top] > all->a.array[(top + 1) % all->a.size])
		// 	sa(all);
		i = 0;
		while (all->b.size != 0)
			pa(all);
		e *= 2;
	}

}