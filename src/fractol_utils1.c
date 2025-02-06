/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:41:38 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/05 21:14:15 by dbatista         ###   ########.fr       */
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

double	map(t_map coords)
{
	return (coords.new_min + ((coords.u_num - coords.old_min) / (coords.old_max - coords.old_min)) * (coords.new_max - coords.new_min));
}

void	zoom_in(t_fractol *frac, double mouse_r, double mouse_i)
{
	double	z_factor;

	(void)mouse_i;
	(void)mouse_r;
	z_factor = 0.90;

	frac->shift_r = (frac->shift_r - mouse_r) * z_factor + mouse_r;
	frac->shift_i = (frac->shift_i - mouse_i) * z_factor + mouse_i;
	frac->zoom *= z_factor;
	printf("%f, %f - zoom in pos mouse r e i: \n", frac->shift_r, frac->shift_i);
	printf("%f\n", frac->zoom);
}

void	zoom_out(t_fractol *frac, double mouse_r, double mouse_i)
{
	double	z_factor;

	(void)mouse_i;
	(void)mouse_r;
	z_factor = 1.12;

	frac->shift_r = (frac->shift_r - mouse_r) * z_factor + mouse_r;
	frac->shift_i = (frac->shift_i - mouse_i) * z_factor + mouse_i;
	frac->zoom *= z_factor;
	printf("%f, %f - zoom in pos mouse r e i: \n", frac->shift_r, frac->shift_i);
	printf("%f\n", frac->zoom);
}
