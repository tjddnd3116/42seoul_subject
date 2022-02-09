#include "../includes/minishell.h"
#include "../Libft/libft.h"

int	rd_in(char *file)
{
	int	newfd;

	newfd = open(file, O_RDONLY, 0644);
	if (newfd < 1)
		return (1);
	dup2(newfd, 0);
	close(newfd);
	return (0);
}

int	rd_out(char *file)
{
	int	newfd;

	newfd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (newfd < 1)
	{
		printf("minishell: %s: %s\n", file, strerror(errno));
		return (1);
	}
	dup2(newfd, 1);
	close(newfd);
	return (0);
}

int	rd_double_out(char *file)
{
	int	newfd;

	newfd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (newfd < 1)
	{
		printf("minishell: %s: %s\n", file, strerror(errno));
		return (1);
	}
	dup2(newfd, 1);
	close(newfd);
	return (0);
}

void	heredoc(char *end)
{
	char	*line;
	int		newfd;

	newfd = open("heredocfile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, end))
		{
			free(line);
			break ;
		}
		write(newfd, line, ft_strlen(line));
		write(newfd, "\n", 1);
	}
	close(newfd);
}

int	find_rd_type(char *rd)
{
	if (!ft_strcmp(rd, "<"))
		return (1);
	else if (!ft_strcmp(rd, ">"))
		return (2);
	else if (!ft_strcmp(rd, ">>"))
		return (3);
	else if (!ft_strcmp(rd, "<<"))
		return (4);
	else
		return (0);
}
