/*
** tokenize.c for token in /home/alies_a/rendu/PSU_2015_minishell2/src
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar 14 17:55:10 2016 alies_a
** Last update Wed Mar 16 17:42:04 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static t_parse func[] =
  {
    {&tok_str, 's'},
    {&tok_pipe, '|'},
    {&tok_right_simple, '>'},
    {&tok_left_simple, '<'},
    {&tok_default, 's'},
    {NULL, 0}
  };

int     tok_default(const char *line)
{
  (void)line;
  return (1);
}

static t_token	*next_token(const char *line,
			    int *pos)
{
  t_token	*token;
  int		x;
  int		res;

  res = 0;
  x = 0;
  if ((token = malloc(sizeof(t_token))) == NULL)
    return (NULL);
  while (func[x].func != NULL && res <= 0)
    {
      res = func[x].func(line + *pos);
      x += 1;
    }
  x -= 1;
  if (res <= 0)
    return (NULL);
  token->type = func[x].type;
  if ((token->str = malloc(sizeof(char) * (res + 1))) == NULL)
    return (NULL);
  my_strncpy(token->str, line + *pos, res + 1);
  *pos += res;
  return (token);
}

t_token		*tokenize(const char *line)
{
  t_token	*start;
  t_token       *tmp;
  int		len;
  int		x;

  len = my_strlen(line);
  x = 0;
  if ((start = next_token(line, &x)) == NULL)
    return (NULL);
  tmp = start;
  start->prev = NULL;
  while (x < len)
    {
      if ((tmp->next = next_token(line, &x)) == NULL)
	return (NULL);
      (tmp->next)->prev = tmp;
      tmp = tmp->next;
    }
  tmp->next = NULL;
  return (start);
}
