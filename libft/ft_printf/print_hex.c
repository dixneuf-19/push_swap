/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:26:34 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:37:11 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_shex(unsigned int hex, int *p_count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (hex < 16)
		*p_count += write(1, tab + hex, 1);
	else
	{
		print_shex(hex / 16, p_count);
		*p_count += write(1, tab + (hex % 16), 1);
	}
}

static void	print_bhex(unsigned int hex, int *p_count)
{
	char	*tab;

	tab = "0123456789ABCDEF";
	if (hex < 16)
		*p_count += write(1, tab + hex, 1);
	else
	{
		print_bhex(hex / 16, p_count);
		*p_count += write(1, tab + (hex % 16), 1);
	}
}

int	print_hex(unsigned int hex, char size)
{
	int				count;

	count = 0;
	if (size == 'x')
		print_shex(hex, &count);
	else
		print_bhex(hex, &count);
	return (count);
}
