#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

char	**cmd;
int		i = 0;

//finir builtins cd 
//faire l'execution avec pipe 
//faire la gestion d'erreur

int		ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return (i);
}

int		ft_error(char *s)
{
	free(cmd);
	write(1, s, ft_strlen(s));
	exit(0);
}

int		size_cmd(char **cmd, char *found)
{
	if (!cmd)
		return 0;
	int i = -1;
	while(cmd[++i])
	{
		if (!(strcmp(cmd[i], found)))
			return (i);
	}
	return (i);
}

char	**split_cmd(char **arg, int size, int *i)
{
	cmd = NULL;
	if(!(cmd = malloc(sizeof(*cmd) * (size + 1))))
		ft_error("error\n");
	int j = -1;
	while(++j < size)
		cmd[j] = arg[j + *i];
	cmd[j] = NULL;
	*i += size;
	return (cmd);
}

char	**parsing(char **arg, int *i)
{
	int size = size_cmd(&arg[*i], ";");
	if (!size)
		return (NULL);
	cmd = split_cmd(arg, size, i);
	return (cmd);
}

int	exec_builtin(void)
{
	printf("BONJOUR BUILTINS : %s\n", cmd[1]);
	if (!cmd[1])
		ft_error("cd: bad arguments\n");
	if (chdir(cmd[1]) != 0)
		ft_error("cd: cannot change directory\n");
	return 0;
}

char	**check_pipe(char **cmd)
{
	if (!cmd)
		return (NULL);
	int i = -1;
	while(cmd[++i])
	{
		if (!strcmp(cmd[i], "|"))
			return (&cmd[i + 1]);
	}
	return (NULL);
}

void	exec_cmd(char **cmd, char **env)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		ft_error("error\n");	
	if (!pid)
	{
		if (!strcmp(cmd[0], "cd"))
			exec_builtin();
		else
		{
			if (execve(cmd[0], cmd, env) < 0)
				ft_error("error execve\n");
		}
	}
	waitpid(0, NULL, 0);
}

int exec_son(char** free_ptr, char** env, char** tmp, int fd_in, int fd_pipe[2])
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		ft_error("error 5\n");
	if (check_pipe(tmp) && dup2(fd_pipe[1], STDOUT_FILENO) < 0)
		ft_error("error 4\n");
	close(fd_in);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	tmp[size_cmd(tmp, "|")] = NULL;
	exec_cmd(tmp, env);
	free(free_ptr);
	exit(0);
}

void	execution(char **cmd, char **env)
{
	if (!check_pipe(cmd))
		return (exec_cmd(cmd, env));

	int fd_in;
	int fd_pipe[2];
	char **tmp = cmd;
	int nb_wait = 0;
	pid_t pid;

	if ((fd_in = dup(STDIN_FILENO)) < 0)
		ft_error("prout\n");
	while (tmp)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			ft_error("prout 2\n");		
		if (!pid)
			exec_son(cmd, env, tmp, fd_in, fd_pipe);		
		else
		{
			if (dup2(fd_pipe[0], fd_in) < 0)
				ft_error("prout 3\n");
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			++nb_wait;
			tmp = check_pipe(tmp);
		}
	}
}

int main(int argc, char **argv, char **env) 
{
	while (++i < argc)
	{
		cmd = parsing(argv, &i);
		execution(cmd, env);
		free(cmd);
		cmd = NULL;
	}
	return 0;
}
