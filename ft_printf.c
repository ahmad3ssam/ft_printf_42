/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:39:52 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/17 12:45:25 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print/ft_printf.h"

int	ft_print_it(char c, va_list args, int *count)
{
	if (c == 'c')
		(*count) += ft_putchar(va_arg(args, int));
	else if (c == 's')
		(*count) += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		(*count) += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		(*count) += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		(*count) += ft_putunbr(va_arg(args, int));
	else if (c == 'p')
		(*count) += ft_putaddr(va_arg(args, void *));
	else if (c == 'x')
		check_before_con((long)va_arg(args, long), 39, count);
	else if (c == 'X')
		check_before_con((long)va_arg(args, long), 7, count);
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	return (1);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, c);
	i = 0;
	count = 0;
	while (c[i])
	{
		if (c[i] != '%')
		{
			count += ft_putchar(c[i]);
		}
		else if (c[i] == '%')
			i += ft_print_it(c[i + 1], args, &count);
		i++;
	}
	va_end(args);
	return (count);
}
// #include <limits.h>

// int	main(void)
// {
// 	int		i;
// 	char	*p;

// 	// Write C code here
// 	p = malloc(2);
// 	p[0] = '1';
// 	p[1] = '\0';
// 	// // ft_printf("%d  %s %c %p",100,"aahmad",'a',&p);
// 	// ft_printf("%c %s %d %u\n %p  %% \n",'a',"ahmad",100,-214748348,&p);
// 	// printf("\n%c %s %d %u\n %p %% \n",'a',"ahmad",100,-214748348,&p);
// 	int j;
// 	j = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c %% %s %% %d %% %i %% %u %% %x %% %X %% %% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 , 0, 42, 0);
// 	i = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c %% %s %% %d %% %i %% %u %% %x %% %X %% %% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 , 0, 42, 0);
// 	// uintptr_t addr = (uintptr_t)p;
// 	printf("ft_pr %d\n prin %d \n",j, i);
// 	// printf("\n\n%ld",(uintptr_t)p);
// 	return (0);
// }