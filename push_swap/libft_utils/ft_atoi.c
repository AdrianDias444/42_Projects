#include "../header.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	negativo;
	int	res;

	signal = 0;
	negativo = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		signal++;
		if (signal > 1)
			return (0);
		if (*nptr == '-')
			negativo = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * negativo);
}