/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:17:37 by addias            #+#    #+#             */
/*   Updated: 2025/12/20 12:17:38 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_puthex(unsigned long nb, char def);

#endif
