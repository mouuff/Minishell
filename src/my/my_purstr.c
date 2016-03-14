/*
** my_purstr.c for purstr in /home/alies_a/rendu/PSU_2015_minishell1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 22 14:49:07 2016 alies_a
** Last update Fri Jan 22 16:34:12 2016 alies_a
*/

static void     purstr_loop(char *str, int x, int *off, int *space)
{
  if (str[x] == ' ' || str[x] == '\t')
    {
      *off += 1;
      *space = 1;
    }
  else
    {
      if (*space)
	{
	  if (x - *off > 0)
	    {
	      str[x - *off] = ' ';
	      *off -= 1;
	    }
	  *space = 0;
	}
      str[x - *off] = str[x];
    }
  x += 1;
}

void    my_purstr(char *str)
{
  int   x;
  int   off;
  int   space;

  space = 0;
  off = 0;
  x = 0;
  while (str[x] != '\0')
    {
      purstr_loop(str, x, &off, &space);
      x += 1;
    }
  str[x - off] = '\0';
}
