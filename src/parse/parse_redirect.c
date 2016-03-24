/*
** parse_redirect.c for redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 24 18:44:34 2016 alies_a
** Last update Thu Mar 24 18:47:39 2016 alies_a
*/

#include "my.h"
#include "mysh.h"

int	parse_redirect(t_cmp *cmp)
{
  if (cmp->rd[IN].type != 0)
    {
      if (my_strlen(cmp->rd[IN].file) == 0)
	return (1);
    }
  if (cmp->rd[OUT].type != 0)
    {
      if (my_strlen(cmp->rd[OUT].file) == 0)
	return (1);
    }
  return (0);
}
