/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:43:03 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/09 12:33:40 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	square_complex(t_fractol z)
{
	t_fractol	res;

	res.cpx_r = (z.cpx_r * z.cpx_r) - (z.cpx_i * z.cpx_i);
	res.cpx_i = 2 * z.cpx_r * z.cpx_i;
	return (res);
}

t_fractol	add_z_with_c(t_fractol z1, t_fractol z2)
{
	t_fractol	res;

	res.cpx_r = z1.cpx_r + z2.cpx_r;
	res.cpx_i = z1.cpx_i + z2.cpx_i;
	return (res);
}

void	error_malloc(void)
{
	perror("Malloc error: ");
	exit(1);
}
