/*
** my_array_show.c for my_array_show in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 22:09:42 2015 Arnaud Alies
** Last update Mon Jan  4 20:37:30 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

int    my_array_show(char **tab)
{
  int   x;

  if (tab == NULL)
    return (0);
  x = 0;
  while (tab[x] != NULL)
    {
      my_putstr(tab[x]);
      my_putchar('\n');
      x += 1;
    }
  return (0);
}
