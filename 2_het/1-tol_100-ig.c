#include <stdio.h>

int sum(int i, int max)
{
	int szam = 0;
	for (i; i <= max; i++)
	{
		szam += i;
	}
	return szam;
}

int gauss(int a, int b)
{
	return (a + b) * (b - a + 1) / 2;
}

int main()
{
	printf("%d\n", sum(1, 100));
	printf("%d\n", gauss(1, 100));
	return 0;
}
