/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:10:16 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 19:19:30 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **args)
{
	t_stack	*a;
	t_stack	*b;
	int		*indexes;

	args = &args[1];
	argc--;
	indexes = convert_args(args, argc);
	if (!indexes)
	{
		printstr("Error\n");
		return (-1);
	}
	a = stack_create(indexes, argc);
	b = stack_create(NULL, 0);
	push_swap(a, b);
}
/*
int	main(int argc, char **args)
{
	srand(0);
	int	num = 100;
	if (argc > 1)
		num = atoi(args[1]);
	int	*indexes = malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		indexes[i] = -1;
	for (int i = 0; i < num; i++)
	{
		int n = rand() % num;
		if (indexes[n] == -1)
			indexes[n] = i;
		else
			i--;
	}
	t_stack *a = stack_create(indexes, num);
	t_stack *b = stack_create(NULL, 0);
	push_swap(a, b);
}*/
