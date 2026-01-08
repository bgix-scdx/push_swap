/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:59:35 by vgerthof          #+#    #+#             */
/*   Updated: 2026/01/08 13:29:55 by vgerthof         ###   ########.fr       */
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
int	translate_inst(int size, char *inst, t_stack *A, t_stack *B)
{
	char	*str;
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
		//deb(*A, *B);
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
	int	tmp;
	int	current;

	tmp = 0;
	if (B.size != 0)
		return ("B n'est pas vide");
	while (i < A.size)
	{
		current = A.array[A.top];
		if (current < tmp)
			return ("l'ordre est mauvais");
		tmp = current;
		i += rotate(&A, 1);
	}
	return ("ok");
}

//pas de protections sur les malloc/ calloc notament dans stack init
int	main(int arg_c, char **argv)
{
	t_stack	stacka;
	t_stack	stackb;
	char	*inst;
	int		size;
	int		n;

	stacka = stack_init(arg_c - 1, arg_c - 1);
	stackb = stack_init(arg_c - 1, 0);
	if (!stacka.array || !stackb.array)
		return (1);
	while (arg_c-- > 1)
		stacka.array[arg_c - 1] = ft_atoi(argv[arg_c]);
	//deb(stacka, stackb);
	inst = read_the_file(&size);
	n = translate_inst(size, inst, &stacka, &stackb);
	if (n == -1)
		printf("error invalid input\n");
	else
		printf("\napres %d operations: %s\n", n, verif(stacka, stackb));
	return (free(inst), free(stacka.array), free(stackb.array), 0);
}
