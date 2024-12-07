/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:13:35 by mzary             #+#    #+#             */
/*   Updated: 2024/11/16 09:13:53 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	print_arg(char opt, va_list ap, const char **p_format);
int	print_string(char *string);
int	print_pointer(void *pointer);
int	print_signed(int integer);
int	print_unsigned(unsigned int uinteger);
int	print_hex(unsigned int hex, char size);

#endif
