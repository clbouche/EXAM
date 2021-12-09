#include "unistd.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdio.h"
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
static char *ft_itoa_base(long unsigned int n, int seize)
{
	char *hexa;
	char *base = "0123456789abcdef";
	int len;
	hexa = NULL;
	len = ft_count(n, seize);
	if (!(hexa = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	hexa[len--] = '\0';
	while (len >= 0)
	{
		printf("n =  %lu\n", n);
		hexa[len--] = base[n % seize];
		printf("hexa == %c\n", base[n % seize]);
		n /= seize;
	}
	return (hexa);
}
static int ft_putchar(char c)
{
	write(1, &c,1);
	return (1);
}
static int	ft_putstr(char *str)
{
	int i;
	int ret;
	ret = 0;
	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
		ret++;
	}
	return (ret);
}
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
int ft_printf(const char *format, ...)
{
	va_list ap;
	char *str = (char *)format;
	int ret = 0;
	
	va_start(ap, format);
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			if	(*str == '%')
				ret += ft_putchar('%');
			else if (*str == 'c')
			{
				char c = va_arg(ap, int);
				ret += ft_putchar(c);
			}
			else if (*str == 's')
			{
				char *s = va_arg(ap, char *);
				ret += ft_putstr(s);
			}
			else if (*str == 'i')
			{
				int n = va_arg(ap, int);
				ret += ft_count(n, 10);
				ft_putnbr(n);
			}
			else if (*str == 'x')
			{
				char *s;
				unsigned int x = va_arg(ap, unsigned int);
				s = ft_itoa_base((long unsigned)x, 16);
				ret += ft_putstr(s);
				free(s);
			}
		}
		else
			ret += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (ret);
}
int main()
{
	// printf("ret == %i\n", ft_printf("coucou\n"));
	// printf("printf == %i\n", printf("coucou\n"));
	// printf("hexa == %i\n", ft_printf("%x\n", 42));
	// printf("Xprintf == %i\n", printf("%x\n", 42));
	// printf("int == %i\n", ft_printf("%i\n", -42));
	// printf("Iprintf == %i\n", printf("%i\n", -42));
	// printf("string == %i\n", ft_printf("%s\n", "salut"));
	// printf("Sprintf == %i\n", printf("%s\n", "salut"));
	// printf("char == %i\n", ft_printf("%c\n", 's'));
	// printf("Cprintf == %i\n", printf("%c\n", 's'));
	// printf("monprintf == %i\n", ft_printf("%c  %s%i%s%x\n", 's',"en int 42 =", 42, "en hexa 42 =", 42));
	// printf("VraIprintf == %i\n", printf("%c  %s%i%s%x\n", 's',"en int 42 =", 42, "en hexa 42 =", 42));
	// printf("rtn mine : [%i]   ", ft_printf("%d\n", -42));
	// printf("rtn print: [%i]   ", printf("%d\n", -42));
	// printf("rtn mine : [%i]   ", ft_printf("%", 45));
	printf("rtn print: [%i]   ", ft_printf("%k\n", 45));
}