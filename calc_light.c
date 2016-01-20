/*
** calc_light.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Fri Mar 14 07:57:08 2014 athomasjulien
** Last update Sun Mar 16 17:47:33 2014 athomasjulien
*/

#include	<math.h>
#include	"header.h"

int		calc_light_sph(t_point *point)
{
  float		v1;
  float		norme2;
  float		norme1;

  point->pos->xp = point->coord->xeye + (point->sph->vx * point->pos->k_sph);
  point->pos->yp = point->coord->yeye + (point->sph->vy * point->pos->k_sph);
  point->pos->zp = point->coord->zeye + (point->sph->vz * point->pos->k_sph);
  point->lum->nx = point->pos->xp;
  point->lum->ny = point->pos->yp;
  point->lum->nz = point->pos->zp;
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
  point->lum->vz = point->lum->z - point->pos->zp;
  v1 = (point->lum->nx * point->lum->vx + point->lum->ny
	* point->lum->vy + point->lum->nz * point->lum->vz);
  norme1 = (pow(point->lum->nx, 2) + pow(point->lum->ny, 2)
	    + pow(point->lum->nz, 2));
  norme2 = (pow(point->lum->vx, 2) + pow(point->lum->vy, 2)
	    + pow(point->lum->vz, 2));
  point->img->cos = v1 / (sqrt(norme1) * sqrt(norme2));
  if (calc_shadow_cyl(point, point->cyl, point->pos->k_sph) == 2 ||
      calc_shadow_cone(point, point->cone, point->pos->k_sph) == 2)
    return (0x000000);
  return (0xFF0000);
}

int		calc_light_cyl(t_point *point)
{
  float		v1;
  float		norme2;
  float		norme1;

  point->pos->xp = point->coord->xeye + (point->cyl->vx * point->pos->k_cyl);
  point->pos->yp = point->coord->yeye + (point->cyl->vy * point->pos->k_cyl);
  point->pos->zp = point->coord->zeye + (point->cyl->vz * point->pos->k_cyl);
  point->lum->nx = point->pos->xp;
  point->lum->ny = point->pos->yp;
  point->lum->nz = 0;
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
  point->lum->vz = point->lum->z - point->pos->zp;
  v1 = (point->lum->nx * point->lum->vx + point->lum->ny
	* point->lum->vy + point->lum->nz * point->lum->vz);
  norme1 = (pow(point->lum->nx, 2) + pow(point->lum->ny, 2)
	    + pow(point->lum->nz, 2));
  norme2 = (pow(point->lum->vx, 2) + pow(point->lum->vy, 2)
	    + pow(point->lum->vz, 2));
  point->img->cos = v1 / (sqrt(norme1) * sqrt(norme2));
  if (calc_shadow_sph(point, point->sph, point->pos->k_cyl) == 2 ||
      calc_shadow_cone(point, point->cone, point->pos->k_cyl) == 2)
    return (0x000000);
  return (0x00FF00);
}

int		calc_light_cone(t_point *point)
{
  float		v1;
  float		norme2;
  float		norme1;

  point->pos->xp = point->coord->xeye + (point->cone->vx * point->pos->k_cone);
  point->pos->yp = point->coord->yeye + (point->cone->vy * point->pos->k_cone);
  point->pos->zp = point->coord->zeye + (point->cone->vz * point->pos->k_cone);
  point->lum->nx = point->pos->xp;
  point->lum->ny = point->pos->yp;
  point->lum->nz = 0.05 * point->pos->zp;
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
  point->lum->vz = point->lum->z - point->pos->zp;
  v1 = (point->lum->nx * point->lum->vx + point->lum->ny
	* point->lum->vy + point->lum->nz * point->lum->vz);
  norme1 = (pow(point->lum->nx, 2) + pow(point->lum->ny, 2)
	    + pow(point->lum->nz, 2));
  norme2 = (pow(point->lum->vx, 2) + pow(point->lum->vy, 2)
	    + pow(point->lum->vz, 2));
  point->img->cos = v1 / (sqrt(norme1) * sqrt(norme2));
  if (calc_shadow_sph(point, point->sph, point->pos->k_cone) == 2 ||
      calc_shadow_cyl(point, point->cyl, point->pos->k_cone) == 2)
    return (0x000000);
  return (0x6C0277);
}

int		calc_light_plan(t_point *point)
{
  float		v1;
  float		norme2;
  float		norme1;

  point->pos->xp = point->coord->xeye + point->coord->vx * point->pos->k_plan;
  point->pos->yp = point->coord->yeye + point->coord->vy * point->pos->k_plan;
  point->pos->zp = point->coord->zeye + point->coord->vz * point->pos->k_plan;
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
  point->lum->vz = point->lum->z - point->pos->zp;
  v1 = (point->lum->nx * point->lum->vx + point->lum->ny
	* point->lum->vy + point->lum->nz * point->lum->vz);
  norme1 = (pow(point->lum->nx, 2) + pow(point->lum->ny, 2)
	    + pow(point->lum->nz, 2));
  norme2 = (pow(point->lum->vx, 2) + pow(point->lum->vy, 2)
	    + pow(point->lum->vz, 2));
  point->img->cos = v1 / (sqrt(norme1) * sqrt(norme2));
  if (calc_shadow_sph(point, point->sph, point->pos->k_plan) == 2 ||
      calc_shadow_cyl(point, point->cyl, point->pos->k_plan) == 2 ||
      calc_shadow_cone(point, point->cone, point->pos->k_plan) == 2)
    return (0x000000);
  return (0x0000FF);
}
