/*
** compute.c for compute line in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:14:30 2016 Arnaud Alies
** Last update Sun Apr 10 18:51:36 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int     	compute(t_data *data, char *line)
{
  t_cmp		*res;
  t_token	*tokens;
  int		code;

  if ((tokens = tokenize(line)) == NULL)
    return (1);
  if (cl_tokens(tokens))
    return (1);
  if ((res = recompose(tokens)) == NULL)
    return (1);
  if (cmps_parse(res) == 0)
    {
      if ((code = launch_cmps(data, res, 0)) != 0)
	{
	  cmps_free(&res);
	  tokens_free(&tokens);
	  return (code);
	}
    }
  cmps_free(&res);
  tokens_free(&tokens);
  return (0);
}

int     compute_line(t_data *data, char *line)
{
  int   code;

  if (pre_check(line))
    return (0);
  if ((code = compute(data, line)) != 0)
    return (code);
  return (0);
}
