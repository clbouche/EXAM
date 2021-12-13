/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:39:18 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/10 12:34:12 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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

int	ft_len(unsigned int nbr, int basel)
{
	unsigned int n = nbr;
	int len = 0;

	if (n == 0)
		return (1);
	while(n)
	{
		n /= basel;
		len++;
	}
	if (nbr < 0)
		len++;
	return(len);
}

int	ft_putnbr(int nbr)
{
	int len = 0;
	unsigned int unbr = 0;

	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = -nbr;
		len++;
		len += ft_len(unbr, 10);
	}
	else
	{
		unbr = nbr;
		len += ft_len(unbr, 10);
	}
	if (unbr >= 10)
		ft_putnbr(unbr / 10);
	ft_putchar(unbr % 10 + '0');
	return (len);
}

static char	*ft_itoa_base(long unsigned int num, int basel)
{
	char *hexa;
	char *base = "0123456789abcdef";
	int len = ft_len(num, basel);
	if (!(hexa = malloc(sizeof(char) * len + 1)))
		return (NULL);
	hexa[len--] = '\0';
	while (len >= 0)
	{
		hexa[len--] = base[num % basel];
		num /= basel;
	}
	return (hexa);
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
			if (*(str + 1) == 's')
			{
				char *s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				rtn += ft_putstr(s);
				str++;
			}
			else if (*(str + 1)== 'd')
			{
				int num = va_arg(ap, int);
				rtn += ft_putnbr(num);
				str++;
			}
			else if (*(str + 1) == 'x')
			{
				unsigned int hexa = va_arg(ap, unsigned int);
				char *s = ft_itoa_base((long unsigned)hexa, 16);
				rtn += ft_putstr(s);
				free(s);
				str++;
			}
			else
				rtn += ft_putchar(*str);
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
	// char *s = NULL;

	// printf("rtn mine: [%i]   ", ft_printf("%s\n%", "Hello World!"));
	// printf("rtn printf : [%i]   ", printf("%s\n%", "Hello World!"));

	// printf("rtn mine: [%i]   ", ft_printf("%s\n", "Hello World!"));
	// printf("rtn printf : [%i]   ", printf("%s\n", "Hello World!"));
	
	// printf("rtn mine: [%i]   ", ft_printf("%", "Hello World!"));
	// printf("rtn printf : [%i]   ", printf("%", "Hello World!"));
	
	// printf("rtn mine: [%i]\n", ft_printf("%s\n", s));
	// printf("rtn printf : [%i]\n", printf("%s\n", s));

	// printf("\n\nTEST D\n");

	// printf("rtn mine:[%i]\n", ft_printf("%d\n", INT_MIN));
	// printf("rtn printf : [%i]\n", printf("%d\n", INT_MIN));

	// printf("rtn mine: [%i]\n", ft_printf("%d\n", INT_MAX));
	// printf("rtn printf : [%i]\n", printf("%d\n", INT_MAX));
	
	// printf("rtn mine: [%i]   ", ft_printf("%d\n", 42));
	// printf("rtn printf : [%i]   ", printf("%d\n", 42));
	
	// printf("rtn mine : [%i]   ", ft_printf("%d\n", -42));
	// printf("rtn print: [%i]   ", printf("%d\n", -42));
	

	// printf("\n\nTEST X\n");
	// printf("rtn mine: [%i]   ", ft_printf("%x\n", 42));
	// printf("rtn printf : [%i]   ", printf("%x\n", 42));

	// printf("rtn mine: [%i]   ", ft_printf("%x\n", -42));
	// printf("rtn printf : [%i]   ", printf("%x\n", -42));

	// printf("rtn mine: [%i]\n", ft_printf("%x\n", INT_MAX));
	// printf("rtn printf : [%i]\n", printf("%x\n", INT_MAX));

	// printf("rtn mine: [%i]\n", ft_printf("%x\n", INT_MIN));
	// printf("rtn printf : [%i]\n", printf("%x\n", INT_MIN));


	// printf("\n\nALL\n");
	// printf("rtn mine:[%i]\n", ft_printf(".%s%d%s%x.\n","en int 42 = ", 42, "en hexa 42 = ", 42));
	// printf("rtn printf : [%i]\n", printf(".%s%d%s%x.\n","en int 42 = ", 42, "en hexa 42 = ", 42));

	// printf("rtn mine: [%i]\n",printf("%s     coucou\n"));
	
	// printf("rtn mine: [%i]   ", ft_printf("%k\n", -42));
	
	return (0);
}