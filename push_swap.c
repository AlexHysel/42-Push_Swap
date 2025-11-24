/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 16:34:26 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate(char **args, int argc)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < argc)
	{
		k = -1;
		while (args[i][++k])
			if ((args[i][k] < '0' || args[i][k] > '9') && args[i][k] != '-')
				return (0);
		j = i;
		while (args[++j])
		{
			k = 0;
			while (args[i][k] && args[i][k] == args[j][k])
				k++;
			if (args[i][k] - args[j][k] == 0)
				return (0);
		}
	}
	return (1);
}

static int	*convert(char **nums, int argc)
{
	int	*indexes;
	int	c;
	int	i;

	i = 0;
	c = argc / 2;
	if (!validate(nums, argc))
		return (NULL);
	indexes = malloc(sizeof(int) * argc);
	if (indexes)
	{
		while (--argc >= 0)
			indexes[erase_max(nums)] = argc;
		while (++i < c)
			swap(&indexes[i], &indexes[argc - i - 1]);
	}
	return (indexes);
}

static int	max_bit(int *nums, int len)
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
			if (a->values[a->size - 1] & bit)
				stack_r(a, "ra\n");
			else
				stack_p(a, b, "pb\n");
		}
		while (b->size > 0)
			stack_p(b, a, "pa\n");
		bit *= 2;
	}
}

#include <stdio.h>
#include <time.h>

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
	if (!indexes)
	{
		printstr("Error\n");
		return (-1);
	}
	a = stack_create(indexes, argc);
	b = stack_create(NULL, 0);
	display(a->values, a->size);
	push_swap(a, b);
	display(a->values, a->size);
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
