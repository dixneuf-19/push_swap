/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:00:48 by mzary             #+#    #+#             */
/*   Updated: 2024/12/07 21:09:15 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(int *stack, int size)
{
	int	i;
	int	tmp;

	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;	
}

static void	push_stack(int *src, int *dst, int srcsize, int dstsize)
{
	int	i;
		
	rotate_stack(src, srcsize);
	i = dstsize - 1;
	while (i >= 0)
	{
		dst[i + 1] = dst[i];
		i--;
	}
	dst[0] = src[srcsize - 1];
}

void	sort_stacks(int *stack_a, int *stack_b, int size)
{
}