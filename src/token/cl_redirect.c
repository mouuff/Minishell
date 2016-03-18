/*
** cl_redirect.c for cl_redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 13:52:44 2016 alies_a
** Last update Fri Mar 18 15:12:31 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int	cl_redirect(t_token *tok,
			    char type)
{
  char		*buff;
  int		x;

  x = 0;
  while (tok->str[x] != '\0' &&
	 (is_delimiter(tok->str[x]) ||
	  tok->str[x] == type))
    {
      x += 1;
    }
  buff = tok->str;
  if ((tok->str = my_strdup(tok->str + x)) == NULL)
    return (1);
  free(buff);
  return (0);
}

int	cl_right(t_token *tok)
{
  if (cl_redirect(tok, '>'))
    return (1);
  return (0);
}

int     cl_left(t_token *tok)
{
  if (cl_redirect(tok, '<'))
    return (1);
  return (0);
}
