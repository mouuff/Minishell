/*
** compute.c for compute line in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:14:30 2016 Arnaud Alies
** Last update Thu Mar 17 14:07:36 2016 alies_a
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

#include <stdio.h>
void	show_tok(t_token *start)
{
  while (start != NULL)
    {
      printf("'%s' [%c]\n", start->str, start->type);
      start = start->next;
    }
}

void	show_cmp(t_cmp *start)
{
  while (start != NULL)
    {
      printf("arg> %s | i: %s o: %s\n",
	     start->args, start->input_file, start->output_file);
      start = start->next;
    }
}

int     	compute_line(t_data *data, char *line)
{
  t_token	*tokens;

  tokens = tokenize(line);
  show_tok(tokens);
  printf("\n-----------------\n");
  t_cmp *res;
  res = recompose(tokens);
  show_cmp(res);
  cmps_free(&res);
  tokens_free(&tokens);
  return (E_PASS);
}
