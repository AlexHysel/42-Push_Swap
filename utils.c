/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:57:47 by afomin            #+#    #+#             */
/*   Updated: 2025/11/28 15:33:32 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	num_as_str_cmp(char *str1, char *str2)
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

int	is_integer(char *num)
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
