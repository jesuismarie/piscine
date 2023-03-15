/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:26:09 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/19 15:28:51 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	n;
	int	i;

	n = max - min;
	i = 0;
	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = (int *)malloc(n * sizeof(int));
	if (!range)
		return (-1);
	while (i < n)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (i);
}
