
#include <unistd.h>

int is_space(int c)
{
	return((c >= 9 && c <= 13) || c == ' ' || c == '\0');
}

int count_word(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(s[i])
	{
		if(!is_space(s[i]) && is_space(s[i+1]))
			count++;
		i++;
	}
	return(count);
}

void print_s(char *s,int start,int len,int words)
{
	int i;

	i = 0;
	while(i<len)
	{
		write(1,&s[start],1);
		i++;
		start++;
	}
	if(words >= 1)
	{
		write(1,"   ",3);
	}
}

void expand_str(char *s)
{
	int i;
	int start;
	int words;

	i = 0;
	words = count_word(s)-1;
	while (s[i])
	{
		if(i>0 && !is_space(s[i]) && is_space(s[i-1]))
			start = i;
		if(i == 0 && !is_space(s[i]))
			start = i;
		if(!is_space(s[i]) && is_space(s[i+1]))
		{
			print_s(s,start,i-start+1,words);
			words--;
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
		expand_str(av[1]);
	write(1,"\n",1);
	return(0);
}
