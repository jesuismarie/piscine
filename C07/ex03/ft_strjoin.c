/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:45:00 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/20 18:09:30 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	mlen(int size, char **strs)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}	
		i++;
	}
	return (len);
}

char	*check(void)
{
	char	*s;

	s = malloc(1);
	*s = '\0';
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		z;
	int		len;
	char	*ptr;

	if (size == 0)
		return (check());
	len = ((size - 1) * ft_strlen(sep)) + mlen(size, strs);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			ptr[k++] = strs[i][j++];
		z = 0;
		if (k < len)
		{
			while (sep[z])
				ptr[k++] = sep[z++];
		}
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}

#include <stdio.h>
int main() {
	char *a[] = {"abc", "def", "ghi", "jkl"};
	char *c = ft_strjoin(4, a, "...");
	printf("%s", c);
}
