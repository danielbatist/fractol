/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:41:38 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/09 12:31:14 by dbatista         ###   ########.fr       */
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

double	map(t_map coords)
{
	return (coords.new_min \
		+ ((coords.u_num - coords.old_min) \
		/ (coords.old_max - coords.old_min)) \
		* (coords.new_max - coords.new_min));
}

void	zoom_in(t_fractol *frac, double mouse_r, double mouse_i)
{
	double	z_factor;

	z_factor = 0.80 - (frac->zoom * 0.05);
	if (z_factor < 0.80)
		z_factor = 0.80;
	frac->shift_r = frac->shift_r * z_factor + mouse_r * (1 - z_factor);
	frac->shift_i = frac->shift_i * z_factor + mouse_i * (1 - z_factor);
	frac->zoom *= z_factor;
}

void	zoom_out(t_fractol *frac, double mouse_r, double mouse_i)
{
	double	z_factor;

	z_factor = 1.0 + (frac->zoom * 0.05);
	if (z_factor < 1.20)
		z_factor = 1.20;
	frac->shift_r = frac->shift_r * z_factor + mouse_r * (1 - z_factor);
	frac->shift_i = frac->shift_i * z_factor + mouse_i * (1 - z_factor);
	frac->zoom *= z_factor;
}
