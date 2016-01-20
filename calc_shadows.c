/*
** calc_shadows.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Fri Mar 14 12:47:04 2014 athomasjulien
** Last update Sun Mar 16 15:18:11 2014 athomasjulien
*/

#include	<math.h>
#include	"header.h"

int		calc_shadow_sph(t_point *point, t_coord *sph, float k)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		x2;
  float		x1;

  my_shadow_sph(point, sph, k);
  a = (pow(point->lum->vx, 2) + pow(point->lum->vy, 2)
       + pow(point->lum->vz, 2));
  b = 2 * (point->lum->vx * point->pos->xp + point->lum->vy * point->pos->yp
       + point->lum->vz * point->pos->zp);
  c = (pow(point->pos->xp, 2) + pow(point->pos->yp, 2)
       + pow(point->pos->zp, 2) - sph->rayon * sph->rayon);
  delta = (b * b) - (4 * a * c);
  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  return (my_lower_shadow_k(delta, x1, x2));
}

int		calc_shadow_cyl(t_point *point, t_coord *cyl, float k)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		x2;
  float		x1;

  my_shadow_cyl(point, cyl, k);
  a = (pow(point->lum->vx, 2) + pow(point->lum->vy, 2));
  b = (2 * point->lum->vx * point->pos->xp + 2
       * point->lum->vy * point->pos->yp);
  c = (pow(point->pos->xp, 2) + pow(point->pos->yp, 2)
       - cyl->rayon * cyl->rayon);
  delta = (b * b) - (4 * a * c);
  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  return (my_lower_shadow_k(delta, x1, x2));
}

int		calc_shadow_cone(t_point *point, t_coord *cone, float k)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		x2;
  float		x1;

  my_shadow_cone(point, cone, k);
  a = pow(point->lum->vx, 2) + pow(point->lum->vy, 2)
    - (pow(point->lum->vz, 2) * 0.05);
  b = (2 * point->lum->vx * point->pos->xp) + (2 * point->lum->vy
						    * point->pos->yp)
    - ((2 * point->lum->vz * point->pos->zp) * 0.05);
  c = (pow(point->pos->xp, 2) + pow(point->pos->yp, 2)
       - (pow(point->pos->zp, 2) * 0.05));
  delta = (b * b) - (4 * a * c);
  x1 = (-b - sqrt(delta)) / (2 * a);
  x2 = (-b + sqrt(delta)) / (2 * a);
  return (my_lower_shadow_k(delta, x1, x2));
}
