/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:41:58 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/05 00:17:41 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_mouse_move(int but, int x, int y, t_fractol *f)
{
	if (but == Button1 || but == Button3)
	{
		f->julia_r = (map(x, 0, WID) * f->zoom) + f->shift_r;
		f->julia_i = (map(y, 0, HEI) * f->zoom) + f->shift_i;
		fractol_render(f);
	}
	return (0);
}

int	exit_clear(t_fractol *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	mlx_destroy_window(frac->mlx, frac->window);
	mlx_destroy_display(frac->mlx);
	free(frac->mlx);
	exit(1);
}

int	key_handle(int key, t_fractol *frac)
{
	if (key == XK_Escape)
		exit_clear(frac);
	else if (key == XK_Left || key == XK_a)
		frac->shift_r += (0.1 * frac->zoom);
	else if (key == XK_Right || key == XK_d)
		frac->shift_r -= (0.1 * frac->zoom);
	else if (key == XK_Up || key == XK_w)
		frac->shift_i -= (0.1 * frac->zoom);
	else if (key == XK_Down || key == XK_s)
		frac->shift_i += (0.1 * frac->zoom);
	else if (key == XK_KP_Add)
		frac->iter += 30;
	else if (key == XK_KP_Subtract)
		frac->iter -= 30;
	else if (key == XK_space)
		colours_change(frac);
	fractol_render(frac);
	return (0);
}

int	mouse_handle(int but, int x, int y	, t_fractol *frac)
{
	double		z_factor;
	t_fractol	z_map;

	z_map.map_x = map(x, -WID / 2, WID / 2);
	z_map.map_y = map(y, -HEI / 2, HEI / 2);
	z_factor = 1.0;
	if (ft_strncmp(frac->title, "Julia", 5) == 0)
		julia_mouse_move(but, x, y, frac);
	else if (but == Button4)
	{
		z_factor = 1.5;
		frac->iter++;
		frac->zoom *= z_factor;
	}
	else if (but == Button5)
	{
		frac->iter--;
		z_factor = 0.7;
		frac->zoom *= z_factor;
		frac->shift_r += (z_map.map_x / (WID / 2)) * frac->zoom;
		frac->shift_i += (z_map.map_y / (WID / 2)) * frac->zoom;
	}
	fractol_render(frac);
	return (0);
}
