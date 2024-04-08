/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 17:01:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/08 18:40:13 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_check(t_info *info, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	command_check(t_info *info, char *cmd, char **envp)
{
	char	*path;
	char	**path_split;
	char	*cmd_path;
	
	int		i = 0;

	path = path_check(info, envp); // CAN BE IN MAIN - DOES NOT NEED TO BE CHECKED FOR EVERY CHILD
	if (path == NULL)
		... // Free necessary things and kill child
	path_split = ft_split(path, ':');
	if (path_split == NULL)
		... // Free necessary things and kill child
	cmd_path = ft_strjoin(path_split[i], info->cmds->str[0]); // DON'T FORGET THE /
	while (access(cmd_path, F_OK) == -1 && path_split[i] != NULL) // CHECK mode - man 3 access
	{
		cmd_path = ft_strjoin(path_split[i], info->cmds->str[0]);
		i++;
	}
	if (path_split[i] == NULL)
		... // Free necessary things and kill child
	

}





// forking(char *argv)
// {
// 	const int pid = fork();
	
// 	if (pid == 0)
// 		child_proc(argv)
// 	else
// 		parent()		
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	while (argc)
// 	{
// 		forking(argv[i]);

// 	}
// }