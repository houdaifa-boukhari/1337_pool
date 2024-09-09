#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	char		**cmds;
	struct s_cmd *next;
}				t_cmd;

typedef struct s_cmds
{
	char    		**cmds;
	t_cmd			*cmd;
	struct	s_cmds	*next;
}           		t_cmds;

typedef struct s_fd
{
	int fd_in;
	int	fd_out;
	int save_in;
	int fd[2];
	int	pid;
}           t_fd;

char	**parsing(char **cmds, int *c);

int count_allocation(char **str, char *c, int *i)
{
	int count;
	int	j;

	count = 0, j = 0;
	while (str[j])
	{
		if (strcmp(str[j], c) == 0)
			break ;
		count++;
		j++;
		(*i)++;
	}
	return (count);
}

int count_arrays(char **cmd)
{
	int i = 0;
	if (!cmd || !*cmd)
		return (0);
	while (cmd[i])
		i++;
	return (i);
}
int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void creat_list(t_cmd **head, char **cmd)
{
	t_cmd 	*ptr;
	t_cmd	*new_node;

	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_node)
		return ;
	new_node->cmds = cmd;
	new_node->next = NULL;
	if (!*head)
	{
		(*head) = new_node;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
}

t_cmd *more_parsing(char **cmds, t_cmd **cmd)
{
	int idx = 0, count = 0, j = 0, i = 0,  len = count_arrays(cmds);
	char	**new_str;

	while (idx < len)
	{
		j = idx;
		count = count_allocation(cmds + idx, "|", &idx);
		new_str = malloc(sizeof(char *) * (count + 1));
		if (!new_str)
			return (NULL);
		i = 0;
		while (cmds[j] && i < count)
		{
			new_str[i++] = cmds[j];
			j++;
		}
		new_str[i] = NULL;
		creat_list(cmd, new_str);
		idx++;
	}
	return (*cmd);
}

void creat_cmd(t_cmds **head, char **cmd, int *count)
{
	t_cmds 	*ptr;
	t_cmd	*cmd_;
	t_cmds	*new_node;

	cmd_ = NULL;
	new_node = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new_node)
		return ;
	new_node->cmds = parsing(cmd + *count, count);
	more_parsing(new_node->cmds, &cmd_);
	new_node->cmd = cmd_;
	new_node->next = NULL;
	if (!*head)
	{
		(*head) = new_node;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
}
int	count_cmds(t_cmd *cmd)
{
	int	i = 0;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return i;
}

void	ft_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}
int *allocation_array(int size)
{
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	int i =0;
	while (i < size)
		tab[i++] = 0;
	return (tab);
}

bool	is_blt(char **cmd)
{
	int	count = count_arrays(cmd);
	if (strcmp(cmd[0], "cd") != 0)
		return (false);
	if (count != 2)
	{
		ft_error("error: cd: bad arguments\n");
		return (true);
	}
	int st = chdir(cmd[1]);
	if (st < 0)
	{
		ft_error("error: cd: cannot change directory to path_to_change\n");
		return (true);
	}
	return (true);
}

void	controle_fd(t_cmd *cmds, t_fd *fd)
{
	if (fd->fd_in != 0)
	{
		dup2(fd->fd_in, STDIN_FILENO);
		close(fd->fd_in);
	}
	close(fd->fd[0]);
	if (cmds->next)
		dup2(fd->fd[1], STDOUT_FILENO);
	else
		dup2(fd->fd_out, STDOUT_FILENO);
	close(fd->fd[1]);
}

int	execut_(t_cmd *cmds, char **envp, t_fd fd)
{
	int	i;
	int size;
	int	*pids;
	int	*fd_pipe;

	if (!cmds || !(cmds->cmds) || !*(cmds->cmds))
		return (0);
	if (is_blt(cmds->cmds))
		return (0);
	size = count_cmds(cmds);
	pids = allocation_array(size);
	fd_pipe = allocation_array(size);
	i = 0;
	while (cmds)
	{
		pipe(fd.fd);
		fd.pid = fork();
		if (fd.pid < 0)
		{
			perror("fork");
			i = 0;
			while (i < size)
			{
				if (fd_pipe[i] != 0)
					close(fd_pipe[i]);
				i++;
			}
			free(fd_pipe), free(pids);
		}
		if (fd.pid == 0)
		{
			controle_fd(cmds, &fd);
			execve(cmds->cmds[0], cmds->cmds, envp);
			free(fd_pipe), free(pids);
			ft_error("error: cannot execute ");
			ft_error(cmds->cmds[0]);
			ft_error("\n");
			exit(0);
		}
		else if (fd.pid > 0)
		{
			pids[i] = fd.pid;
			fd_pipe[i] = fd.fd[0];
			fd.fd_in = fd.fd[0];
			close(fd.fd[1]);
			i++;
			cmds = cmds->next;
		}
	}
	i = 0;
	while (i < size)
	{
		if (fd_pipe[i] != 0)
			close(fd_pipe[i]);
		i++;
	}
	i = 0;
	int status;
	while (i < size)
	{
		waitpid(pids[i++], &status, 0);
		status = WEXITSTATUS(status);
	}
	return (status);
}

char	**parsing(char **cmds, int *c)
{
	int	count = 0, i = 0, j = 0;
	char	**new_str;
	count = count_allocation(cmds, ";", c);
	new_str = malloc(sizeof(char *) * (count + 1));
	if (!new_str)
		return (NULL);
	while (cmds[j] && i < count)
		new_str[i++] = cmds[j++];
	new_str[i] = NULL;
	return (new_str);
}

int main(int ac, char **av, char **envp)
{
	int		count;
	int status = 0;
	t_cmds	*cmds;
	t_fd	fd;

	cmds = NULL;
	count = 1;
    if (strcmp(av[ac - 1], "|") == 0)
        return (0);
	while (count < ac)
	{
		creat_cmd(&cmds, av, &count);
		count++;
	}
	while (cmds)
	{
		fd.fd_in = STDIN_FILENO;
		fd.fd_out = STDOUT_FILENO;	
		status = execut_(cmds->cmd, envp, fd);

		cmds = cmds->next;
	}
	return (status);
}
