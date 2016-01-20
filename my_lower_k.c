/*
** my_lower_k.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Mon Mar 10 16:29:29 2014 athomasjulien
** Last update Sat Mar 15 17:19:58 2014 athomasjulien
*/

#include	"header.h"

int		my_lower_shadow_k(float delta, float x1, float x2)
{
  if (delta < 0)
    return (1);
  else if (x1 > x2 && x2 > 0)
    x1 = x2;
  if (x1 > 0 && x1 < 1)
    return (2);
  return (1);
}

void		my_swap_values(int *i, float *tab, int *size)
{
  int		j;
  float		tmp;

  *i = 1;
  j = -1;
  while (++j < *size - 1)
    {
      if (tab[j] > tab[j + 1])
	{
	  tmp = tab[j];
	  tab[j] = tab[j + 1];
	  tab[j + 1] = tmp;
	  *i = 0;
	}
    }
  *size = *size - 1;
}

float		my_low_k(t_point *point)
{
  float		tab[5];
  int		i;
  int		size;

  tab[0] = point->pos->k_plan;
  tab[1] = point->pos->k_sph;
  tab[2] = point->pos->k_cyl;
  tab[3] = point->pos->k_cone;
  tab[4] = 0;
  size = 4;
  i = 0;
  while (i != 1)
    my_swap_values(&i, tab, &size);
  i = -1;
  while (tab[++i] && tab[i] <= 0);
  return (tab[i]);
}
