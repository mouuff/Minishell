/*
** compute.c for compute line in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:14:30 2016 Arnaud Alies
** Last update Mon Mar 14 17:55:24 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	compute(t_data *data, char **expr)
{
  int   	code;

  if (IS_ERR((code = check_builtin(data, expr))))
    return (code);
  if (code == E_SKIP)
    {
      if (IS_ERR((code = my_exec(data, expr))))
	return (code);
    }
  return (E_PASS);
}
/*
int     compute_line(t_data *data, char *line)
{
  char  **args;
  int   code;

  args = NULL;
  if (pre_check(line))
    return (E_PASS);
  if ((args = str_to_arg(line)) == NULL)
    return (E_MALLOC);
  if (parse(args))
    {
      my_array_del(args);
      return (E_PASS);
    }
  if (IS_ERR((code = compute(data, args))))
    {
      my_array_del(args);
      return (code);
    }
  my_array_del(args);
  return (E_PASS);
}
*/

int     	compute_line(t_data *data, char *line)
{
  t_token	*tokens;

  tokens = 
  return (E_PASS);
}
