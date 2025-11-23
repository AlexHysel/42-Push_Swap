/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:57:47 by afomin            #+#    #+#             */
/*   Updated: 2025/11/23 18:48:33 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

int	erase_max(char **nums)
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
