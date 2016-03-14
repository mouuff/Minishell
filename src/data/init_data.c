/*
** init_data.c for init data in /home/alies/rendu/PSU_2015_minishell1/src/data
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 19:44:54 2016 Arnaud Alies
** Last update Thu Jan 14 15:57:16 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int     init_data(t_data *data, char **env)
{
  if ((data->env = my_array_dup(env)) == NULL)
    return (1);
  if ((data->oldpwd = my_strdup("")) == NULL)
    return (1);
  return (0);
}
