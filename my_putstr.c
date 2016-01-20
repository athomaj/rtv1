/*
** my_putstr.c for  in /home/juliena/rendu/MUL_2013_rtv1
** 
** Made by athomasjulien
** Login   <juliena@epitech.net>
** 
** Started on  Sat Mar 15 16:46:16 2014 athomasjulien
** Last update Sat Mar 15 23:12:19 2014 athomasjulien
*/

#include	<unistd.h>
#include	"header.h"

void		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    write(1, &str[i], 1);
}
