/*
** str_to_arg.h for str to arg in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 17:24:49 2016 Arnaud Alies
** Last update Tue Jan  5 17:31:47 2016 Arnaud Alies
*/

#ifndef STR_TO_ARG_H_
#define STR_TO_ARG_H_

typedef struct s_vars
{
  const char	*str;
  char		**res;
  int   	x;
  int   	pos;
  int   	par;
} t_vars;

#endif
