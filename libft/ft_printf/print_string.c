/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:44 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:23:25 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *string)
{
	int		i;

	if (string == 0)
		return (write(1, "(null)", 6));
	i = 0;
	while (string[i])
	{
		write(1, string + i, 1);
		i++;
	}
	return (i);
}
