/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:16:08 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/11 21:55:01 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				j;
	char			c;
	char			*hex;
	unsigned char	a;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (*str > 31 && *str < 127)
		{
			c = *str;
			write (1, &c, 1);
		}
		else
		{
			a = (unsigned char)*str;
			write (1, "\\", 1);
			j = a / 16;
			write (1, &hex[j], 1);
			j = a % 16;
			write (1, &hex[j], 1);
		}
		str++;
	}
}
