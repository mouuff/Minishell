/*
** cmp_pipe.c for cmp_pipe in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 11:05:30 2016 alies_a
** Last update Thu Mar 17 11:36:41 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

int     cmp_pipe(const t_token *tok, t_cmd **cmd)
{
  if (((*cmd)->next = new_cmd()) == NULL)
    return (1);
  ((*cmd)->next)->prev = (*cmd);
  (*cmd) = (*cmd)->next;
  return (0);
}
