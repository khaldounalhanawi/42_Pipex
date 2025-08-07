#include "pipex.h"

static int	correct_first(char **arr)
{
	int	i;
	char	**splitted;

	i = 0;
	splitted = ft_split (arr[0], '=');
	if (!splitted)
		return (-1);
	free (arr[0]);
	arr[0] = ft_strdup (splitted [1]);
	if (!arr[0])
		return (-1);
	free (splitted [0]);
	free (splitted [1]);
	free (splitted [2]);
	free (splitted);
	return (0);
}

char	**extract_envp(char **envp)
{
	int		i = 0;
	char	*str;
	char	*working_path;
	char	**arr;

	str = NULL;
	while (*envp)
	{
		str = ft_strnstr(*envp, "PATH", 4);
		if (str)
		{
			arr = ft_split (str, ':');
			if (!arr)
				return (NULL);
			break ;
		}
		envp ++;
	}
	if (correct_first (arr) == -1)
		return (NULL);
	return (arr);
}