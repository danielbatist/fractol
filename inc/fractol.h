/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:27:54 by dbatista          #+#    #+#             */
/*   Updated: 2025/02/09 22:26:56 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/src/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>

# define WID 			800
# define HEI 			800
# define KEY_PRESS		2
# define BUTTON_PRESS	4
# define DESTROY_NOTIFY	17
# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_A			97
# define KEY_D			100
# define KEY_W			119
# define KEY_S			115
# define KEY_ADD		65451
# define KEY_SUB		65453
# define KEY_SPACE		32
# define MOUSE_LEFT		1
# define MOUSE_MIDDLE	2
# define MOUSE_RIGHT	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define GREEN			0x00FF00 
# define BLUE			0x0000FF 
# define MAGENTA		0xFF00FF 
# define LIME			0xCCFF00 
# define ORANGE			0xFF6600
# define PURPLE			0x9932CC 
# define AQUA			0x33CCCC
# define PINK			0xFF66B2
# define ELECTRIC		0x0066FF
# define LIGHTENING		0x00CCFF
# define LAVA			0xFF3300
# define YELLOW			0xFFFF00 
# define PASTELYELLOW	0xFFFF99
# define PASTELPINK		0xFFB6C1

typedef struct s_fractol
{
	int		bpp;
	int		line;
	int		endian;
	int		colour;
	int		iter;
	char	*title;
	char	*addr;
	void	*mlx;
	void	*window;
	void	*img;
	double	hip;
	double	shift_r;
	double	shift_i;
	double	zoom;
	double	julia_r;
	double	julia_i;
	double	cpx_r;
	double	cpx_i;
	double	map_x;
	double	map_y;
}			t_fractol;

typedef struct s_map
{
	double	u_num;
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;

}			t_map;

int			key_handle(int key, t_fractol *frac);
int			mouse_handle(int but, int x, int y, t_fractol *frac);
int			exit_clear(t_fractol *frac);
int			blend_colours(int c1, int c2, double i);
int			re_fractol(t_fractol *frac);
void		colours_change(t_fractol *frac);
void		fractol_render(t_fractol *frac);
void		error_malloc(void);
void		guidelines(void);
void		frac_init(t_fractol *frac);
void		zoom_in(t_fractol *frac, double mouse_r, double mouse_i);
void		zoom_out(t_fractol *frac, double mouse_r, double mouse_i);
void		get_pixel_to_complex(int x, int y, t_fractol *frac);
double		ft_atod(char *str);
double		map(t_map coords);
t_fractol	add_z_with_c(t_fractol z, t_fractol c);
t_fractol	square_complex(t_fractol z);
#endif
