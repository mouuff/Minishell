/*
** tokenize.c for token in /home/alies_a/rendu/PSU_2015_minishell2/src
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar 14 17:55:10 2016 alies_a
** Last update Mon Mar 14 20:12:31 2016 alies_a
*/

#include "mysh.h"

static t_parse func[] =
  {
    {&tok_default, 'c'},
    {NULL, 0}
  };

int	tok_default(const char *line)
{
  int	x;
  int	y;
  int	res;

  res = 0;
  x = 0;
  while (line[x] != '\0' && res <= 0)
    {
      y = 0;
      while (func[y].func != NULL && res <= 0)
	{
	  res = func[y].func(line + x);  
	  y += 1;
	}
      x += 1;
    }
  return (x);
}


static t_token	*next_token(const char *line,
			    int *pos)
{
  
}

t_token		*tokenize(const char *line)
{
  t_token	*start;
  t_token       *tmp;
  int		len;
  int		x;

  if ((start = malloc(sizeof(t_token))) == NULL)
    return (NULL);
  tmp = start;
  start->prev = NULL;
  len = my_strlen(line);
  x = 0;
  while (x < len)
    {
      
    }
  return (start);
}
