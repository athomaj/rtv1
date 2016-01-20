/*
** my_calc.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Fri Feb 28 13:17:58 2014 athomasjulien
** Last update Sun Mar 16 18:14:23 2014 athomasjulien
*/

#include	<math.h>
#include	"header.h"

int		inter_plan(t_point *point)
{
  if (point->coord->vz == 0)
    return (0);
  point->pos->k_plan = (-point->coord->zeye) / point->coord->vz;
  point->lum->nx = 0;
  point->lum->ny = 0;
  point->lum->nz = 100;
  if (point->pos->k_plan > 0)
    return (2);
  else
    return (1);
}

void		init_tab_float(float *tab_float, t_point *point)
{
  tab_float[0] = point->pos->k_plan;
  tab_float[1] = point->pos->k_sph;
  tab_float[2] = point->pos->k_cyl;
  tab_float[3] = point->pos->k_cone;
}

int		which_color(t_point *point)
{
  float		k;
  float		tab_float[4];
  int		(*fptr[4])(t_point *);
  int		i;

  k = my_low_k(point);
  init_tab_float(tab_float, point);
  fptr[0] = &calc_light_plan;
  fptr[1] = &calc_light_sph;
  fptr[2] = &calc_light_cyl;
  fptr[3] = &calc_light_cone;
  i = -1;
  while (++i < 4)
    if (k == tab_float[i])
      return (fptr[i](point));
  return (0);
}

int		calc(int x, int y, t_point *point)
{
  int		k;

  my_value(point, x, y);
  inter_plan(point);
  my_sphere(point);
  my_cyl(point);
  my_cone(point);
  k = which_color(point);
  return (k);
}
