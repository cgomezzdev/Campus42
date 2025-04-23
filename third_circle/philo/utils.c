
#include "philo.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] || s2[i])
    {
        if(s1[i] != s2[i])
        return(s1[i] - s2[i]);
        i++;
    }
    return(0);
}

int ft_atoi(char *s)
{
	int i;
	int num;

	num = 0;
	i = 0;
	while(s[i])
	{
		num = (num * 10) + s[i] - '0'; 
		i++;
	}
	return(num);
}