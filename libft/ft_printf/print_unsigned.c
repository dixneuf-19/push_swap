/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:59 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:37:22 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_uint(unsigned int uint, int *p_count)
{
	char	*digit;

	digit = "0123456789";
	if (uint < 10)
		*p_count += write(1, digit + uint, 1);
	else
	{
		print_uint(uint / 10, p_count);
		*p_count += write(1, digit + (uint % 10), 1);
	}
}

int	print_unsigned(unsigned int uinteger)
{
	int				count;

	count = 0;
	print_uint(uinteger, &count);
	return (count);
}
