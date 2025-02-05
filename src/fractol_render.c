

#include "fractol.h"

static void	my_mlx_pixel_put(int x, int y, t_fractol *frac, int colour)
{
	int	displace;

	displace = (y * frac->line + x * (frac->bpp / 8));
	*(unsigned int *)(frac->addr + displace) = colour;

}

static void	fract_set(t_fractol *z, t_fractol *c, t_fractol *frac)
{
	if (ft_strncmp(frac->title, "Julia", 5) == 0)
	{
		c->cpx_r = frac->julia_r;
		c->cpx_i = frac->julia_i;
	}
	else
	{
		c->cpx_r = z->cpx_r;
		c->cpx_i = z->cpx_i;	
	}
}

static void	get_pixel_to_complex(int x, int y, t_fractol *frac)
{
	t_fractol	z;
	t_fractol	c;
	int			i;
	int			rgb;

	i = 0;
	z.cpx_r = (map(x, 0, WID) * frac->zoom) + frac->shift_r;
	z.cpx_i = (map(y, 0, HEI) * frac->zoom) + frac->shift_i;
	fract_set(&z, &c, frac);
	while (i < frac->iter)
	{
		z = add_z_with_c(square_complex(z), c);
		if ((z.cpx_r * z.cpx_r) + (z.cpx_i * z.cpx_i) > frac->hip)
		{
			rgb = blend_colours(BLACK, frac->colour, (double)i / frac->iter);
			my_mlx_pixel_put(x, y, frac, rgb);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(x, y, frac, BLACK);
}

void	fractol_render(t_fractol *frac)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
			get_pixel_to_complex(x, y, frac);
	}
	mlx_put_image_to_window(frac->mlx, frac->window, frac->img, 0, 0);
}
