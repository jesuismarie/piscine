/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:58:15 by mnazarya          #+#    #+#             */
/*   Updated: 2022/10/29 19:09:03 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sum;
	int	i;

	sum = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		sum *= i;
		i++;
	}
	return (sum);
}