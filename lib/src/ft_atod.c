/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:28:06 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/09 12:29:11 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(char **s)
{
	int	sign;

	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
		if (**s == '+' || **s == '-')
			return (0);
	}
	return (sign);
}

static void	ft_atod_process(char **s, long *i, double *frac, int *sign)
{
	double	power;

	power = 1.0;
	while (**s == ' ' || (**s >= '\t' && **s <= '\n'))
		(*s)++;
	*sign = is_negative(s);
	if (*sign == 0)
		return ;
	while (**s >= '0' && **s <= '9')
	{
		*i = (*i * 10) + (**s - '0');
		(*s)++;
	}
	if (**s == '.')
		(*s)++;
	while (**s >= '0' && **s <= '9')
	{
		power /= 10;
		*frac = *frac + ((**s - '0') * power);
		(*s)++;
	}
	return ;
}

double	ft_atod(char *s)
{
	double	fractional;
	int		sign;
	long	integral;

	integral = 0;
	fractional = 0.0;
	sign = 1;
	ft_atod_process(&s, &integral, &fractional, &sign);
	if (*s != '\0' && (*s < '0' || *s > '9') && *s != '.')
		return (0.0);
	return ((integral + fractional) * sign);
}
