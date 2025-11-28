/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:24:47 by afomin            #+#    #+#             */
/*   Updated: 2025/11/28 16:18:46 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	erase_max(char **nums)
{
	int		max_i;
	int		i;

	max_i = 0;
	i = 0;
	while (nums[i])
	{
		if (num_as_str_cmp(nums[i], nums[max_i]) >= 0)
			max_i = i;
		i++;
	}
	nums[max_i] = "";
	return (max_i);
}

static int	validate_args(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		if (!is_integer(args[i]))
			return (0);
		j = i;
		while (args[++j])
			if (!num_as_str_cmp(args[i], args[j]))
				return (0);
	}
	return (1);
}

int	*convert_args(char **nums, int argc)
{
	int	*indexes;

	if (!validate_args(nums))
		return (NULL);
	indexes = malloc(sizeof(int) * argc);
	if (indexes)
		while (--argc >= 0)
			indexes[erase_max(nums)] = argc;
	return (indexes);
}
