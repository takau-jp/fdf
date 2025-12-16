/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:01:15 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/26 15:53:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int			compute_outcode(double x, double y);
bool		trival_accept(int s_outcode, int e_outcode);
bool		trival_reject(int s_outcode, int e_outcode);
t_screen	move_to_bounds(t_screen from, t_screen to, int *outcode);


// Cohen-Sutherland Algo
bool	clip_line(t_screen *start, t_screen *end)
{
	int	s_outcode;
	int	e_outcode;

	s_outcode = compute_outcode(start->x, start->y);
	e_outcode = compute_outcode(end->x, end->y);
	while (true)
	{
		if (trival_accept(s_outcode, e_outcode))
			return (true);
		if (trival_reject(s_outcode, e_outcode))
			return (false);
		if (s_outcode != INSIDE_OUTCODE)
			*start = move_to_bounds(*start, *end, &s_outcode);
		else
			*end = move_to_bounds(*end, *start, &e_outcode);
	}
}

// Computes the outcode for a point relative to the clipping window.
int	compute_outcode(double x, double y)
{
	int	code;

	code = INSIDE_OUTCODE;
	if (x < 0)
		code |= LEFT_OUTCODE;
	else if (x >= W_WIDTH)
		code |= RIGHT_OUTCODE;
	if (y < 0)
		code |= TOP_OUTCODE;
	else if (y >= W_HEIGHT)
		code |= BOTTOM_OUTCODE;
	return (code);
}

// Returns true if both endpoints are inside.
bool	trival_accept(int s_outcode, int e_outcode)
{
	return (!(s_outcode | e_outcode));
}

// Returns true if both endpoints are completely outside.
bool	trival_reject(int s_outcode, int e_outcode)
{
	return (s_outcode & e_outcode);
}

t_screen	move_to_bounds(t_screen from, t_screen to, int *outcode)
{
	t_screen	pixel;
	double		alpha;

	alpha = 0.0;
	if (*outcode & LEFT_OUTCODE)
		alpha = (double)(0 - from.x) / (to.x - from.x);
	else if (*outcode & RIGHT_OUTCODE)
		alpha = (double)((W_WIDTH - 1) - from.x) / (to.x - from.x);
	else if (*outcode & TOP_OUTCODE)
		alpha = (double)(0 - from.y) / (to.y - from.y);
	else if (*outcode & BOTTOM_OUTCODE)
		alpha = (double)((W_HEIGHT - 1) - from.y) / (to.y - from.y);
	pixel = lerp_pixel(from, to, alpha);
	if (*outcode & LEFT_OUTCODE)
		pixel.x = 0;
	else if (*outcode & RIGHT_OUTCODE)
		pixel.x = (W_WIDTH - 1);
	else if (*outcode & TOP_OUTCODE)
		pixel.y = 0;
	else if (*outcode & BOTTOM_OUTCODE)
		pixel.y = (W_HEIGHT - 1);
	*outcode = compute_outcode(pixel.x, pixel.y);
	return (pixel);
}
