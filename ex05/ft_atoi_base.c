/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:56:19 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 17:37:29 by alejhern         ###   ########.fr       */
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

int	char_to_int(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;
	int	i;

	result = 0;
	base_len = ft_strlen(base);
	sign = 1;
	i = 0;
	if (!check_base(base, base_len))
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		result = result * base_len + char_to_int(str[i], base);
		i++;
	}
	return (result * sign);
}
