/*
** my_array_add.c for my array add in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 15:31:38 2016 Arnaud Alies
** Last update Tue Jan  5 15:54:56 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char	**my_array_add(char ***from, const char *str)
{
  char	**res;
  int	len;

  len = my_array_len(*from);
  if ((res = malloc(sizeof(char*) * (len + 2))) == NULL)
    return (NULL);
  if (my_array_cpy(res, *from) == NULL)
    return (NULL);
  my_array_free(*from);
  free(*from);
  if ((res[len] = my_strdup(str)) == NULL)
    return (NULL);
  res[len + 1] = NULL;
  *from = res;
  return (res);
}
