/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:41:58 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/05 21:19:32 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_mouse_move(int but, int x, int y, t_fractol *f)
{
	if (but == Button1 || but == Button3)
	{
		f->julia_r = (map((t_map){x, 0, WID, -2, 2}) * f->zoom) + f->shift_r;
		f->julia_i = (map((t_map){y, 0, WID, 2, -2}) * f->zoom) + f->shift_i;
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
	double		mouse_r;
	double		mouse_i;
	double		old_cpx_x;
	double 		old_cpx_y;
	double		new_cpx_x;
	double 		new_cpx_y;

	printf("%i, %i - coordenada do pixel:\n", x, y);

	old_cpx_x = -2.0 + ((((double)x) / WID) * 4.0) * frac->zoom + frac->shift_r;
	old_cpx_y = 2.0 + ((((double)y) / HEI) * 4.0) * frac->zoom + frac->shift_i;
	printf("%f, %f coordenadas do cpx antes: \n", old_cpx_x, old_cpx_y);


	mouse_r = (x - WID / 2) / (0.5 * WID * frac->zoom) + frac->shift_r;
	mouse_i = (HEI / 2 - y) / (0.5 * HEI * frac->zoom) + frac->shift_i;
	printf("%f, %f - teste de mouse r e i: \n", mouse_r, mouse_i);

	if (ft_strncmp(frac->title, "Julia", 5) == 0)
		julia_mouse_move(but, x, y, frac);
	else if (but == Button4)
		zoom_in(frac, mouse_r, mouse_i);
	else if (but == Button5)
		zoom_out(frac, mouse_r, mouse_i);
	new_cpx_x = -2.0 + ((((double)x) / WID) * 4.0) * frac->zoom + frac->shift_r;
	new_cpx_y = 2.0 + ((((double)y) / HEI) * 4.0) * frac->zoom + frac->shift_i;
	
	//frac->shift_r += (new_cpx_x - old_cpx_x);
	//frac->shift_i -= (new_cpx_y - old_cpx_y);
	printf("%f, %f  coordenadas do cpx depois:\n", new_cpx_x, new_cpx_y);
	fractol_render(frac);
	return (0);
}
