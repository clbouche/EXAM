#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **env;
int ret;
int fd[2];

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_print(char *str, char *s2)
{
	write(2, str, ft_strlen(str));
	if (s2)
		write(2, s2, ft_strlen(s2));
	write(2, "\n", 1);
	return 1;
}

void ft_cd(char **av, int i)
{
	if (i != 2)
		ft_print("error: cd: bad arguments", NULL);
	else if (chdir(av[1]) != 0)
		ft_print("error: cd: cannot change directory to ", av[1]);
}

int ft_handle_ends(char **av, int i, int *tmp)
{
	int pid = fork();
	if (pid == 0)
	{
		av[i] = NULL;
		dup2(*tmp, STDIN_FILENO); /* L'input standard devient fd[0] si y a eu des cmd avant, ou STDIN normal si rien */
		close(*tmp);
		if (execve(av[0], av, env) != 0)
			return(ft_print("error: cannot execute ", av[0]));
	}
	else
	{
		close(*tmp);
		waitpid(-1, &ret, 0); // wait for any child process
		*tmp = dup(STDIN_FILENO);
	}
	return 0;
}

int ft_handle_pipes(char **av, int i, int *tmp)
{

	pipe(fd);
	int pid = fork();
	if (pid == 0) // CHILD
	{
		av[i] = NULL;				/* 		L'endroit ou pipe devient NULL */
		dup2(*tmp, STDIN_FILENO);	/* 		L'input standard devient tmp, qui vaut input standard au premier appel
											ou fd[0] si y a deja eu pipe */
		dup2(fd[1], STDOUT_FILENO); /*  	L'output devient le fd[1], writing end du pip */
		close(fd[0]);
		close(fd[1]);
		close(*tmp);
		if (execve(av[0], av, env) != 0)
			return (ft_print("error: cannot execute ", av[0]));
	}
	else // PARENT
	{
		close(fd[1]);
		close(*tmp);
		waitpid(-1, &ret, 0); // WAIT ANY CHILD PROCESS
		*tmp = dup(fd[0]);			/* Tmp stocke mtn fd[0] aka reading end du pipe, en prevision de prochaine cmd */
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
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0; // reinitialiser i à 0 pour pouvoir ensuite l'incrémenter et trouver sa nouvelle position
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			i++;
		if (av[0] && strcmp(av[0], "cd") == 0)
			ft_cd(av, i);
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
			ft_handle_ends(av, i, &tmp);
		else if (i != 0 && strcmp(av[i], "|") == 0)
			ft_handle_pipes(av, i, &tmp);
	}
	close(tmp);
	return (0);
}
