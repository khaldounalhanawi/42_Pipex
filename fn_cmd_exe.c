#include "pipex.h"

static int	free_mult_arr(char **arr, char **arr2)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free (arr[i++]);
		free (arr);
	}
	if (arr2)
	{
		i = 0;
		while (arr2[i])
			free (arr2[i++]);
		free (arr2);
	}
	return (-1);
}

static char	*merge_name(char *paths, char *name)
{
	char	*address;
	char	*temp;

	address = ft_strjoin(paths, "/");
	if (!address)
		return (NULL);
	temp = address;
	address = NULL;
	address = ft_strjoin(temp, name);
	free (temp);
	if (!address)
		return (NULL);
	return (address);
}

static char	*inspect_paths(char **paths, char *name)
{
	char	*address;

	address = NULL;
	while (*paths)
	{
		if (ft_strrchr (name, '/'))
		{
			if (access (name, X_OK) == 0)
				return (ft_strdup (name));
		}
		address = merge_name (*paths, name);
		if (!address)
			return (NULL);
		if (access (address, X_OK) == 0)
			return (address);
		free (address);
		paths ++;
	}
	return (NULL);
}

int	cmd_exe(char *cmd, char **envp)
{
	char	**arr;
	char	**paths;
	char	*address;

	paths = extract_envp (envp);
	if (!paths)
		return (-1);
	arr = ft_split (cmd, ' ');
	if (!arr)
	{
		free_mult_arr (paths, NULL);
		return (-2);
	}
	address = inspect_paths (paths, arr[0]);
	if (!address)
		return (free_mult_arr (arr, paths));
	if (execve (address, arr, envp) == -1)
	{
		free (address);
		return (free_mult_arr(arr, paths));
	}
	return (0);
}
