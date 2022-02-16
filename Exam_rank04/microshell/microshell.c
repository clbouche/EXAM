#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

char	**cmd;
int		i = 0;

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

char	**check_comma(char **arg, int *i)
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

char	**check_pipe(void)
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


int	exec_cmd(char **env)
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
	return (0);
}

void	exec_pipe(void)
{
	//il faut executer jusqu'au pipe en envoyant a exec_cmd
	printf("PIPEEEE\n");
}

int main(int argc, char **argv, char **env) 
{
	while (++i < argc)
	{
		cmd = check_comma(argv, &i);
		printf("i = %i\n", i);
		if (check_pipe())
			exec_pipe();
		else
			exec_cmd(env);
		free(cmd);
		cmd = NULL;
	}
	return 0;
}
