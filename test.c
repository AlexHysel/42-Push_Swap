/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/23 17:18:08 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	*convert(char **nums, int argc)
{
	int	*indexes;

	indexes = malloc(sizeof(int) * argc);
	if (indexes)
		while (--argc >= 0)
			indexes[erase_max(nums)] = argc;
	return (indexes);
}

static void	display(int	*values, int argc)
{
	int	i;

	i = 0;
	while(i < argc)
		printf("%d, ", values[i++]);
	printf("\n");
}

int	main(int argc, char **args)
{
	t_stack	*stack;
	int		*indexes;

	args = &args[1];
	argc--;
	indexes = convert(args, argc);
	stack = malloc(sizeof(t_stack));
	stack_init(stack, indexes, argc);
	
	display(indexes, argc);
	stack_s(stack);
	display(indexes, argc);
	stack_r(stack);
	display(indexes, argc);
	stack_rr(stack);
	display(indexes, argc);
	stack_rr(stack);
	display(indexes, argc);
	stack_rr(stack);
	display(indexes, argc);
}
