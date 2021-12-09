/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:39:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/09 15:03:34 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

// int	ft_countlen(long unsigned int n, int basel)
// {
// 	int i = 0;
	
// 	if (n == 0)
// 		return (1);
// 	while (n)
// 	{
// 		n /= basel;
// 		i++;
// 	}
// 	//if (n < 0)
// 	//	i++;
// 	return (i);
// }

static int ft_count(long unsigned int n, int base)
{
	int i;
	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

// void	ft_putnbr(int nbr)
// {
// 	if (nbr < 0)
// 	{
// 		ft_putchar('-');
// 		nbr *= -1;
// 	}
// 	if (nbr >= 10)
// 		ft_putnbr (nbr / 10);
// 	ft_putchar((nbr % 10 + '0'));
// }

void ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if(n > 9)
	{
		ft_putnbr(n /10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	//printf("ret putnbr =================%i\n", ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	int rtn = 0;
	char *str = (char *)fmt;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				rtn += ft_putchar('%');
			else if (*str == 's')
			{
				char *s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				rtn += ft_putstr(s);
			}
			else if (*str == 'd')
			{
				int num = va_arg(ap, int);
				rtn += ft_putnbr(num);
			}
			// if (*str == 'x')
			// {
			// 	int hexa = va_arg(ap, long unsigned int);
			// }
			
		}
		else
			rtn += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (rtn);
}

int main(void)
{
	// printf("TEST S\n");
	// printf("rtn mine: [%i]   ", ft_printf("%s\n", "Hello World!"));
	// printf("rtn printf : [%i]   ", printf("%s\n", "Hello World!"));

	// printf("\n\nTEST D\n");
	// printf("rtn mine: [%i]   ", ft_printf("%d\n", 42));
	// printf("rtn printf : [%i]   ", printf("%d\n", 42));
	
	printf("rtn mine : [%i]   ", ft_printf("%", -42));
	printf("rtn print: [%i]   ", printf("%d\n", -42));
	
	// printf("rtn mine: [%i]   ", ft_printf("%d\n", 2147483647));
	// printf("rtn printf : [%i]   ", printf("%d\n", 2147483647));
	
	// printf("rtn mine: [%i]   ", ft_printf("%d\n", -2147483648));
	// printf("rtn printf : [%i]   ", printf("%ld\n", -21474836487));	

	// printf("\n\nTEST X\n");
	// printf("rtn mine: [%i]   ", ft_printf("%x\n", 42));
	// printf("rtn printf : [%i]   ", printf("%x\n", 42));
	return (0);
}