/*
** tok_str.c for tok in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar 14 20:23:46 2016 alies_a
** Last update Mon Mar 14 20:27:21 2016 alies_a
*/

int     tok_str(const char *line)
{
  int	x;

  if (line[0] != '"')
    return (0);
  x = 1;
  while (line[x] != '\0')
    {
      if (line[x] == '"')
	return (x);
      x += 1;
    }
  return (-1);
}
