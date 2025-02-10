/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:41:58 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/09 22:27:57 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_mouse_move(int but, int x, int y, t_fractol *f)
{
	if (but == MOUSE_LEFT || but == MOUSE_RIGHT)
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
	if (key == KEY_ESC)
		exit_clear(frac);
	else if (key == KEY_LEFT || key == KEY_A)
		frac->shift_r += (0.1 * frac->zoom);
	else if (key == KEY_RIGHT || key == KEY_D)
		frac->shift_r -= (0.1 * frac->zoom);
	else if (key == KEY_UP || key == KEY_W)
		frac->shift_i -= (0.1 * frac->zoom);
	else if (key == KEY_DOWN || key == KEY_S)
		frac->shift_i += (0.1 * frac->zoom);
	else if (key == KEY_ADD)
		frac->iter += 10;
	else if (key == KEY_SUB)
		frac->iter -= 10;
	else if (key == KEY_SPACE)
		colours_change(frac);
	fractol_render(frac);
	return (0);
}

int	mouse_handle(int but, int x, int y	, t_fractol *frac)
{
	double		mouse_r;
	double		mouse_i;

	mouse_r = frac->shift_r + ((double)x / WID) \
	* (4.0 * frac->zoom) - 2.0 * frac->zoom;
	mouse_i = frac->shift_i + (2.0 * frac->zoom) \
	- ((double)y / HEI) * (4.0 * frac->zoom);
	if (ft_strncmp(frac->title, "Julia", 5) == 0)
		julia_mouse_move(but, x, y, frac);
	else if (but == SCROLL_UP)
		zoom_in(frac, mouse_r, mouse_i);
	else if (but == SCROLL_DOWN)
		zoom_out(frac, mouse_r, mouse_i);
	fractol_render(frac);
	return (0);
}
