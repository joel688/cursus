#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static	long int	ft_atoi(const char *str)
{
	long long int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v'))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (*str < '0' || *str > '9')
			return (result);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (sign < 0)
		result *= -1;
	return (result);
}

static	int	find_doublon(int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 2;
	k = 0;
	while(i < argc)
	{
		while(j < argc)
		{
			if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return(0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return(1);
}

static	int	is_int(const char *s)
{
	long long int i;

	i = ft_atoi(s);
	if (i >= -2147483648 && i <= 2147483647) 
		return (1);
	else 
		return (0);
}

static	int	is_num(char *s)
{
	int i;
	int length;

	i = 0;
	length = ft_strlen(s);
	while(s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	if(i == length)
		return(1);
	else
		return(0);
}

int is_error(int argc, char **argv)
{
	int i;
	int isnum;
	int isint;
	int isdoublon;

	i = 1;
	isnum = 1;
	isint = 1;
	isdoublon = find_doublon(argc, argv);
	while(isnum == 1 && isint == 1 && isdoublon == 1)
	{
		if(i == argc)
			break;
		isnum = is_num(argv[i]);
		isint = is_int(argv[i]);
				i++;

	}
	if(isnum == 0 || isint == 0 || isdoublon == 0 || argc == 1)
	{
		write(2, "Error\n", 6);
		return(0);
	}
	return(1);
}

int main(int argc, char **argv)
{
	int i;
	i = is_error(argc, argv);
	write(1, &i, 1);
}
