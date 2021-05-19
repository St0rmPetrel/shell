/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 00:48:11 by prautha           #+#    #+#             */
/*   Updated: 2021/04/14 12:16:03 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_quantity_chr(long n)
{
	int		i;
	long	m;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	m = 1;
	while (--i)
		m *= 10;
	return (m);
}

static void	ft_output(long q, long m, int fd)
{
	long	m_tmp;

	while (q > 1)
	{
		m_tmp = m / q;
		ft_putchar_fd(m_tmp + 48, fd);
		m -= m_tmp * q;
		q /= 10;
	}
	ft_putchar_fd((m % 10) + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	m;
	long	q;

	m = (long)n;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	q = ft_quantity_chr(m);
	ft_output(q, m, fd);
}
