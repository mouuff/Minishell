/*
** my_array_len.c for array_len in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 21:31:06 2015 Arnaud Alies
** Last update Mon Jan  4 20:37:22 2016 Arnaud Alies
*/

#include <stdlib.h>

int     my_array_len(char **array)
{
  int   x;

  if (array == NULL)
    return (0);
  x = 0;
  while (array[x] != NULL)
    x += 1;
  return (x);
}
