/*
** compute.c for compute line in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Jan  7 14:14:30 2016 Arnaud Alies
** Last update Mon Apr  4 14:54:26 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"


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
      my_array_show(start->args);
      printf("i: %s o: %s\n",
	     start->rd[IN].file, start->rd[OUT].file);
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

int     	compute(t_data *data, char *line)
{
  t_cmp		*res;
  t_token	*tokens;
  int		code;

  if ((tokens = tokenize(line)) == NULL)
    return (1);
  if (cl_tokens(tokens))
    return (1);
  //show_tok(tokens);
  //printf("\n-----------------\n");
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
  //show_cmp(res);
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
