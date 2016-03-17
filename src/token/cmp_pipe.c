/*
** cmp_pipe.c for cmp_pipe in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 11:05:30 2016 alies_a
** Last update Thu Mar 17 14:06:46 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

int     cmp_pipe(const t_token *tok, t_cmp **cmp)
{
  (void)tok;
  if (((*cmp)->next = new_cmp()) == NULL)
    return (1);
  ((*cmp)->next)->prev = (*cmp);
  (*cmp) = (*cmp)->next;
  return (0);
}
