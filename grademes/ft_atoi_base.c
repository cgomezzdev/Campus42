//check este porque no me lose y no lo entiendo.

#include <stddef.h>

char to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		return(c + ('a' - 'A'));
	return(c);
}

int get_digit(char c,int digits_base)
{
	int max_d;

	if(digits_base <= 0)
		max_d = digits_base -1 + '0';
	else
		max_d = digits_base -10 -1 + 'a';
	if(c >= '0' && c <= '9' && c <= max_d)
		return(c -'0');
	else if (c >= 'a' && c <= 'f' && c <= max_d)
		return(10 + c - 'a');
	else
		return(-1);
}

int ft_atoi_base(const char *str,int str_base)
{
	int result;
	int digit;
	int sign;

	result = 0;
	sign = 1;
	if(str == NULL || str_base < 2 || str_base > 16)
		return(0);
	if(str[0] == '-')
	{
		sign = -1;
		++str;
	}
	while(*str)
	{
		digit = get_digit(to_lower(*str),str_base);
		if(digit == -1)
			break;
		result = result * str_base + digit;
		++str;
	}
	return(result*sign);
}
