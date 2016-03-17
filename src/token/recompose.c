/*
** recompose.c for recompose in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 10:00:15 2016 alies_a
** Last update Thu Mar 17 13:31:11 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

t_cmd	*new_cmd()
{
  t_cmd	*res;

  if ((res = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  my_memset(res, 0, sizeof(t_cmd));
  if ((res->args = my_strdup("")) == NULL)
    return (NULL);
  return (res);
}

t_cmd		*recompose(const t_token *tok)
{
  t_cmd		*start;
  t_cmd		*tmp;
  t_parse	func;

  if ((start = new_cmd()) == NULL)
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
