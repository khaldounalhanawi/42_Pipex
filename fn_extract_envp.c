#include "pipex.h"

char	**extract_envp(char **envp)
{
	char	*str;
	char	**arr;

	str = NULL;
	arr = NULL;
	while (*envp)
	{
		str = ft_strnstr(*envp, "PATH=", 5);
		if (str)
		{
			arr = ft_split (str + 5, ':');
			if (!arr)
				return (NULL);
			break ;
		}
		envp ++;
	}
	return (arr);
}