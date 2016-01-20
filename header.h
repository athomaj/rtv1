/*
** header.h for header.h in /home/juliena/Documents/graph/tp_droites
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Thu Nov 21 17:14:20 2013 athomasjulien
** Last update Sun Mar 16 18:23:09 2014 athomasjulien
*/

#ifndef HEADER_H_
# define HEADER_H_
# define WIN_X 1000
# define WIN_Y 1000
# define SPH_X 200
# define SPH_Y -250
# define SPH_Z -30
# define SPH_RAYON 800
# define CYL_X 500
# define CYL_Y 200
# define CYL_Z 0
# define CYL_RAYON 150
# define CONE_X 450
# define CONE_Y 0
# define CONE_Z 0
# define LUM_X -3000
# define LUM_Y 4000
# define LUM_Z 2000
# define EYE_X -3000
# define EYE_Y 0
# define EYE_Z 500

typedef struct	s_my_img
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  float		cos;
}		t_my_img;

typedef struct	s_char
{
  float		x;
  float		y;
  float		alpha;
}		t_char;

typedef struct	s_coord
{
  float		vx;
  float		vy;
  float		vz;
  float		rayon;
  float		xeye;
  float		yeye;
  float		zeye;
  float		angle;
}		t_coord;

typedef struct	s_pos
{
  float		k_plan;
  float		k_sph;
  float		k_cyl;
  float		k_cone;
  float		xp;
  float		yp;
  float		zp;
}		t_pos;

typedef struct	s_lum
{
  float		x;
  float		y;
  float		z;
  float		vx;
  float		vy;
  float		vz;
  float		nx;
  float		ny;
  float		nz;
}		t_lum;

typedef struct	s_struct_point
{
  t_my_img	*img;
  t_char	*charac;
  t_coord	*coord;
  t_coord	*sph;
  t_coord	*cyl;
  t_coord	*cone;
  t_pos		*pos;
  t_lum		*lum;
}		t_point;

int		my_pixel_put_to_image(t_my_img *, int, int, int);
int		gere_key(int, void *);
int		my_struct_init(t_point *);
int		my_img(t_point *);
int		gere_expose(t_point *);
int		calc_light_plan(t_point *);
int		calc_light_sph(t_point *);
int		calc_light_cyl(t_point *);
int		calc_light_cone(t_point *);
int		calc_shadow_sph(t_point *, t_coord *, float);
int		calc_shadow_cyl(t_point *, t_coord *, float);
int		calc_shadow_cone(t_point *, t_coord *, float);
int		calc(int, int, t_point *);
int		inter_plan(t_point *);
void		my_sphere(t_point *);
void		my_cyl(t_point *);
void		my_cone(t_point *);
void		my_value(t_point *, int, int);
void		my_shadow_cone(t_point *, t_coord *, float);
void		my_shadow_sph(t_point *, t_coord *, float);
void		my_shadow_cyl(t_point *, t_coord *, float);
float		my_low_k(t_point *);
void		my_putchar(char);
void		my_free_struct(t_point *);
int		my_lower_shadow_k(float, float, float);
void		my_putstr(char *);

#endif /* !HEADER_H_ */
