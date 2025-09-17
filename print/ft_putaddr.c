/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:20:34 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/17 13:06:09 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *p)
{
	int			count;
	uintptr_t	addr;

	if (!p)
    {
        ft_putstr("(nil)");
        return (5); // length of "(nil)"
    }
	addr = (uintptr_t)p;
	count = 2;
	write(1, "0x", 2);
	ft_convert_to_hexa((uintptr_t)p, 39, &count);
	return (count);
}
