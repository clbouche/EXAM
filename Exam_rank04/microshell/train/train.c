#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int	rtn;
int	fd[2];
char	**env;

int	ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return (i);
}

int	ft_print(char *s1, char *s2)
{
	write(2, s1, ft_strlen(s1));
	if (s2)
		write(2, s2, ft_strlen(s2));
	write(2, "\n", 1);
	return (1); 
}

void	ft_cd(char **av, int i)
{
	if (i != 2)
		ft_print("error: cd: bad argument", NULL);
	if (chdir(av[1]) != 0)
		ft_print("error: cd: cannot access to ", av[1]);
}

int	manage_ends(char **av, int i, int *tmp)
{
	int pid = fork();
	if (pid == 0)
	{
		av[i] = NULL;
		dup2(*tmp, STDIN_FILENO);
		close(*tmp);
		if (execve(av[0], av, env) != 0)
			return (ft_print("error: execve: executable ", av[0]));
	}
	else 
	{
		close(*tmp);
		waitpid(-1, &rtn, 0);
		*tmp = dup(STDIN_FILENO);
	}
	return (0);
}

int	manage_pipe(char **av, int i, int *tmp)
{
	pipe(fd);
	int pid = fork();
	if (pid == 0)
	{
		av[i] = NULL;
		dup2(*tmp, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(*tmp);
		if (execve(av[0], av, env) != 0)
			return (ft_print("error: execve: executable ", av[0]));
	
	}
	else
	{
		close(fd[1]);
		close(*tmp);
		waitpid(-1, &rtn, 0);
		*tmp = dup(fd[0]);
		close(fd[0]);
	}
	return 0;
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	env = envp;
	int tmp = dup(STDIN_FILENO);
	int i = 0;
	while(av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while(av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
			i++;
		if (av[0] && strcmp(av[0], "cd") == 0)
			ft_cd(av, i);
		else if (i != 0 && (strcmp(av[i], ";") == 0 || av[i] == NULL))
			manage_ends(av, i, &tmp);
		else if (i != 0 && strcmp(av[i], "|") == 0)
			manage_pipe(av, i, &tmp);
	}
	close(tmp);
	return 0;
}
