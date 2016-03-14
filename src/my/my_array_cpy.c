/*
** my_array_cpy.c for my_array_cpy in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 10:10:08 2016 Arnaud Alies
** Last update Tue Jan  5 10:13:10 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char	**my_array_cpy(char **dest, char **from)
{
  int	x;

  x = 0;
  while (from[x] != NULL)
    {
      if ((dest[x] = my_strdup(from[x])) == NULL)
	return (NULL);
      x += 1;
    }
  dest[x] = NULL;
  return (dest);
}
