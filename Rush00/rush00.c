/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:56:26 by oeloyan           #+#    #+#             */
/*   Updated: 2022/10/01 16:16:25 by oeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush00(int a, int b, int i, int j)
{
	if ((i == 0 && j == 0) || (i == b - 1 && j == 0)
		|| (i == 0 && j == a - 1) || (i == b - 1 && j == a - 1))
	{
		ft_putchar ('o');
	}
	else if ((i == 0 && j != 0 && j != a - 1)
		|| (i == b - 1 && j != 0 && j != a - 1))
	{
		ft_putchar ('-');
	}
	else if ((j == 0 && i != 0 && j != b - 1)
		|| (j == a - 1 && i != 0 && i != b - 1))
	{
		ft_putchar ('|');
	}
	else
	{
		ft_putchar (' ');
	}
}

void	rush(int a, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			rush00 (a, b, i, j);
			j++;
		}
		i++;
		ft_putchar ('\n');
	}
}
