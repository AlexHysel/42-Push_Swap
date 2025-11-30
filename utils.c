/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:57:47 by afomin            #+#    #+#             */
/*   Updated: 2025/11/30 16:59:43 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	log_functions(char *func, char stack_id)
{
	char	nl;

	nl = '\n';
	while (*func)
		write(1, func++, 1);
	write(1, &stack_id, 1);
	write(1, &nl, 1);
}
