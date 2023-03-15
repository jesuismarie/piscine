/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:57:51 by tmnatsak          #+#    #+#             */
/*   Updated: 2022/10/16 17:57:55 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_get_number(int fd)
{
	int		i;
	char	c[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		return (NULL);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*ft_get_val(int fd, char *c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		return (NULL);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

void	ft_read(int fd, char *c)
{
	while (c[0] == ' ' || c[0] == '\t')
		read(fd, c, 1);
	if (c[0] == ':')
		read(fd, c, 1);
	while (c[0] == ' ')
		read(fd, c, 1);
}

int	count_lines(char *file, char *c)
{
	int	count;
	int	fd;
	int	pos;

	pos = 1;
	count = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		while (pos)
		{
			pos = read(fd, c, 1);
			if (c[0] == ':')
				count++;
		}
		break ;
	}
	close(fd);
	return (count);
}

t_list	*process(char *file)
{
	int		i;
	int		fd;
	char	c[1];
	t_list	*tab;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(t_list) * (count_lines(file, c)));
	if (fd == -1 || !tab)
		return (NULL);
	i = 0;
	while (i < count_lines(file, c) - 1)
	{
		tab[i].nb = ft_atoi(ft_get_number(fd));
		read(fd, c, 1);
		ft_read(fd, c);
		tmp = ft_get_val(fd, c);
		tab[i].val = ft_strcpy(tmp);
		free(tmp);
		i++;
	}
	close(fd);
	return (tab);
}
