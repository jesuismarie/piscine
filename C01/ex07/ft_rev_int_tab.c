/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:18:25 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/04 16:02:59 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size) / 2)
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = temp;
		i++;
	}
}
