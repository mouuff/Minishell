/*
** my_array_free.c for free in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 19:50:19 2016 Arnaud Alies
** Last update Thu Jan 14 15:35:17 2016 Arnaud Alies
*/

#include <stdlib.h>

void    my_array_free(char **array)
{
  int   x;

  if (array == NULL)
    return ;
  x = 0;
  while (array[x] != NULL)
    {
      free(array[x]);
      x += 1;
    }
}
