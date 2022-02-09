/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:53:23 by soum              #+#    #+#             */
/*   Updated: 2022/02/09 17:48:29 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_m_list
{
	struct s_cmd	*content;
	struct s_m_list	*next;
}t_m_list;

typedef struct s_cmd
{
	char	**cmdline;
	int		flag;
	char	quote;
	int		fd[2];
	int		out;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	int			status;
	char		*cmd_set;
	t_m_list	*lstlast;
	t_env		*env;

}	t_data;

extern int	g_status;

//cd.c
t_env		*find_env(char *key, t_env *env);
void		add_env(t_env *env, char *key, char *value);
void		ch_env(t_env *env, char *key, char *value);
void		ft_chdir(char *dest, t_env *env);
void		ft_cd(t_cmd *cmd, t_env *env);

//check_cmd.c
int			pipe_error_check2(t_m_list *tmp, int flag);
int			pipe_error_check(t_data *data);
int			check_cmd(t_data *data);

//env.c
t_env		*new_env(char *envline);
int			get_envlen(char **env);
t_env		*init_env(char **envp);
int			env_num(t_env *env);
char		**make_envp(t_env *env);

//env_util.c
int			get_keylen(char *str);
char		*replace_dollar(char *str, t_env *env);

//error.c
void		error_msg(char *str);
void		syntax_error_msg(char let);

//execute.c
void		exec_extern(t_cmd *cmd, char **env);
void		execute_extern(t_cmd *cmd, char **env);
void		execute_cmd(t_data *data, t_cmd *cmd, t_env *env, int flag);
void		execute_list(t_m_list *list, t_data *data, \
		int b_stdin, int b_stdout);
void		execute(t_data *data, t_m_list *list);

//exit.c
int			is_numeric(char *str);
void		ft_exit(t_cmd *cmd, int flag, t_data *data);

//export.c
void		print_export(t_env *env);
void		print_not_valid(char *cmd, char *str);
void		ft_export(t_cmd *cmd, t_env *env);

//free_list.c
void		free_env_list(t_data *data);
void		free_envp(char **env);
void		free_cmd_data(t_cmd *content);
void		free_cmd_list(t_data *data);

//init_shell.c
void		init_cmd(t_cmd *cmd_data, char *cmd, char let);
void		init_struct(t_data *data, char **envp);
void		sigint_handler(int signal);
void		sigquit_handler(int signal);
void		setting_signal(void);

//parsing_cmd.c
void		put_in_cmd(t_data *data, char *cmd, char let);
int			parsing_proc(t_data *data, char *tmp);
void		parsing(t_data *data);

//parsing_util.c
int			quote_index(char *cmd, char let, int *index);
char		*put_in_cmdline(char *cmd, char let, int *i);
char		*put_in_cmdline_normal(char *cmd, char let, int *i);
int			find_quote_match(char *tmp, int i);

//pipe.c
void		child(t_m_list *list, t_data *data);
void		create_child(t_m_list *list, t_data *data, int prev);

//prompt.c
void		show_prompt(t_data *data);

//quote.c
int			key_len(char *str);
char		*dollar_sing(char *cmdline, t_env *env);
char		*mixed_quote(char *cmdline, t_env *env);
char		*double_quote(char *cmdline, t_env *env);
char		*single_quote(char *cmdline);

//quote_split.c
int			sep_cnt_quote(char *cmd, char c);
void		putin(char *cmd, char *cmdline, int from, int i);
void		sep_cmdline(char *cmd, char c, char **cmdline);
char		**quote_split(char *cmd, char c);

//rd_util.c
int			rd_in(char *file);
int			rd_out(char *file);
int			rd_double_out(char *file);
void		heredoc(char *end);
int			find_rd_type(char *rd);

//redirection.c
int			redirection(char *file, int type, int dup_out, int out);
int			cmd_cnt(t_cmd *cmd);
void		print_rd_error(t_cmd *cmd, int status, char *cmdtype);
int			redirect(t_cmd *cmd, char **cmdline, \
		char **new_cmdline, int dup_out);
int			rd_handler(t_cmd *cmd);

//reparsing_cmd.c
void		reparsing_env(t_data *data);
char		*cmdline_change(char *cmdline, t_env *env);

//unset.c
int			ft_strcmp(const char *s1, const char *s2);
void		free_cnv(t_env *cur);
void		delete_env(t_env **env, char *key, t_data *data);
void		ft_unset(t_cmd *cmd, t_env *env, t_data *data);

//util.c
char		*ft_strjoin_free(char *s1, char *s2);
#endif
