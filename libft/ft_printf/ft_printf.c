/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:11:47 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:36:58 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total;
	va_list	ap;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			total += write(1, format, 1);
		else
			total += print_arg(*(format + 1), ap, &format);
		format++;
	}
	return (va_end(ap), total);
}
