/*
** find_env.c for find env in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan  6 18:53:30 2016 Arnaud Alies
** Last update Thu Jan 14 16:30:22 2016 Arnaud Alies
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	env_len(const char *str)
{
  int   	x;

  if (str == NULL)
    return (0);
  x = 0;
  while (str[x] != '\0' && str[x] != '=')
    x += 1;
  return (x);
}

static int     env_find(const char *env, const char *name)
{
  int   	x;

  if (env_len(env) != my_strlen(name))
    return (0);
  x = 0;
  while (env[x] != '\0' && name[x] != '\0' && env[x] != '=')
    {
      if (env[x] != name[x])
	return (0);
      x += 1;
    }
  return (1);
}

int     find_env(t_data *data, const char *name)
{
  int   x;

  x = 0;
  while ((data->env)[x] != NULL)
    {
      if (env_find((data->env)[x], name))
	return (x);
      x += 1;
    }
  return (-1);
}

const char	*get_env(t_data *data, const char *name)
{
  int		x;
  int		len;

  x = find_env(data, name);
  if (x < 0)
    return (NULL);
  len = my_strlen(name) + 1;
  return ((data->env)[x] + len);
}
