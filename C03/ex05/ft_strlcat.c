/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:28:18 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/15 12:40:33 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	z;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (size <= i || size == 0)
		return (j + size);
	k = 0;
	z = i;
	while (k < size - i - 1 && src[k])
	{
		dest[z] = src[k];
		z++;
		k++;
	}
	dest[z] = '\0';
	return (i + j);
}
