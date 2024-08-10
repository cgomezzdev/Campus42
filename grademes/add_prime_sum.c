
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	if (n >9)
	{
		ft_putnbr(n/10);
		n = n % 10;
	}
	if (n < 10)
	{
		n = n + '0';
		write(1,&n,1);
	}
}

int ft_atoi(char *s)
{
	int i;
	int n;

	i = 0;
	while((s[i] >= '0' && s[i] <= '9') && s[i])
	{
		n = (n*10) + s[i] - '0';
		i++;
	}
	return(n);
}

int is_prime(int n)
{
	int div;

	div = 2;
	while(div <= n /2)
	{
		if(n % div == 0)
			return(0);
		div++;
	}
	return(1);
}

void a_p_s(char *s)
{
	int n;
	int sum;

	n = ft_atoi(s);
	if (n < 0)
	{
		write(1,"0",1);
		return;
	}
	sum = 0;
	while(n > 1)
	{
		if(is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	write(1,"\n",1);
}

int main(int ac, char *av[])
{
	if (ac == 2)
		a_p_s(av[1]);
	else
	write(1,"0\n",2);
	return(0);
}
