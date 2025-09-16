// Online C compiler to run C program online
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}


void    ft_putstr(char *s)
{
    write(1, s, strlen(s));
   
}


void	print_it(long n)
{
	char	c;

	if (n == 0)
		return ;
	print_it(n / 10);
	c = ('0' + (n % 10));
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	print_it(n);
}

void	ft_putunbr(long n)
{
	if (n < 0)
	{
		n = 4294967296 + n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	print_it(n);
}


void	ft_putadd(void *p)
{
    uintptr_t addr = (uintptr_t)p;
    
    printf("%lx",addr);
}


int     ft_print_it(char c,va_list args)
{
    va_list copy;
    va_copy(copy,args);

    if(c == 'c')
    {
        ft_putchar(va_arg(copy, int));
    }
    else if(c == 's')
    {
        char *p = va_arg(copy, char *);
        // printf("hi\n%s",va_arg(arg, void *));
        ft_putstr(p);
    }
    else if(c == 'd')
    {
        int i = va_arg(copy, int);
        ft_putnbr(i);    
    }
    else if(c == 'i')
        ft_putnbr(va_arg(copy, int));
    else if(c == 'u')
        ft_putunbr(va_arg(copy, int));
    else if(c == 'p')
        ft_putadd(va_arg(copy, void *));
    va_end(copy);
    
    return 1;
}



int ft_printf(const char *c, ...)
{
    va_list args;
    va_start(args,c);
    if(!args)
        return(0);
    int i;
    
    i = 0;
    while(c[i])
    {
        if(c[i] != '%')
            ft_putchar(c[i]);
        else if(c[i] == '%')
            i += ft_print_it(c[i + 1], args);
        i++;
    }
    va_end(args);
}


int main() {
    // Write C code here
    int p=1;
    ft_printf("%d  %s",100,"ahmad");
    
    //printf("Try programiz.pro %c %s %d %u\n %p",'a',"ahmad",100,-2147483648,&p);
    // printf("Try programiz.pro %c %s",NULL,NULL);

    return 0;
}