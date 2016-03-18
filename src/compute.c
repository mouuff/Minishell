/*
** compute.c for compute line in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:14:30 2016 Arnaud Alies
** Last update Fri Mar 18 16:10:03 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*
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
  t_cmp *old;
  while (start != NULL)
    {
      my_array_show(start->args);
      printf("i: %s o: %s\n",
	     start->input_file, start->output_file);
      old = start;
      start = start->next;
    }
  /*
  printf("\n");
  start = old;
  while (start != NULL)
    {
      my_array_show(start->args);
      printf("i: %s o: %s\n",
	     start->input_file, start->output_file);
      start = start->prev;
    }
  */
}

int     	compute_line(t_data *data, char *line)
{
  t_token	*tokens;

  tokens = tokenize(line);
  cl_tokens(tokens);
  //show_tok(tokens);
  //printf("\n-----------------\n");
  t_cmp *res;
  res = recompose(tokens);
  cmps_parse(res);
  //show_cmp(res);

  launch_cmps(data, res, 0);
  
  cmps_free(&res);
  tokens_free(&tokens);
  return (E_PASS);
}
