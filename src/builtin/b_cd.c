/*
** b_cd.c for cd in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan 11 16:52:07 2016 Arnaud Alies
** Last update Thu Mar 31 19:41:34 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void	set_pwd(t_data *data)
{
  char	*args[4];
  char	*buff;

  if ((buff = getcwd(NULL, 0)) == NULL)
    return ;
  args[0] = "setenv";
  args[1] = "PWD";
  args[2] = buff;
  args[3] = NULL;
  my_setenv(data, args);
  free(buff);
}

int		set_oldpwd(t_data *data)
{
  const char	*path;

  if ((path = get_env(data, "PWD")) == NULL)
    path = "";
  free(data->oldpwd);
  if ((data->oldpwd = my_strdup(path)) == NULL)
    return (1);
  return (0);
}

static void	print_err(const char *path)
{
  my_puterr(path);
  if (isdir(path))
    my_puterr(": Permission denied.\n");
  else if (is_something(path))
    my_puterr(": Not a directory.\n");
  else
    my_puterr(": No such file or directory.\n");
}

int		b_cd(t_data *data, int ac, char **av)
{
  const char	*path;

  if (ac == 1)
    {
      if ((path = get_env(data, "HOME")) == NULL)
	return (0);
    }
  else if (ac == 2)
    {
      if (my_strcmp(av[1], "-") == 0)
	path = data->oldpwd;
      else
	path = av[1];
    }
  if (chdir(path) == -1)
    {
      print_err(path);
      return (0);
    }
  if (set_oldpwd(data))
    return (1);
  set_pwd(data);
  return (0);
}
