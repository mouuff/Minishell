/*
** delimiter.c for delimiter in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 16:33:07 2016 alies_a
** Last update Wed Mar 16 16:34:02 2016 alies_a
*/

int	is_delimiter(char c)
{
  if (c == '\t' ||
      c == ' ')
    return (1);
  return (0);
}
