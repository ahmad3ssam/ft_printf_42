/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:19:55 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/17 12:45:16 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_to_hexa(unsigned int ptr, int letter, int *count)
{
	int		f;
	char	c;

	if (ptr == 0)
		return ;
	(*count)++;
	ft_convert_to_hexa(ptr / 16, letter, count);
	f = 16 * ((ptr / 16.0) - (ptr / 16));
	c = f + '0';
	if (c >= '0' && c <= '9')
		write(1, &c, 1);
	else
	{
		c += letter;
		write(1, &c, 1);
	}
}

void	check_before_con(unsigned int ptr, int letter, int *count)
{
	if (ptr == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	ft_convert_to_hexa(ptr, letter, count);
}
