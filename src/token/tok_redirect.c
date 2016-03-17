/*
** tok_redirect.c for redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 16:47:38 2016 alies_a
** Last update Thu Mar 17 19:35:31 2016 alies_a
*/

#include "mysh.h"
#include "my.h"

static int	tok_redirect(const char *line,
			     char *type)
{
  int   x;
  int   word;

  word = 0;
  if (my_strmou(line, type) != 0)
    return (0);
  x = 1;
  while (line[x] != '\0' &&
	 !(word && is_delimiter(line[x])))
    {
      if (!is_delimiter(line[x]))
	word = 1;
      if (word && line[x] == '"')
	return (tok_str(line + x) + 2);
      x += 1;
    }
  return (x);
}

int     tok_right_simple(const char *line)
{
  return (tok_redirect(line, ">"));
}

int     tok_left_simple(const char *line)
{
  return (tok_redirect(line, "<"));
}
