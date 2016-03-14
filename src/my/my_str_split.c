/*
** my_str_split.c for my_str_split in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 15:43:36 2016 Arnaud Alies
** Last update Thu Jan  7 15:56:30 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

static int	init_res(char ***res)
{
  if ((*res = malloc(sizeof(char*))) == NULL)
    return (1);
  (*res)[0] = NULL;
  if (my_array_add(res, "") == NULL)
    return (1);
  return (0);
}

char	**my_str_split(const char *str, char c)
{
  char	**res;
  int   pos;
  int   x;

  x = 0;
  pos = 0;
  if (init_res(&res))
    return (NULL);
  while (str[x] != '\0')
    {
      if (str[x] == c)
	{
	  if (my_array_add(&res, "") == NULL)
	    return (NULL);
	  pos += 1;
	}
      else if (my_char_add(&(res[pos]), str[x]) == NULL)
	return (NULL);
      x += 1;
    }
  return (res);
}
