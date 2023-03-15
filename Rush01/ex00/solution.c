/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:08:39 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:42 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		check_col_down(int map[4][4], int current, int input[16]);
int		check_row_left(int map[4][4], int current, int input[16]);
int		check_row_right(int map[4][4], int current, int input[16]);
int		check_col_up(int map[4][4], int current, int input[16]);
int		check_neighbours(int map[4][4], int current, int height);

int	check(int map[4][4], int current, int input[16])
{
	if (check_row_left(map, current, input) == 0)
		return (0);
	if (check_row_right(map, current, input) == 0)
		return (0);
	if (check_col_down(map, current, input) == 0)
		return (0);
	if (check_col_up(map, current, input) == 0)
		return (0);
	return (1);
}

void	display(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	solve(int map[4][4], int input[16], int current)
{
	int	height;

	if (current == 16)
		return (1);
	height = 0;
	while (++height <= 4)
	{
		if (check_neighbours(map, current, height))
		{
			map[current / 4][current % 4] = height;
			if (check(map, current, input))
			{
				if (solve(map, input, current + 1))
					return (1);
			}
			else
				map[current / 4][current % 4] = 0;
		}
	}
	return (0);
}
