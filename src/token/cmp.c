/*
** recompose.c for recompose in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 10:00:15 2016 alies_a
** Last update Thu Mar 17 14:06:21 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

t_cmp	*new_cmp()
{
  t_cmp	*res;

  if ((res = malloc(sizeof(t_cmp))) == NULL)
    return (NULL);
  my_memset(res, 0, sizeof(t_cmp));
  if ((res->args = my_strdup("")) == NULL)
    return (NULL);
  return (res);
}

t_cmp		*recompose(const t_token *tok)
{
  t_cmp		*start;
  t_cmp		*tmp;
  t_parse	func;

  if ((start = new_cmp()) == NULL)
    return (NULL);
  tmp = start;
  while (tok != NULL)
    {
      if (get_func(&func, tok->type))
	return (NULL);
      (func.recomp)(tok, &tmp);
      tok = tok->next;
    }
  return (start);
}
