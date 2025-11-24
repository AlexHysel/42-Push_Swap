/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:11:14 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 18:58:00 by afomin           ###   ########.fr       */
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
		if (args[i][0] == '-')
			k++;
		while (args[i][++k])
			if (args[i][k] < '0' || args[i][k] > '9')
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

	c = argc;
	if (!validate(nums, argc))
		return (NULL);
	indexes = malloc(sizeof(int) * argc);
	if (indexes)
		while (--argc >= 0)
			indexes[erase_max(nums)] = argc;
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
	int				size;

	bit = 1;
	m_bit = max_bit(a->values, a->size);
	size = a->size;
	while (bit <= m_bit)
	{
		i = 0;
		while (i++ < size)
		{
			if (a->values[0] & bit)
				stack_r(a, "ra\n");
			else
				stack_p(a, b, "pb\n");
		}
		while (b->size > 0)
			stack_p(b, a, "pa\n");
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
