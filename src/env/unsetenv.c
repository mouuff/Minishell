/*
** unsetenv.c for unsetenv in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 11:57:04 2016 Arnaud Alies
** Last update Thu Jan  7 13:46:18 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "mysh.h"

void	remove_env(t_data *data, const char *name)
{
  int	pos;
  int	x;
  int	y;

  pos = find_env(data, name);
  if (pos == -1)
    return ;
  y = 0;
  x = 0;
  while ((data->env)[x] != NULL)
    {
      if (x == pos)
	free((data->env)[x]);
      else
	{
	  (data->env)[y] = (data->env)[x];
	  y += 1;
	}
      x += 1;
    }
  (data->env)[y] = NULL;
}

int	my_unsetenv(t_data *data, char **args)
{
  int	x;

  x = 1;
  while (args[x] != NULL)
    {
      remove_env(data, args[x]);
      x += 1;
    }
  return (0);
}
