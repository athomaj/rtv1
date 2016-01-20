/*
** my_pixel_put_to_image.c for my_pixel_put_to_image.c in /home/juliena/rendu/MUL_2013_wolf3d
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Thu Dec 19 14:05:19 2013 athomasjulien
** Last update Mon Mar 10 20:40:15 2014 athomasjulien
*/

#include	"header.h"

int		my_pixel_put_to_image(t_my_img *img, int x, int y, int color)
{
  int		a;
  int		b;
  unsigned char	*col;

  if (x >= WIN_X || y >= WIN_Y || x < 0 || y < 0)
    return (0);
  col = (unsigned char *)&color;
  a = img->bpp / 8;
  b = img->sizeline;
  if (img->cos < 0)
    img->cos = 0;
  img->data[(x * a) + 0 + (y * b)] = col[0] * img->cos;
  img->data[(x * a) + 1 + (y * b)] = col[1] * img->cos;
  img->data[(x * a) + 2 + (y * b)] = col[2] * img->cos;
  img->data[(x * a) + 3 + (y * b)] = col[3] * img->cos;
  return (0);
}
