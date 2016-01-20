/*
** my_object.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Fri Feb 28 13:15:07 2014 athomasjulien
** Last update Sat Mar 15 23:12:03 2014 athomasjulien
*/

#include	<math.h>
#include	"header.h"

void		my_sphere(t_point *point)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		new_k;

  a = (point->sph->vx * point->sph->vx + point->sph->vy
       * point->sph->vy + point->sph->vz * point->sph->vz);
  b = (2 * point->sph->vx * point->coord->xeye + 2
       * point->sph->vy * point->coord->yeye
       + 2 * point->sph->vz * point->coord->zeye);
  c = (point->coord->xeye * point->coord->xeye
       + point->coord->yeye * point->coord->yeye
       + point->coord->zeye * point->coord->zeye
       - point->sph->rayon * point->sph->rayon);
  delta = (b * b) - (4 * a * c);
  point->pos->k_sph = (-b - sqrt(delta)) / (2 * a);
  new_k = (-b + sqrt(delta)) / (2 * a);
  if (delta < 0)
    point->pos->k_sph = -1;
  else if (point->pos->k_sph > new_k && new_k > 0)
    point->pos->k_sph = new_k;
}

void		my_cyl(t_point *point)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		new_k;

  a = pow(point->cyl->vx, 2) + pow(point->cyl->vy, 2);
  b = (2 * point->cyl->vx * point->coord->xeye + 2
       * point->cyl->vy * point->coord->yeye);
  c = (pow(point->coord->xeye, 2) + pow(point->coord->yeye, 2)
       - pow(point->cyl->rayon, 2));
  delta = (b * b) - (4 * a * c);
  point->pos->k_cyl = (-b - sqrt(delta)) / (2 * a);
  new_k = (-b + sqrt(delta)) / (2 * a);
  if (delta < 0)
    point->pos->k_cyl = -1;
  else if (point->pos->k_cyl > new_k && new_k > 0)
    point->pos->k_cyl = new_k;
}

void		my_cone(t_point *point)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		new_k;

  a = pow(point->cone->vx, 2) + pow(point->cone->vy, 2)
    - (pow(point->cone->vz, 2) * 0.1);
  b = (2 * point->cone->vx * point->coord->xeye)
    + (2 * point->cone->vy * point->coord->yeye)
    - ((2 * point->cone->vz * point->coord->zeye) * 0.1);
  c = (pow(point->coord->xeye, 2) + pow(point->coord->yeye, 2)
       - (pow(point->coord->zeye, 2) * 0.1));
  delta = (b * b) - (4 * a * c);
  point->pos->k_cone = (-b - sqrt(delta)) / (2 * a);
  new_k = (-b + sqrt(delta)) / (2 * a);
  if (delta < 0)
    point->pos->k_cone = -1;
  else if (point->pos->k_cone > new_k && new_k > 0)
    point->pos->k_cone = new_k;
}
