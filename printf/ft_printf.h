/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerthof <vgerthof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:16:48 by bgix              #+#    #+#             */
/*   Updated: 2026/01/10 13:35:53 by vgerthof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>  // print_f
# include <stdlib.h> // malloc
# include <stdarg.h> // va_
# include <unistd.h> // write
# include <stdbool.h> // BALLEAN

void	ft_printf_void(int *length, va_list lst);
void	ft_printf_base(int *length, va_list lst, char *baka_base, bool is_maj);
void	ft_printf_undec(int *length, va_list lst);
void	ft_printf_char(int *length, va_list lst);
void	ft_printf_str(int *length, va_list lst);
void	ft_printf_dec(int *length, va_list lst);
int		ft_strlen(char *s);

#endif