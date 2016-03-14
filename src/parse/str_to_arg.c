/*
** str_to_arg.c for str to arg in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 16:51:33 2016 Arnaud Alies
** Last update Fri Jan 22 13:57:02 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "str_to_arg.h"

static int	init_vars(t_vars *var)
{
  if ((var->res = malloc(sizeof(char*))) == NULL)
    return (1);
  (var->res)[0] = NULL;
  var->x = 0;
  var->pos = 0;
  var->par = 0;
  return (0);
}

static int	loop(t_vars *var)
{
  if ((var->res)[var->pos] == NULL)
    {
      if (my_array_add(&(var->res), "") == NULL)
	return (1);
    }
  if ((var->str)[var->x] == '"' || (var->str)[var->x] == '\'')
    var->par = (var->par ? 0 : 1);
  if ((var->str)[var->x] == ' ' && !var->par)
    var->pos += 1;
  else if ((var->str)[var->x] != '\'' && (var->str)[var->x] != '"')
    {
      if (my_char_add(&((var->res)[var->pos]), (var->str)[var->x]) == NULL)
	return (1);
    }
  var->x += 1;
  return (0);
}

char    	**str_to_arg(const char *str)
{
  t_vars	var;

  var.str = str;
  if (init_vars(&var))
    return (NULL);
  while (str[var.x] != '\0')
    {
      if (loop(&var))
	return (NULL);
    }
  return (var.res);
}
