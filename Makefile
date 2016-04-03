##
## Makefile for minishell in /home/alies/rendu/PSU_2015_minishell1
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Mon Jan  4 14:04:11 2016 Arnaud Alies
## Last update Sun Apr  3 13:02:44 2016 alies_a
##

NAME    =       mysh

CC	=	gcc -g

SRC	=	./src/

ENV	=	./src/env/

MY	=	./src/my/

DATA	=	./src/data/

PARSE	=	./src/parse/

BUILTIN	=	./src/builtin/

EXEC	=	./src/exec/

SIG	=	./src/signal/

TOK	=	./src/token/

INCPATH	=	./include/

CFLAGS	=	-I$(INCPATH) \
		-Wall -Wextra -W

SRCS	=	$(SRC)main.c \
		$(SRC)compute.c \
		$(SRC)cleanup.c \
		$(SRC)stat.c \
		$(TOK)tokenize.c \
		$(TOK)delimiter.c \
		$(TOK)tok_str.c \
		$(TOK)tok_pipe.c \
		$(TOK)tok_redirect.c \
		$(TOK)tok_free.c \
		$(TOK)cmp_str.c \
		$(TOK)cmp_redirect.c \
		$(TOK)cmp_pipe.c \
		$(TOK)cmp.c \
		$(TOK)cmp_free.c \
		$(TOK)cl_str.c \
		$(TOK)cl_redirect.c \
		$(TOK)cl_no.c \
		$(TOK)cl.c \
		$(SIG)sig.c \
		$(SIG)sig_handler.c \
		$(EXEC)exec.c \
		$(EXEC)get_exec.c \
		$(EXEC)redirect.c \
		$(EXEC)pipe_it.c \
		$(EXEC)run_builtin.c \
		$(EXEC)fd_backup.c \
		$(EXEC)std_input.c \
		$(EXEC)rdr_fork.c \
		$(PARSE)preparse.c \
		$(PARSE)parse.c \
		$(PARSE)cmp_parse.c \
		$(PARSE)parse_empty_args.c \
		$(PARSE)parse_ambig.c \
		$(PARSE)parse_redirect.c \
		$(BUILTIN)check.c \
		$(BUILTIN)b_env.c \
		$(BUILTIN)b_exit.c \
		$(BUILTIN)b_cd.c \
		$(BUILTIN)b_doge.c \
		$(ENV)find_env.c \
		$(ENV)setenv.c \
		$(ENV)parse_setenv.c \
		$(ENV)unsetenv.c \
		$(DATA)init_data.c \
		$(DATA)free_data.c \
		$(MY)get_next_line.c \
		$(MY)my_char_add.c \
		$(MY)my_char_append.c \
		$(MY)my_char_count.c \
		$(MY)my_putchar.c \
		$(MY)my_puterr.c \
		$(MY)my_putstr.c \
		$(MY)my_array_show.c \
		$(MY)my_array_len.c \
		$(MY)my_array_append.c \
		$(MY)my_array_free.c \
		$(MY)my_array_cpy.c \
		$(MY)my_array_dup.c \
		$(MY)my_array_add.c \
		$(MY)my_array_del.c \
		$(MY)my_strcpy.c \
		$(MY)my_strdup.c \
		$(MY)my_strlen.c \
		$(MY)my_strcmp.c \
		$(MY)my_str_join.c \
		$(MY)my_str_isalpha.c \
		$(MY)my_str_split.c \
		$(MY)my_str_to_nbr.c \
		$(MY)my_purstr.c \
		$(MY)my_strncpy.c \
		$(MY)my_strdcpy.c \
		$(MY)my_memset.c \
		$(MY)my_strmou.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		check $(NAME)

check:
		@./src/exec/check &

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
