/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:06:11 by tmnatsak          #+#    #+#             */
/*   Updated: 2022/11/29 16:38:15 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_list
{
	int		nb;
	char	*val;
}		t_list;
long	ft_atoi(const char *str);
char	*ft_strcpy(char *src);
void	ft_putstr(char *str);
char	*ft_get_number(int fd);
char	*ft_get_val(int fd, char *c);
t_list	*process(char *file);

#endif
