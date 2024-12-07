/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:26:01 by mzary             #+#    #+#             */
/*   Updated: 2024/12/07 06:18:50 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*extract;
	int		*stack_a;
	int		*stack_b;
	int		size;

	if (ac != 2)
		exit(EXIT_FAILURE);
	extract = extract_info(av[1]);
	stack_a = extract->stack;
	size = extract->size;
	stack_b = (int *)malloc(sizeof(int) * size);
	if (stack_b == NULL)
	{
		free(extract);
		exit(EXIT_FAILURE);
	}
	sort_stacks(stack_a, stack_b, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", stack_a[i]);
	}
	free(stack_a);
	free(extract);
	free(stack_b);
	exit(EXIT_SUCCESS);
}
