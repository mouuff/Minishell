/*
** check.c for check for builtins in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 18:23:39 2016 Arnaud Alies
** Last update Mon Jan 25 22:45:46 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

t_func builtins[] =
  {{&b_exit, "exit"},
   {&b_env, "env"},
   {&b_setenv, "setenv"},
   {&b_unsetenv, "unsetenv"},
   {&b_cd, "cd"},
   {&b_doge, "doge"},
   {NULL, NULL}};

int     check_builtin(t_data *data, char **args)
{
  int	x;
  int	len;

  len = my_array_len(args);
  x = 0;
  while (builtins[x].name != NULL)
    {
      if (my_strcmp(args[0], builtins[x].name) == 0)
	return ((builtins[x].func)(data, len, args));
      x += 1;
    }
  return (E_SKIP);
}
