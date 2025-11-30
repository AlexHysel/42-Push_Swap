/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:06:51 by afomin            #+#    #+#             */
/*   Updated: 2025/11/30 17:28:36 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **args)
{
	t_stack	*a;
	t_stack	*b;
	char	*err_msg;
	int		*indexes;

	args = &args[1];
	argc--;
	indexes = convert_args(args, argc);
	if (!indexes)
	{
		err_msg = "Error\n";
		while (*err_msg)
		{
			write(2, err_msg, 1);
			err_msg++;
		}
		return (-1);
	}
	a = stack_create(indexes, argc, 'a');
	b = stack_create(NULL, 0, 'b');
	push_swap(a, b);
	free(a->values);
	free(a);
	free(b->values);
	free(b);
}
