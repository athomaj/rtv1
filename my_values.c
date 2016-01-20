/*
** my_values.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Fri Feb 28 13:21:17 2014 athomasjulien
** Last update Sun Mar 16 15:19:22 2014 athomasjulien
*/

#include	"header.h"

void		my_value(t_point *point, int x, int y)
{
  point->lum->x = LUM_X;
  point->lum->y = LUM_Y;
  point->lum->z = LUM_Z;
  point->coord->vx = 100;
  point->coord->vy = (WIN_X / 2) - x;
  point->coord->vz = (WIN_Y / 2) - y;
  point->coord->xeye = EYE_X;
  point->coord->yeye = EYE_Y;
  point->coord->zeye = EYE_Z;
  point->sph->vx = point->coord->vx + SPH_X;
  point->sph->vy = point->coord->vy + SPH_Y;
  point->sph->vz = point->coord->vz + SPH_Z;
  point->sph->rayon = SPH_RAYON;
  point->cyl->vx = point->coord->vx + CYL_X;
  point->cyl->vy = point->coord->vy + CYL_Y;
  point->cyl->vz = point->coord->vz + CYL_Z;
  point->cyl->rayon = CYL_RAYON;
  point->cone->vx = point->coord->vx + CONE_X;
  point->cone->vy = point->coord->vy + CONE_Y;
  point->cone->vz = point->coord->vz + CONE_Z;
}

void		my_shadow_sph(t_point *point, t_coord *sph, float k)
{
  point->pos->xp = point->coord->xeye + (sph->vx * k);
  point->pos->yp = point->coord->yeye + (sph->vy * k);
  point->pos->zp = point->coord->zeye + (sph->vz * k);
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
  point->lum->vz = point->lum->z - point->pos->zp;
}

void		my_shadow_cyl(t_point *point, t_coord *cyl, float k)
{
  point->pos->xp = point->coord->xeye + (cyl->vx * k);
  point->pos->yp = point->coord->yeye + (cyl->vy * k);
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
}

void		my_shadow_cone(t_point *point, t_coord *cone, float k)
{
  point->pos->xp = point->coord->xeye + (cone->vx * k);
  point->pos->yp = point->coord->yeye + (cone->vy * k);
  point->pos->zp = point->coord->zeye + (cone->vz * k);
  point->lum->vx = point->lum->x - point->pos->xp;
  point->lum->vy = point->lum->y - point->pos->yp;
  point->lum->vz = point->lum->z - point->pos->zp;
}
