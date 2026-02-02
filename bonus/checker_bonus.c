/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:59:35 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/30 16:40:01 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

//pas de protection sur calloc
/*copie 1 a 1 les characteres de l'entrer standard vers inst
si inst n'est pas suffisament grande elle le move dans un nouveau
buffer 10x plus grand*/
char	*read_the_file(int *size)
{
	char	*inst;
	char	*tmp;
	int		size_max;

	size_max = 1000;
	inst = ft_calloc(size_max, 1);
	while (read(0, &inst[*size], 1) > 0)
	{
		(*size)++;
		if (size_max == (*size))
		{
			size_max *= 10;
			tmp = ft_calloc(size_max, 1);
			ft_memmove(tmp, inst, (*size));
			free(inst);
			inst = tmp;
		}
	}
	return (inst);
}

/*recupere "inst" la liste d'instructions et lance les operations adequate,
en cas d'entrer invalide, e = -1 et elle return -1, sinon elle return 
le nombre d'operations effectuer*/
//deb(*A, *B);
int	translate_inst(int size, char *inst, t_stack *A, t_stack *B)
{
	int		i;
	int		e;
	int		n;

	i = 0;
	e = 0;
	n = 0;
	while (i < size)
	{
		if (inst[i] == 's')
			e = swap_launch(&inst[i + 1], A, B);
		else if (inst[i] == 'p')
			e = push_launch(&inst[i + 1], A, B);
		else if (inst[i] == 'r')
			e = rotate_launch(&inst[i + 1], A, B);
		else
			e = -1;
		if (e == -1)
			return (-1);
		i += e;
		n++;
	}
	return (n);
}

/*On lui donne les listes apres avoir fait les operations
et elle verifie que B est vide et A est ordonnee*/
char	*verif(t_stack A, t_stack B)
{
	int	i;
	int	i2;
	int	tmp;
	int	current;

	i = 0;
	tmp = -2147483648;
	if (B.size != 0)
		return ("Instructions doesnt empty the stack B\n");
	while (i < A.size)
	{
		current = A.array[A.top];
		i2 = -1;
		if (current < tmp)
			return ("Instructions doesnt sort the list\n");
		tmp = current;
		i += rotate(&A, 1);
	}
	return ("ok");
}

int	checkdup(int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int arg_c, char **argv)
{
	t_all	all;

	all.n = -1;
	all.a = stack_init(arg_c - 1, arg_c - 1);
	all.b = stack_init(arg_c - 1, 0);
	all.inst = (char *)0;
	if (!all.a.array || !all.b.array || arg_c == 1)
		return (1);
	while (++all.n < all.a.s_max)
	{
		if (ft_safe_atoi(argv[all.n + 1], &all.new) == 0)
			return (free_all(&all), ft_printf("invalid number input\n"));
		all.a.array[all.n] = (int) all.new;
		if (checkdup(all.a.array, all.n + 1))
			return (free_all(&all), ft_printf("Duplicate value\n"));
	}
	all.n = 0;
	all.inst = read_the_file(&all.n);
	all.n = translate_inst(all.n, all.inst, &all.a, &all.b);
	if (all.n == -1)
		ft_printf("error invalid instruction input\n");
	else
		ft_printf("after %d operations: %s\n", all.n, verif(all.a, all.b));
	return (free_all(&all), 0);
}
