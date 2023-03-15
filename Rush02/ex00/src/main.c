/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:03:49 by tmnatsak          #+#    #+#             */
/*   Updated: 2022/10/20 11:11:11 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	get_decimal(int nb)
{
	if (nb >= 20 && nb < 30)
		return (20);
	else if (nb >= 30 && nb < 40)
		return (30);
	else if (nb >= 40 && nb < 50)
		return (40);
	else if (nb >= 50 && nb < 60)
		return (50);
	else if (nb >= 60 && nb < 70)
		return (60);
	else if (nb >= 70 && nb < 80)
		return (70);
	else if (nb >= 80 && nb < 90)
		return (90);
	else if (nb >= 90 && nb < 100)
		return (90);
	else if (nb < 20)
		return (nb);
	return (0);
}

int	get_multiply(int nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	return (get_decimal(nb));
}

void	nbr_display(int num, t_list *dict, int *a)
{
	int	i;
	int	m;

	i = 0;
	m = get_multiply(num);
	if (m >= 100)
		nbr_display(num / m, dict, a);
	if (*a == 0)
		write(1, " ", 1);
	*a = 0;
	while (dict[i].nb != m)
		i++;
	ft_putstr(dict[i].val);
	if (m != 0 && num % m != 0)
		nbr_display(num % m, dict, a);
}

int	check(int argc, char **argv)
{
	int	i;
	int	this;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	this = 1;
	i = 0;
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 3)
	{
		this = 2;
		if (fd == -1)
			return (0);
	}	
	while (argv[this][i] != '\0')
	{
		if (argv[this][i] < 48 || argv[this][i] > 57)
			return (0);
		i++;
	}
	if (ft_atoi(argv[this]) > 999999999)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*tab;
	int		*ptrfirst;
	int		first;

	first = 1;
	ptrfirst = &first;
	if (argc < 2 || argc > 3)
		return (0);
	if (!check(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		tab = process("numbers.dict");
		nbr_display(ft_atoi(argv[1]), tab, ptrfirst);
	}
	else
	{
		tab = process(argv[1]);
		nbr_display(ft_atoi(argv[2]), tab, ptrfirst);
	}
}
