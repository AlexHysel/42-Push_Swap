/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <alexhysel@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:32:42 by afomin            #+#    #+#             */
/*   Updated: 2025/11/24 15:33:26 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int		*values;
	int		size;
}				t_stack;

void	push_swap(t_stack *a, t_stack *b);

//Stack
t_stack	*stack_create(int *values, int size);
void	stack_r(t_stack *stack, char *log);
void	stack_p(t_stack *from, t_stack *to, char *log);

//Utils
void	printstr(char *str);
void	swap(int *a, int *b);
int		erase_max(char **nums);

#endif
