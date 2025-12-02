/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:10:16 by afomin            #+#    #+#             */
/*   Updated: 2025/12/02 14:34:36 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "push_swap.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static char	contains(int *nums, int size, int num)
{
	while (size-- > 0)
		if (nums[size] == num)
			return (1);
	return (0);
}

static void	fill(int *values, int len)
{
	time_t	t;

	t = time(NULL);
	srand(localtime(&t)->tm_sec);
	for (int i = 0; i < len; i++)
	{
		int n = rand() % 1000;
		if (!contains(values, i, n))
			(values)[i] = n;
		else
			i--;
	}
}

static void	arg_log(int *nums, int size)
{
	int	i;
	int	fd;

	fd = open("trace.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	i = 0;
	while (i < size)
		dprintf(fd, "%d ", nums[i++]);
	close(fd);
}

int			main(int argc, char **args)
{
	int	len = 100;
	int *values;

	if (argc > 1)
		len = atoi(args[1]);
	values = malloc(sizeof(int) * len);
	fill(values, len);
	arg_log(values, len);
	t_stack *a = stack_create(values, len, 'a');
	t_stack *b = stack_create(NULL, 0, 'b');
	push_swap(a, b);
	free(a->values);
	free(a);
	free(b->values);
	free(b);
}*/
