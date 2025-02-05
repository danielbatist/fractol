/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:41:38 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/05 00:15:09 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	guidelines(void)
{
	ft_printf("Welcome to the fascinating world of fractals!\n");
	ft_printf("MiniLibX limitations may cause slower rendering.\n");
	ft_printf("We hope you enjoy the experience. 😊\n");
	ft_printf("To move:	Press keys: W, A, S, D or Left, Right, Up, Down ar\n");
	ft_printf("To zoom in:		Scroll mouse wheel up\n");
	ft_printf("To zoom out:		Scroll mouse wheel down\n");
	ft_printf("To switch colours:	Press: Space bar\n");
	ft_printf("To increase iterations:	Press key: + (from the number pad)\n");
	ft_printf("To decrease iterations:	Press key: -\n");
	ft_printf("To rotate Julia:	Mouse left or right click\n");
	ft_printf("To quit:	Press: ESC or click X on window, or Ctrl + c \n");
	ft_printf("Try: <./fractal julia -0.4 +0.6> or ");
	ft_printf("<./fractol julia -0.835 -0.2321>\n");
	ft_printf("WARNING: Resizing or maximizing the window will ");
	ft_printf("transport you to the dreaded black abyss!\n");
}

double	ft_atod(char *str)
{
	int		sign;
	int		dot; 
	long	whole;
	double	dec;
	double	power;

	sign = 1;
	dot = 0;
	whole = 0;
	dec = 0.0;
	power = 1.0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		str++;
		if (*str == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
		whole = (whole * 10) + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		dot = 1;
		while (*str >= '0' && *str <= '9')
		{
			dec = (dec * 10) + (*str++ - '0');
			power *= 10;
			str++;
		}
	}
	if (dot)
		return (sign * (whole + (dec / power)));
	else
		return (sign * whole);
}

double	map(double u_num, double o_min, double o_max)
{
	return (-2 + ((u_num - o_min) / (o_max - o_min)) * 4);
}
