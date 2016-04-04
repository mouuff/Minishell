/*
** tok_redirect.c for redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 16:47:38 2016 alies_a
** Last update Mon Apr  4 14:54:37 2016 alies_a
*/

#include "mysh.h"
#include "my.h"

static int	tok_redirect(const char *line,
			     char *type)
{
  int   x;

  if (my_strlen(line) == 0 ||
      my_strmou(line, type) != 0)
    return (0);
  x = my_strlen(type);
  while (line[x] != '\0' && (line[x] == ' ' || line[x] == '\t'))
    x += 1;
  while (line[x] != '\0' && !is_delimiter(line[x]))
    x += 1;
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

int     tok_right_double(const char *line)
{
  return (tok_redirect(line, ">>"));
}

int     tok_left_double(const char *line)
{
  return (tok_redirect(line, "<<"));
}
