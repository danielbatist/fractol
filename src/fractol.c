/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:52:05 by dbatista          #+#    #+#             */
/*   Updated: 2025/01/28 23:52:22 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot") + 1) == 0)
		{
			guidelines();
			argv[1][0] = ft_toupper(argv[1][0]);
			frac.title = argv[1];
		}
		frac_init(&frac);
		fractol_render(&frac);
		mlx_loop(frac.mlx);
		return (0);
	}
	if (argc == 4)
	{
		if (ft_strncmp(argv[1], "julia", ft_strlen("julia") + 1) == 0)
		{
			guidelines();
			argv[1][0] = ft_toupper(argv[1][0]);
			frac.title = argv[1];
			if (ft_strncmp(frac.title, "Julia", 5))
			{
				frac.julia_r = ft_atod(argv[2]); 
				frac.julia_i = ft_atod(argv[3]);
			}
			frac_init(&frac);
			fractol_render(&frac);
			mlx_loop(frac.mlx);
			return (0);
		}
	}
	ft_printf("Invalid input\n");
	ft_printf("Try:\n<./fractol mandelbrot> ");
	ft_printf("or ");
	ft_printf("<./fractol julia -0.4 +0.6");
	ft_printf("<./fractol julia -0.835 -0.2321>\n");
	exit(1);
}
