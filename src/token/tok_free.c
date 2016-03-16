/*
** tok_free.c for tok free in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 17:20:15 2016 alies_a
** Last update Wed Mar 16 18:07:31 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

static void	token_free(t_token *tok)
{
  free(tok->str);
  free(tok);
}

void		tokens_free(t_token **start)
{
  t_token	*tmp;
  t_token	*old;

  tmp = *start;
  while (tmp != NULL)
    {
      old = tmp;
      tmp = tmp->next;
      token_free(old);
    }
}
