/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/23 19:24:49 by afomin           ###   ########.fr       */
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
	while (i < argc)
		printf("%d, ", values[i++]);
	printf("\n");
}

int	main(int argc, char **args)
{
	t_stack	*a;
	t_stack	*b;
	int		*indexes;

	args = &args[1];
	argc--;

	indexes = convert(args, argc);

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	stack_init(a, indexes, argc);
	stack_init(b, NULL, 0);

	display(a->values, a->size);
	stack_p(a, b);
	display(a->values, a->size);
	display(b->values, b->size);
	stack_p(b, a);
	display(a->values, a->size);
	display(b->values, b->size);
}
