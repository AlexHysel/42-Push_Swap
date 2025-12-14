/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:06:51 by afomin            #+#    #+#             */
/*   Updated: 2025/12/14 19:50:53 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	error(char *err_msg)
{
	while (*err_msg)
		write(2, err_msg++, 1);
	return (-1);
}

static void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
}

int	main(int argc, char **args)
{
	t_stack	*a;
	t_stack	*b;
	int		*indexes;
	char	**splited;

	args = &args[1];
	if (--argc == 1)
	{
		argc = ft_count_words(args[0]);
		splited = ft_split(args[0]);
		indexes = convert_args(splited, argc);
		free_splited(splited);
	}
	else
		indexes = convert_args(args, argc);
	if (!indexes)
		return (error("Error"));
	a = stack_create(indexes, argc, 'a');
	b = stack_create(NULL, 0, 'b');
	push_swap(a, b);
	free(a->values);
	free(a);
	free(b->values);
	free(b);
}
