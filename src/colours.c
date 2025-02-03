/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:14:21 by dbatista          #+#    #+#             */
/*   Updated: 2025/01/29 15:42:44 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	blend_colours(int c1, int c2, double i)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - i) * ((c1 >> 16) & 0xFF) + i * ((c2 >> 16) & 0xFF) * 5);
	g = (int)((1 - i) * ((c1 >> 8) & 0xFF) + i * ((c2 >> 8) & 0xFF) * 5);
	b = (int)((1 - i) * (c1 & 0xFF) + i * (c2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * i * 1.5);
	g = (int)(g + (255 - g) * i * 0.2);
	b = (int)(b + (255 - b) * i * 4);
	return (r << 16) | (g << 8) | b;
}

void	colours_change(t_fractol *frac)
{
	static int	colour[] = {
		WHITE, PASTELPINK, GREEN, BLUE, MAGENTA,
		LIME, ORANGE, PURPLE, AQUA, PINK, ELECTRIC,
		LIGHTENING, LAVA, YELLOW, PASTELYELLOW
	};
	static int	colour_i = 0;

	colour_i = (colour_i + 1) % (sizeof(colour) / sizeof(colour[0]));
	frac->colour = colour[colour_i];
	fractol_render(frac);
}
