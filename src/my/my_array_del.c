/*
** my_array_del.c for del array in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 16:24:28 2016 Arnaud Alies
** Last update Mon Jan 18 11:10:14 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"

int	my_array_del(char **array)
{
  if (array != NULL)
    {
      my_array_free(array);
      free(array);
    }
  return (0);
}
