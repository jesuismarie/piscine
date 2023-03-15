/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:03:26 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/09 20:03:30 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nb);

int	check_neighbours(int map[4][4], int current, int height)
{
	int	i;

	i = -1;
	while (++i < current / 4)
		if (map[i][current % 4] == height)
			return (0);
	i = -1;
	while (++i < current % 4)
		if (map[current / 4][i] == height)
			return (0);
	return (1);
}

int	check_row_left(int map[4][4], int current, int input[16])
{
	int	i;
	int	max_height;
	int	visible_towers;

	i = -1;
	max_height = 0;
	visible_towers = 0;
	if (current % 4 == 3)
	{
		while (++i < 4)
		{
			if (map[current / 4][i] > max_height)
			{
				max_height = map[current / 4][i];
				visible_towers++;
			}
		}
		if (input[8 + current / 4] != visible_towers)
			return (0);
	}
	return (1);
}

int	check_row_right(int map[4][4], int current, int input[16])
{
	int	i;
	int	max_height;
	int	visible_towers;

	i = 4;
	max_height = 0;
	visible_towers = 0;
	if (current % 4 == 3)
	{
		while (--i >= 0)
		{
			if (map[current / 4][i] > max_height)
			{
				max_height = map[current / 4][i];
				visible_towers++;
			}
		}
		if (input[12 + current / 4] != visible_towers)
			return (0);
	}
	return (1);
}

int	check_col_down(int map[4][4], int current, int input[16])
{
	int	i;
	int	max_height;
	int	visible_towers;

	i = 4;
	max_height = 0;
	visible_towers = 0;
	if (current / 4 == 3)
	{
		while (--i >= 0)
		{
			if (map[i][current % 4] > max_height)
			{
				max_height = map[i][current % 4];
				visible_towers++;
			}
		}
		if (input[4 + current % 4] != visible_towers)
			return (0);
	}
	return (1);
}

int	check_col_up(int map[4][4], int current, int input[16])
{
	int	i;
	int	max_height;
	int	visible_towers;

	i = -1;
	max_height = 0;
	visible_towers = 0;
	if (current / 4 == 3)
	{
		while (++i < 4)
		{
			if (map[i][current % 4] > max_height)
			{
				max_height = map[i][current % 4];
				visible_towers++;
			}
		}
		if (input[current % 4] != visible_towers)
			return (0);
	}
	return (1);
}
