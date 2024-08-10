
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	write(1,s,i);
}

int count_words(char *s,char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if(s[i] != c && (s[i+1] == c || s[i+1] == '\0'))
			count++;
		i++;
	}
	//printf("count:%d\n",count);
	return(count);
}

char *substr(char *s,int start, int len)
{
	char *sub;
	int i;

	sub = malloc((len +1)*sizeof(char));
	i = 0;
	while(i<len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	//printf("|%s|\n",sub);
	return(sub);
}

char **rostring(char *s,char c)
{
	char **ro;
	int start;
	int i;
	int j;
	char *tmp;

	ro = malloc((count_words(s,c)+1)* sizeof(char*));

	i = 0;
	j = 0;
	while (s[i])
	{
		if(i > 0 && s[i] != c && s[i-1] == c)
			start = i;
		if(i == 0 && s[i] != c)
			start = i;
		if(s[i] != c && (s[i+1] == c || s[i+1] == '\0'))
		{
			ro[j] = substr(s,start,i-start +1);
			j++;
		}
		i++;
	}
	ro[j] = NULL;
	i = 0;
	tmp = ro[0];
	while(i<count_words(s,c)-1)
	{
		ro[i] = ro[i+1];
		i++;
	}
	ro[count_words(s,c)-1] = tmp;
	return(ro);
}

int main(int ac,char *av[])
{
	int i;
	char **rosplit;

	if(ac > 1)
	{
		rosplit = rostring(av[1],' ');
		//printf("Final result\n");
		i = 0;
 		while(rosplit[i])
        	{
			if (i > 0)
				write(1," ",1);
			ft_putchar(rosplit[i]);
                	//printf("|%s|\n",rosplit[i]);
                	i++;
        	}
	}
	write(1,"\n",1);
	return(0);
}
