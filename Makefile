RED		=	\033[0;31m

YELLOW	=	\033[0;33m

GREEN	=	\033[0;32m

NC		=	\033[0m

CC		=	gcc

NAME	=	minishell

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-L ./$(LIBFT) -lft -ltermcap

LIBFT	=	libft

LIBRARY	=	./libft/libft.a

HDRS	=	includes

SRCDIR = srcs

BUILDDIR = objs

EXEC_DIR = $(BUILDDIR)/executor

REAL_PARSE_DIR = $(BUILDDIR)/real_parser

TERM_DIR = $(BUILDDIR)/terminal_work

PARSER_DIR = $(BUILDDIR)/parser

UTILS_DIR = $(BUILDDIR)/programm_utils

SRCS_EXEC = srcs/executor/exec_command.c \
			srcs/executor/exec_some_cmd.c \
			srcs/executor/exec_specific_cmd.c \
			srcs/executor/search_in_path.c \
			srcs/executor/ft_builtin_1.c \
			srcs/executor/ft_export.c \
			srcs/executor/ft_unset.c \
			srcs/executor/ft_cd.c \
			srcs/executor/pid_utils.c \
			srcs/executor/builtin_utils.c \
			srcs/executor/ft_signal.c

SRCS_REAL_PARSE =	srcs/real_parser/real_parser.c \
					srcs/real_parser/parser_utils.c \
					srcs/real_parser/spec_sim.c \
					srcs/real_parser/fill_false_smpl_cmnd.c \
					srcs/real_parser/proc_redirect.c

SRCS_TERM	=	srcs/terminal_work/term_work.c \
				srcs/terminal_work/up_response.c \
				srcs/terminal_work/receive_str.c \
				srcs/terminal_work/reaction_on_input.c \
				srcs/terminal_work/down_response.c \
				srcs/terminal_work/ctrl_d_response.c \
				srcs/terminal_work/backspace_response.c \
				srcs/terminal_work/restore_term.c \
				srcs/terminal_work/define_str.c \
				srcs/terminal_work/receive_str_utils.c

SRCS_PARSER	=	srcs/parser/parser.c \
				srcs/parser/create_arr_all_arg.c \
				srcs/parser/create_arr_all_comd.c \
				srcs/parser/get_argument.c \
				srcs/parser/path_proccesing.c \
				srcs/parser/shielding_proccesing.c \
				srcs/parser/single_quote_proccesing.c \
				srcs/parser/double_quote_proccesing.c \
				srcs/parser/error_lexer.c 

SRCS_UTILS 	=	srcs/programm_utils/error_message.c \
				srcs/programm_utils/arr_utils_1.c \
				srcs/programm_utils/arr_utils_2.c \
				srcs/programm_utils/str_utils.c \
				srcs/programm_utils/comand_utils.c \
				srcs/programm_utils/envp_utils.c \
				srcs/programm_utils/add_symbol.c \
				srcs/programm_utils/del_symbol.c

SRCS = $(SRCS_EXEC) $(SRCS_TERM) $(SRCS_PARSER) $(SRCS_REAL_PARSE) $(SRCS_UTILS) srcs/main.c

OBJS	=	$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.c=.o))

DIRS	=	$(BUILDDIR) $(EXEC_DIR) $(REAL_PARSE_DIR) $(UTILS_DIR) $(TERM_DIR) $(PARSER_DIR)


RM		=	rm -f

all:	$(NAME)

$(NAME):	$(LIBRARY) $(OBJS)
		@echo "$(YELLOW)MAKING minishel from objs$(NC)"
		@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
		@echo "$(GREEN)DONE$(NC)"

$(OBJS):	|$(DIRS)

$(BUILDDIR):
		@echo "$(YELLOW)START making objs$(NC)"
		mkdir $(BUILDDIR)

$(EXEC_DIR): |$(BUILDDIR)
		mkdir $(EXEC_DIR)

$(REAL_PARSE_DIR): |$(BUILDDIR)
		mkdir $(REAL_PARSE_DIR)

$(UTILS_DIR): |$(BUILDDIR)
		mkdir $(UTILS_DIR)

$(TERM_DIR): |$(BUILDDIR)
		mkdir $(TERM_DIR)

$(PARSER_DIR): |$(BUILDDIR)
		mkdir $(PARSER_DIR)

$(LIBRARY):
		@echo "$(YELLOW)START making libft$(NC)"
		@make --jobs=4 -C $(LIBFT)
		@echo "$(GREEN)MAKING libft is SUCCESS$(NC)"

$(BUILDDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(HDRS) -c $^ -o $@


clean:
		@$(RM) -r $(BUILDDIR)
		@echo "$(RED)Delete objs dir$(NC)"
		@make clean -C $(LIBFT)

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(RED)Delete minishell bin$(NC)"
		@$(RM) $(LIBRARY)
		@echo "$(RED)Delete libft.a lib$(NC)"

re:		fclean all

run:	all
		./$(NAME)

.PHONY:	all clean fclean re run
