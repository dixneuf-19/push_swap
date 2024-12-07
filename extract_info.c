/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:25:08 by mzary             #+#    #+#             */
/*   Updated: 2024/12/07 01:51:43 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_splits(char **splits)
{
	int	size;

	size = 0;
	while (splits[size])
		size++;
	return (size);
}

void	free_splits(char **splits)
{
		int	split;

		split = 0;
		while (splits[split])
		{
			free(splits[split]);
			split++;
		}
		free(splits);
}

t_stack	*extract_info(char *arg)
{
	char	**splits;
	t_stack	*extract;

	splits = ft_split(arg, ' ');
	if (splits == NULL)
		exit(EXIT_FAILURE);
	if (splits[0] == NULL)
	{
		free(splits);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	extract = (t_stack *)malloc(sizeof(t_stack));
	if (extract == NULL)
		exit(EXIT_FAILURE);
	extract->size = count_splits(splits);
	extract_list(extract, splits);
	return (extract);
}
