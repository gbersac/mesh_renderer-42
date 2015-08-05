#ifndef POINTS_H
# define POINTS_H

# include <stdint.h>

typedef uint32_t	t_uint;

typedef struct	s_pt4f
{
	float	x;
	float	y;
	float	z;

	/*
	** Must stay the last attribute of the point.
	*/
	float	w;
}				t_pt4f;

typedef struct	s_pt3f
{
	float	x;
	float	y;
	float	z;
}				t_pt3f;

typedef struct	s_pt2f
{
	float	x;
	float	y;
}				t_pt2f;

typedef struct	s_pt3u
{
	t_uint	x;
	t_uint	y;
	t_uint	z;
}				t_pt3u;

typedef struct	s_pt4u
{
	t_uint	w;
	t_uint	x;
	t_uint	y;
	t_uint	z;
}				t_pt4u;

void			print_pt4f(t_pt4f *pt);
void			print_pt3f(t_pt3f *pt);
void			print_pt2f(t_pt2f *pt);
void			print_pt3u(t_pt3u *pt);

#endif
