/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:24:47 by afomin            #+#    #+#             */
/*   Updated: 2025/11/30 17:45:39 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

static int	num_as_str_cmp(char *str1, char *str2)
{
	int		str1_len;
	int		str2_len;
	short	sign;

	sign = 1;
	if (str1[0] == '-' || str2[0] == '-')
	{
		if (str1[0] == '-' && str2[0] == '-')
			sign = -1;
		else
			return (str1[0] - str2[0]);
	}
	str1_len = len(str1);
	str2_len = len(str2);
	if (str1_len != str2_len)
		return ((str1_len - str2_len) * sign);
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((*str1 - *str2) * sign);
}

static int	ft_atoi(char *str)
{
	int		result;
	short	sign;

	result = 0;
	sign = 1;
	if (!num_as_str_cmp(str, "-2147483648"))
		return (INT_MIN);
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		result *= 10;
		result += *str++ - '0';
	}
	return (sign * result);
}

static int	is_integer(char *num)
{
	if (*num == '-')
	{
		if (num_as_str_cmp(num, "-2147483648") < 0)
			return (0);
		num++;
	}
	else if (num_as_str_cmp(num, "2147483647") > 0)
		return (0);
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (0);
		num++;
	}
	return (1);
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
	int	*args;

	if (!validate_args(nums))
		return (NULL);
	args = malloc(sizeof(int) * argc);
	if (args)
		while (argc-- > 0)
			args[argc] = ft_atoi(nums[argc]);
	return (args);
}
