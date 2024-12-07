/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:00 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:36:42 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char opt, va_list ap, const char **p_format)
{
	unsigned char	character;

	if (opt == 'c')
	{
		character = (unsigned char)va_arg(ap, int);
		return (*p_format += 1, write(1, &character, 1));
	}
	if (opt == 's')
		return (*p_format += 1, print_string(va_arg(ap, char *)));
	if (opt == 'p')
		return (*p_format += 1, print_pointer(va_arg(ap, void *)));
	if (opt == 'd' || opt == 'i')
		return (*p_format += 1, print_signed(va_arg(ap, int)));
	if (opt == 'u')
		return (*p_format += 1, print_unsigned(va_arg(ap, unsigned int)));
	if (opt == 'x' || opt == 'X')
		return (*p_format += 1, print_hex(va_arg(ap, unsigned int), opt));
	if (opt == '%')
		return (*p_format += 1, write(1, "%", 1));
	return (0);
}
