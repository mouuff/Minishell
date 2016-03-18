/*
** cl_str.c for cl in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 14:22:20 2016 alies_a
** Last update Fri Mar 18 14:22:42 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int     cl_str(t_token *tok)
{
  char  *buff;

  buff = tok->str;
  (tok->str)[my_strlen(tok->str) - 1] = '\0';
  if ((tok->str = my_strdup(tok->str + 1)) == NULL)
    return (1);
  free(buff);
  return (0);
}
