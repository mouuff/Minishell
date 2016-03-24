/*
** ambig.c for ambig in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 24 15:04:40 2016 alies_a
** Last update Thu Mar 24 16:05:13 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

int	parse_ambig_out(t_cmp *cmp)
{
  if (cmp->ambiguous == AOUT)
    return (1);
  if (cmp->next != NULL && cmp->rd[OUT].type != 0)
    return (1);
  return (0);
}

int	parse_ambig_in(t_cmp *cmp)
{
  if (cmp->ambiguous == AIN)
    return (1);
  if (cmp->prev != NULL && cmp->rd[IN].type != 0)
    return (1);
  return (0);
}
