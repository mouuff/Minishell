/*
** my_strncpy.c for strncpy in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 15 20:20:17 2016 alies_a
** Last update Tue Mar 15 20:21:32 2016 alies_a
*/

void	my_strncpy(char *dest,
		   const char *from,
		   int n)
{
  int	x;

  x = 0;
  while (from[x] != '\0' && x < n)
    {
      dest[x] = from[x];
      x += 1;
    }
}
