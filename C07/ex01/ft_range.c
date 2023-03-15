/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:17 by mnazarya          #+#    #+#             */
/*   Updated: 2022/11/26 16:20:59 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_abs(int n)
{
	if(n<0)
		n=-n;
	return (n);
}
int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	i = 0;
	ptr = (int *)malloc(sizeof(int)*ft_abs(min-max));
	if (!ptr)
		return (0);
	while (min > max)//4,2
	{
		ptr[i] = min;
		min--;
		i++;
	}
	ptr[i]=min;
	while (min < max)//2,5
	{
		ptr[i] = min;
		min++;
		i++;
	}
	ptr[i]=min;
	return (ptr);
}
