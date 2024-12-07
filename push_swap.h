/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:25:59 by mzary             #+#    #+#             */
/*   Updated: 2024/12/07 02:39:03 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/Libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
}				t_stack;

t_stack	*extract_info(char *arg);
void	free_splits(char **splits);
void	extract_list(t_stack *extract, char **splits);

void	sort_stacks(int *stack_a, int *stack_b, int size);

#endif