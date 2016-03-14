/*
** my_array_dup.c for my_array_dup in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 10:08:43 2016 Arnaud Alies
** Last update Tue Jan  5 10:18:18 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"

char            **my_array_dup(char **from)
{
  char          **res;

  if ((res = malloc(sizeof(char*) * (my_array_len(from) + 1))) == NULL)
    return (NULL);
  if (my_array_cpy(res, from) == NULL)
    return (NULL);
  return (res);
}
