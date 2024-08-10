
#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1,&s[i],1);
		i++;
	}
}

static int ft_strlenc(char *s)
{
	int i;
	int sn;

	i = 0;
	sn = 0;
	while(s[i])
	{
		if (s[i] == '_')
			sn++;
		i++;
	}
	i -=sn;
	return (i);
}

char *s_t_c(char *s)
{
	char *camel;
	int i;
	int j;
	
	i = 0;
	j = 0;
	camel = malloc((ft_strlenc(s)+1) * sizeof(char));
	if (camel == NULL)
		return(NULL);
	while(s[i])
	{
		if (s[i] == '_')
		{
			i++;
			camel[j] = s[i]-32;
		}
		else
		camel[j] = s[i];
		i++;
		j++;
	}
	ft_putstr(camel);
	free(camel);
	return(camel);
}

int main(int ac, char *av[])
{
	if (ac == 2)
		s_t_c(av[1]);
	write(1,"\n",1);
	return(0);
}
