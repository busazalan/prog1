#include <stdio.h>

int sum(int i, int max)
{
	int szam = 0;
	for (i; i < max; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			szam += i;
		}
	}
	return szam;
}

int main()
{
	printf("%d\n", sum(1, 1000));
	return 0;
}
