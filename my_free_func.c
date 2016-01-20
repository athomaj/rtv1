/*
** my_free_func.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Sat Mar 15 09:32:56 2014 athomasjulien
** Last update Sun Mar 16 18:15:15 2014 athomasjulien
*/

#include	<stdlib.h>
#include	"header.h"

void		my_free_struct(t_point *point)
{
  free(point->img);
  free(point->coord);
  free(point->sph);
  free(point->cyl);
  free(point->cone);
  free(point->pos);
  free(point->lum);
}
