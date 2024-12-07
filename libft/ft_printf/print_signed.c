/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:12:24 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:32:44 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_signed(int integer)
{
	if (integer == -2147483648)
		return (write(1, "-2147483648", 11));
	if (integer < 0)
		return (write(1, "-", 1) + print_unsigned(-integer));
	return (print_unsigned(integer));
}
