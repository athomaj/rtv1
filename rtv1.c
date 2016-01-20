/*
** main.c for main.c in /home/juliena/Documents/graph/RT
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Fri Feb  7 15:15:18 2014 athomasjulien
** Last update Sun Mar 16 19:54:52 2014 athomasjulien
*/

#include	<mlx.h>
#include	<stdlib.h>
#include	"header.h"

int		gere_key(int keycode, void *param)
{
  t_point	*point;

  point = param;
  if (keycode == 65307)
    {
      my_free_struct(point);
      exit(0);
    }
  return (0);
}

int		my_struct_init(t_point *my_point)
{
  my_point->img = malloc(sizeof(*my_point->img));
  my_point->coord = malloc(sizeof(*my_point->coord));
  my_point->sph = malloc(sizeof(*my_point->sph));
  my_point->cyl = malloc(sizeof(*my_point->cyl));
  my_point->cone = malloc(sizeof(*my_point->cone));
  my_point->pos = malloc(sizeof(*my_point->pos));
  my_point->lum = malloc(sizeof(*my_point->lum));
  if (my_point->img == NULL
      || my_point->coord == NULL || my_point->sph == NULL
      || my_point->pos == NULL || my_point->lum == NULL
      || my_point->cyl == NULL || my_point->cone == NULL)
    {
      my_putstr("Malloc failed\n");
      return (-1);
    }
  return (0);
}

int		my_img(t_point *my_point)
{
  int		x;
  int		y;
  int		color;

  y = 0;
  while (y < WIN_Y)
    {
      x = 0;
      while (x < WIN_X)
	{
	  if ((color = calc(x, y, my_point)) != 0)
	    my_pixel_put_to_image(my_point->img, x, y, color);
	  x = x + 1;
	}
      y = y + 1;
    }
  return (0);
}

int		gere_expose(t_point *my_point)
{
  mlx_put_image_to_window(my_point->img->mlx_ptr, my_point->img->win_ptr,
			  my_point->img->img_ptr, 0, 0);
  return (0);
}

int		main()
{
  t_point	my_point;

  if (my_struct_init(&my_point) == -1)
    return (1);
  if ((my_point.img->mlx_ptr = mlx_init()) == NULL)
    {
      my_putstr("Mlx fonction failed\n");
      return (1);
    }
  if ((my_point.img->win_ptr = mlx_new_window(my_point.img->mlx_ptr,
					      WIN_X, WIN_Y, "RT")) == NULL)
    return (1);
  if ((my_point.img->img_ptr = mlx_new_image(my_point.img->mlx_ptr,
					     WIN_X, WIN_Y)) == NULL)
    return (1);
  if ((my_point.img->data = mlx_get_data_addr(my_point.img->img_ptr,
					      &my_point.img->bpp,
					      &my_point.img->sizeline,
					      &my_point.img->endian)) == NULL)
    return (1);
  my_img(&my_point);
  mlx_key_hook(my_point.img->win_ptr, gere_key, &my_point);
  mlx_expose_hook(my_point.img->win_ptr, gere_expose, &my_point);
  mlx_loop(my_point.img->mlx_ptr);
  return (0);
}
