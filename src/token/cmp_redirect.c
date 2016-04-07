/*
** cmp_redirect.c for redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 11:00:47 2016 alies_a
** Last update Thu Apr  7 10:30:03 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int	cmp_left_simple(const t_token *tok, t_cmp **cmp)
{
  if ((*cmp)->rd[IN].file != NULL)
    {
      if ((*cmp)->ambiguous == 0)
	(*cmp)->ambiguous = AIN;
    }
  else if (((*cmp)->rd[IN].file = my_strdup(tok->str)) == NULL)
    return (1);
  (*cmp)->rd[IN].type = '<';
  return (0);
}

int	cmp_right_simple(const t_token *tok, t_cmp **cmp)
{
  if ((*cmp)->rd[OUT].file != NULL)
    {
      if ((*cmp)->ambiguous == 0)
	(*cmp)->ambiguous = AOUT;
    }
  else if (((*cmp)->rd[OUT].file = my_strdup(tok->str)) == NULL)
    return (1);
  (*cmp)->rd[OUT].type = '>';
  return (0);
}

int	cmp_right_double(const t_token *tok, t_cmp **cmp)
{
  if ((*cmp)->rd[OUT].file != NULL)
    {
      if ((*cmp)->ambiguous == 0)
	(*cmp)->ambiguous = AOUT;
    }
  else if (((*cmp)->rd[OUT].file = my_strdup(tok->str)) == NULL)
    return (1);
  (*cmp)->rd[OUT].type = '}';
  return (0);
}

int	cmp_left_double(const t_token *tok, t_cmp **cmp)
{
  if ((*cmp)->rd[IN].file != NULL)
    {
      if ((*cmp)->ambiguous == 0)
	(*cmp)->ambiguous = AIN;
    }
  else if (((*cmp)->rd[IN].file = my_strdup(tok->str)) == NULL)
    return (1);
  (*cmp)->rd[IN].type = '{';
  return (0);
}
