/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:33:39 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/15 12:39:33 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*c;
	unsigned int	i;

	i = 0;
	c = dest;
	while (*c)
		c++;
	while (*src && i < nb)
	{
		*c = *src;
		c++;
		i++;
		src++;
	}
	*c = '\0';
	return (dest);
}
