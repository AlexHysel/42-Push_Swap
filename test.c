/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 12:40:36 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <time.h>

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

static int max_bit(int *nums, int len)
{
	int				max;
	unsigned int	bit;

	max = -1;
	while (--len >= 0)
		if (max < nums[len])
			max = nums[len];
	if (!max)
		return (1);
	bit = 16777216;
	while (!(max & bit))
		bit /= 2;
	return (bit);
}

void	push_swap(t_stack *a, t_stack *b)
{
	unsigned int	bit;
	unsigned int	m_bit;
	int				i;

	bit = 1;
	m_bit = max_bit(a->values, a->size);
	while (bit <= m_bit)
	{
		i = a->size;
		while (i-- > 0)
		{
			if (!(a->values[a->size - 1] & bit))
				stack_p(a, b, "pa\n");
			//if (i > a->size / 2)
			//	stack_r(a, "ra\n");
			else
				stack_r(a, "ra\n");
		}
		while (b->size > 0)
				stack_p(b, a, "pb\n");
		bit *= 2;
	}
}
/*
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
	push_swap(a, b);
}*/
int	main(void)
{
	int	num = 100;
	int	*indexes = malloc(sizeof(int) * num);

	srand(0);
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

	t_stack *a = malloc(sizeof(t_stack));
	t_stack *b = malloc(sizeof(t_stack));
	stack_init(a, indexes, num);
	stack_init(b, NULL, 0);
	push_swap(a, b);
}	
