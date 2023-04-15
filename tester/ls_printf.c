/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:18:31 by anboisve          #+#    #+#             */
/*   Updated: 2023/04/15 18:42:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sm_ft.h"

static int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	size_int(int long nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static int	ft_putnbr_fd(int n, int fd)
{
	int	size;

	size = size_int(n);
	if (n == -2147483648)
		sm_putstr("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
	return (size);
}

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static int	ft_size_of_unb(unsigned long long nb, int base)
{
	int	size;

	size = 0;
	while (nb)
	{
		size++;
		nb /= base;
	}
	return (size);
}

static char	*ft_ulltoa(unsigned long long nb, int base)
{
	char		*result;
	int			i;

	i = ft_size_of_unb(nb, base);
	if (nb == 0)
		i++;
	result = sm_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i--)
	{
		result[i] = HEX_TABLE[nb % base];
		nb /= base;
	}
	return (result);
}

static int	ft_put_u(unsigned int nb, int fd)
{
	int		size;
	char	*tmp;

	tmp = ft_ulltoa(nb, 10);
	size = sm_putstr(tmp, fd);
	sm_free(tmp);
	return (size);
}

static int	ft_put_p(unsigned long p, int fd)
{
	char	*tmp;
	int		size;

	size = sm_putstr("0x", fd);
	tmp = ft_ulltoa((unsigned long)p, 16);
	size += sm_putstr(tmp, fd);
	if (tmp)
		sm_free(tmp);
	return (size);
}

static int	ft_put_hex(unsigned int nb, char maj, int fd)
{
	int		size;
	char	*tmp;

	tmp = ft_ulltoa(nb, 16);
	size = sm_strlen(tmp) + 1;
	if (maj == 'X')
		while (size--)
			tmp[size] = ft_toupper(tmp[size]);
	size = sm_putstr(tmp,fd);
	sm_free(tmp);
	return (size);
}

static int	ft_print_select(va_list list, char c, int fd)
{
	char	*s;
	int		len;

	if (c == 's' || c == 'S')
	{
		s = va_arg(list, char *);
		if (!s)
			return (sm_putstr("(null)",fd));
		len = sm_putstr(s, fd);
		if (c == 'S')
			sm_free(s);
		return (len);
	}
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(list, int),fd));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int),fd));
	else if (c == 'p')
		return (ft_put_p(va_arg(list, unsigned long), fd));
	else if (c == '%')
		return (ft_putchar_fd('%',fd));
	else if (c == 'x' || c == 'X')
		return (ft_put_hex(va_arg(list, unsigned int), c, fd));
	else if (c == 'u')
		return (ft_put_u(va_arg(list, unsigned int), fd));
	return (0);
}

int	ls_printf(int fd, const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		total;

	total = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			total += ft_putchar_fd(str[i], fd);
		else
		{
			if (str[++i] == 0)
				continue ;
			total += ft_print_select(arg, str[i], fd);
		}
		i++;
	}
	va_end(arg);
	return (total);
}