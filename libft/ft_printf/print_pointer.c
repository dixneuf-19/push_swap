/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:10 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:37:18 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pointerhex(size_t hex, int *p_count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (hex < 16)
		*p_count += write(1, tab + hex, 1);
	else
	{
		print_pointerhex(hex / 16, p_count);
		*p_count += write(1, tab + (hex % 16), 1);
	}
}

int	print_pointer(void *pointer)
{
	int				count;

	count = write(1, "0x", 2);
	print_pointerhex((size_t)pointer, &count);
	return (count);
}
