/*
** my_str_join.c for my_str_join in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan  6 21:26:31 2016 Arnaud Alies
** Last update Wed Jan  6 21:28:30 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char	*my_str_join(const char *dest, const char *from)
{
  char	*res;
  int   size;
  int   x;
  int   y;

  size = my_strlen(dest) + my_strlen(from);
  if ((res = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  my_strcpy(res, dest);
  y = my_strlen(res);
  x = 0;
  while (from[x] != '\0')
    {
      res[y] = from[x];
      x += 1;
      y += 1;
    }
  res[y] = '\0';
  return (res);
}
