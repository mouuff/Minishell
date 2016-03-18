/*
** cl.c for cl in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 14:26:43 2016 alies_a
** Last update Fri Mar 18 14:35:33 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		cl_tokens(t_token *tok)
{
  t_parse	curr;

  while (tok != NULL)
    {
      if (get_func(&curr, tok->type))
	return (1);
      if ((curr.clean)(tok))
	return (1);
      tok = tok->next;
    }
  return (0);
}
