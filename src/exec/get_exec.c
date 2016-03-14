/*
** get_exec.c for get exec in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 19:50:27 2016 Arnaud Alies
** Last update Sun Jan 24 15:14:37 2016 alies_a
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static void	print_err_file(const char *path)
{
  my_puterr(path);
  if (is_something(path))
    my_puterr(": Permission denied.\n");
  else
    my_puterr(": Command not found.\n");
}

static int      init_paths(t_data *data, char ***paths)
{
  int           x;
  const char	*path;

  if ((path = get_env(data, "PATH")) == NULL)
    path = "";
  if ((*paths = my_str_split(path, ':')) == NULL)
    return (1);
  x = 0;
  while ((*paths)[x] != NULL)
    {
      if (my_char_add(&((*paths)[x]), '/') == NULL)
	return (1);
      x += 1;
    }
  return (0);
}

char    *get_exec_path(t_data *data, char **args)
{
  char  **paths;
  char  *buffer;
  int   x;

  if (init_paths(data, &paths))
    return (NULL);
  x = 0;
  while (paths[x] != NULL)
    {
      if ((buffer = my_str_join(paths[x], args[0])) == NULL)
	return (NULL);
      if (access(buffer, X_OK) == 0 && isfile(buffer))
	{
	  my_array_del(paths);
	  return (buffer);
	}
      free(buffer);
      x += 1;
    }
  my_array_del(paths);
  return (NULL);
}

char    *get_exec_file(const char *path)
{
  if (access(path, X_OK) == 0 && isfile(path))
    return (my_strdup(path));
  return (NULL);
}

char    *get_exec(t_data *data, char **args)
{
  char	*res;

  res = NULL;
  if (is_true_path(args[0]))
    {
      if ((res = get_exec_file(args[0])) != NULL)
	return (res);
      print_err_file(args[0]);
    }
  else
    {
      if ((res = get_exec_path(data, args)) != NULL)
	return (res);
      my_puterr(args[0]);
      my_puterr(": Command not found.\n");
    }
  return (NULL);
}
