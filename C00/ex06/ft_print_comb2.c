/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:53:20 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/01 20:46:52 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_char(char a, char b)
{
	char	x;

	x = a / 10 + '0';
	write (1, &x, 1);
	x = a % 10 + '0';
	write(1, &x, 1);
	write(1, " ", 1);
	x = b / 10 + '0';
	write (1, &x, 1);
	x = b % 10 + '0';
	write(1, &x, 1);
	if (a != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			convert_char(a, b);
			b++;
		}
		a++;
	}
}
