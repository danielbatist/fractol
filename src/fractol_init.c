/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:54:04 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/04 21:26:17 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	creation_window(t_fractol *frac)
{
	frac->window = mlx_new_window(frac->mlx, WID, HEI, frac->title);
	if (!frac->window)
	{
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		error_malloc();
	}
}

static void	creation_img(t_fractol *ft)
{
	ft->img = mlx_new_image(ft->mlx, WID, HEI);
	if (!ft->img)
	{
		mlx_destroy_image(ft->mlx, ft->window);
		mlx_destroy_display(ft->mlx);
		free(ft->mlx);
		error_malloc();
	}
	ft->addr = mlx_get_data_addr(ft->img, &ft->bpp, &ft->line, &ft->endian);
}

static void	init_event(t_fractol *frac)
{
	mlx_hook(frac->window, KeyPress, KeyPressMask, key_handle, frac);
	mlx_hook(frac->window, ButtonPress, ButtonPressMask, mouse_handle, frac);
	mlx_hook(frac->window, DestroyNotify, StructureNotifyMask, exit_clear, frac);
}

static void	init_data(t_fractol *frac)
{
	frac->hip = 4;
	frac->iter = 50;
	frac->shift_r = 0.0;
	frac->shift_i = 0.0;
	frac->zoom = 1.0;
}

void	frac_init(t_fractol *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		error_malloc();
	creation_window(frac);
	creation_img(frac);
	init_event(frac);
	init_data(frac);
	frac->colour = WHITE;
}
