/*
** free_data.c for free_data in /home/alies/rendu/PSU_2015_minishell1/src/data
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 19:45:52 2016 Arnaud Alies
** Last update Thu Jan 14 15:56:57 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void	free_data(t_data *data)
{
  my_array_free(data->env);
  free(data->env);
  free(data->oldpwd);
}
