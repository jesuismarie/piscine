/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:02:49 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/09 20:02:55 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		parsing(int argc, char **argv, int *res);
int		solve(int map[4][4], int input[16], int current);
void	display(int tab[4][4]);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	res[16];
	int	map[4][4];

	if (parsing(argc, argv, res))
	{
		if (solve(map, res, 0))
			display(map);
		else
			ft_putstr("Didn't find any solution");
	}
	return (0);
}
