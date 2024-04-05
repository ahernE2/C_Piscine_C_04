/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:03:29 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/05 10:08:36 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_base(char *base, int base_len)
{
	int	pos;
	int	pos_tmp;

	pos = 0;
	if (base_len < 2)
		return (0);
	while (base[pos])
	{
		pos_tmp = pos + 1;
		if (base[pos] == '+' || base[pos] == '-')
			return (0);
		while (base [pos_tmp])
		{
			if (base[pos] == base[pos_tmp])
				return (0);
			pos_tmp++;
		}
		pos++;
	}
	return (1);
}

void	ft_print_putnbr_base(long nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= base_len)
		ft_print_putnbr_base(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (check_base(base, base_len))
		ft_print_putnbr_base((long)nbr, base, base_len);
}
