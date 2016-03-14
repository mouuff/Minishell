/*
** cleanup.c for cleanup in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan 14 11:48:54 2016 Arnaud Alies
** Last update Thu Jan 14 12:01:33 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

void	clean_str(char **s)
{
  if (*s != NULL)
    free(*s);
}

void	clean_array(char ***array)
{
  if (*array != NULL)
    {
      my_array_free(*array);
      free(*array);
    }
}
