#include "pipex.h"

static int	get_next(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	counter;
	int	len;

	i = 0;
	counter = 0;
	len = 0;
	while (s[len])
		len++;
	if (s[0] != c)
		counter++;
	if (s[0] == '\0')
		return (0);
	while (s[i] && i < len - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			counter++;
		i++;
	}
	return (counter);
}

static int	filler(char **origin, char **p, const char *s, int local_len)
{
	int	i;

	*p = malloc ((local_len + 1) * sizeof(char));
	if (!*p)
	{
		i = 0;
		while (origin[i])
		{
			free(origin[i]);
			i++;
		}
		free(origin);
		return (0);
	}
	ft_strlcpy(*p, s, local_len + 1);
	return (1);
}

static char	**body(int words, char const *s, char c)
{
	char	**p;
	char	**origin;

	p = malloc ((words + 1) * sizeof (char *));
	if (!p)
		return (NULL);
	origin = p;
	while (words--)
	{
		while (*s == c && *s)
			s++;
		if (!filler (origin, p, s, get_next(s, c)))
			return (NULL);
		s += get_next(s, c);
		p++;
	}
	*p = NULL;
	return (origin);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**p;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		p = malloc (sizeof (char *));
		if (!p)
			return (NULL);
		*p = NULL;
		return (p);
	}
	words = word_count(s, c);
	p = body (words, s, c);
	return (p);
}
/*
#include <stdio.h>

int main ()
{
    // char s[] = "    hey there        how are you       ";
    // char c = ' ';

    char s[] = "";
    char c = 97;

    // char s[] = "hhey there";
    // char c = 'h';

    // char s[] = "xxxxxxxxxxxxheyxxxxtherexxxxx";
    // char c = 'x';

    // char s[] = "       hey there";
    // char c = ' ';

    // char s[] = "e"; //	QUESTION?! empty string?? should?
    // char c = 'e';

    // char s[] = "  ";
    // char c = 'e';

    // char s[] = ""; 
    // char c = 'e';

    // char s[] = ",,hey,,,,how,are,things?,";
    // char c = ',';

    // char s[] = "hÉy thÉre i am"; // **** ASK
    // char c = 'É';

    char **k = ft_split(s, c);

    printf("%p\n", k);
    if (k)
	{   
		int i = 0;
	    while (k[i])
	    {
	        printf("%s\n",k[i]);
	        i++;
	    }
	}
    return (0);


}
*/
