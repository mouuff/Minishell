/*
** setenv.c for setenv in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan  6 17:19:12 2016 Arnaud Alies
** Last update Thu Jan  7 11:23:10 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int	add_env(t_data *data, char **args)
{
  char	*buffer;
  char	*tmp;
  int   len;

  len = my_array_len(args);
  if (len >= 2)
    {
      if ((buffer = my_strdup(args[1])) == NULL)
	return (1);
      if (my_char_add(&buffer, '=') == NULL)
	return (1);
    }
  if (len == 3)
    {
      if ((tmp = my_str_join(buffer, args[2])) == NULL)
	return (1);
      free(buffer);
      buffer = tmp;
    }
  if (my_array_add(&(data->env), buffer) == NULL)
    return (1);
  free(buffer);
  return (0);
}

int	reset_env(t_data *data, char **args, int x)
{
  char  *tmp;
  int	len;

  len = my_array_len(args);
  free((data->env)[x]);
  if (len >= 2)
    {
      if (((data->env)[x] = my_strdup(args[1])) == NULL)
	return (1);
      if (my_char_add(&((data->env)[x]), '=') == NULL)
	return (1);
    }
  if (len == 3)
    {
      if ((tmp = my_str_join((data->env)[x], args[2])) == NULL)
	return (1);
      free((data->env)[x]);
      (data->env)[x] = tmp;
    }
  return (0);
}

int	my_setenv(t_data *data, char **args)
{
  int	x;

  if (parse_setenv(args))
    return (0);
  if ((x = find_env(data, args[1])) == -1)
    {
      if (add_env(data, args))
	return (1);
    }
  else
    {
      if (reset_env(data, args, x))
	return (1);
    }
  return (0);
}
