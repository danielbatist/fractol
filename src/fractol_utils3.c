/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:43:03 by dbatista          #+#    #+#             */
/*   Updated: 2025/01/28 23:32:50 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, t_fractol *frac, int colour)
{
	int	displace;

	displace = (y * frac->line + x * (frac->bpp / 8));
	*(unsigned int *)(frac->addr + displace) = colour;

}

t_fractol	square_complex(t_fractol z)
{
	t_fractol	res;

	res.cpx_r = (z.cpx_r * z.cpx_r) - (z.cpx_i * z.cpx_i);
	res.cpx_i = 2 * z.cpx_r * z.cpx_i;
	return (res);
}

t_fractol	add_z_with_c(t_fractol z, t_fractol c)
{
	t_fractol	res;

	res.cpx_r = z.cpx_r + c.cpx_r;
	res.cpx_i = z.cpx_i + c.cpx_i;
	return (res);
}

void	error_malloc(void)
{
	perror("Malloc error: ");
	exit(1);
}
