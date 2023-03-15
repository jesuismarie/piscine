/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:03:05 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/09 20:03:17 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	compare(char *input)
{
	int		i;

	i = 0;
	while (i < 31)
	{
		if (input[i] == "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"[i])
			i++;
		else if (input[i] >= 49 && input[i] <= 52 && (i % 2 == 0))
			i++;
		else
			return (0);
	}
	return (1);
}

int	parsing(int argc, char **argv, int *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2 && ft_strlen(argv[1]) == 31 && compare(argv[1]))
	{
		while (i < 16)
		{
			res[i] = argv[1][j] - 48;
			i++;
			j += 2;
		}
		return (1);
	}
	else
		return (0);
}
