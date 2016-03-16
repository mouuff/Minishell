/*
** tok_redirect.c for redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 16:47:38 2016 alies_a
** Last update Wed Mar 16 16:51:23 2016 alies_a
*/

#include "mysh.h"

static int	tok_redirect(const char *line,
			     char type)
{
  int   x;
  int   word;

  word = 0;
  if (line[0] != type)
    return (0);
  x = 1;
  while (line[x] != '\0' &&
	 !(word && is_delimiter(line[x])))
    {
      if (!is_delimiter(line[x]))
	word = 1;
      x += 1;
    }
  return (x);
}

int     tok_right_simple(const char *line)
{
  return (tok_redirect(line, '>'));
}

int     tok_left_simple(const char *line)
{
  return (tok_redirect(line, '<'));
}
