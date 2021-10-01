#include "libft.h"

char	**ms_setenv(char *name, char *value, char **envp_ms)
{
	int		index;
	char	*new_line;
	int		done;
	char	**temp;

	index = 0;
	done = 0;
	while (envp_ms[index])
	{
		if (ft_strncmp(envp_ms[index], name, ft_strlen(name)) == 0)
		{
			new_line = ft_strjoin(name, value);
			free(envp_ms[index]);
			envp_ms[index] = ft_strdup(new_line);
			free(new_line);
			done++;
		}
		index++;
	}
	if (done == 0)
	{
		new_line = ft_strjoin(name, value);
		temp = ft_addline(envp_ms, new_line);//addline not working
		ft_free_tab(envp_ms);
		envp_ms = ft_matrice_cpy(temp);
		ft_print_matrice(envp_ms);
		free (new_line);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char **matrice;
	char	**temp;
	int		index = 0;

	argc++;
	argv++;
	matrice = ft_matrice_cpy(envp);
	while (matrice[index])
	{
		printf("%s\n", matrice[index]);
		index++;
	}
	//ms_setenv("NAME=", "ALLLO", matrice);
	//ft_print_matrice(matrice);
}