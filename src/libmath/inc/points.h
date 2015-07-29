#ifndef POINTS_H
# define POINTS_H

# include <stdint.h>

typedef uint32_t	t_uint;

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

void	print_pt3f(t_pt3f *pt);
void	print_pt2f(t_pt2f *pt);
void	print_pt3u(t_pt3u *pt);


#endif
