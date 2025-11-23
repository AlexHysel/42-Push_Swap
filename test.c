/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 04:48:06 by afomin           ###   ########.fr       */
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

void	push_swap(t_stack *a, t_stack *b)
{
	unsigned int	bit;
	int				i;
	int				rotates_needed;

	bit = 1;
	i = 0;
	while (bit != 0)
	{
		rotates_needed = a->size - 1;
		while (i < a->size && a->values[i++] & bit)
			rotates_needed--;
		if (a->values[a->size - 1] & bit)
		{
			i++;
			stack_r(a);
		}
		else
			stack_p(a, b);
		while (rotates_needed-- > 0)
		{
			if (a->values[a->size - 1] & bit)
			{
				i++;
				stack_r(a);
			}
			else
				stack_p(a, b);
		}
		while (b->size > 0)
				stack_p(b, a);
		bit *= 2;
	}
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
	push_swap(a, b);
	display(a->values, a->size);
}
