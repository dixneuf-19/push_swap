/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_info_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:00:52 by mzary             #+#    #+#             */
/*   Updated: 2024/12/07 02:32:31 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	extract_number(char *split, int *slot)
{
	int		number;
	char	*check;
	size_t	org_len;
	size_t	dup_len;

	number = ft_atoi(split);
	check = ft_itoa(number);
	if (check == NULL)
		exit(EXIT_FAILURE);
	org_len = ft_strlen(split);
	dup_len = ft_strlen(check);
	if (org_len > dup_len)
		dup_len = org_len;
	if (ft_strncmp(split, check, dup_len) == 0)
	{
		*slot = number;
		return (0);
	}
	free(check);
	return (1);
}

static void	check_duplicate(t_stack *extract)
{
	int	i;
	int	j;

	i = 0;
	while (i < extract->size)
	{
		j = i + 1;
		while (j < extract->size)
		{
			if ((extract->stack)[i] == (extract->stack[j]))
			{
				free(extract->stack);
				free(extract);
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}


void	extract_list(t_stack *extract, char **splits)
{
	int	split;

	extract->stack = (int *)malloc(sizeof(int) * extract->size);
	if (extract->stack == NULL)
	{
		free_splits(splits);
		free(extract);
		exit(EXIT_FAILURE);
	}
	split = 0;
	while (splits[split])
	{
		if (extract_number(splits[split], extract->stack + split))
		{
			free_splits(splits);
			free(extract->stack);
			free(extract);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		split++;
	}
	free_splits(splits);
	check_duplicate(extract);
}