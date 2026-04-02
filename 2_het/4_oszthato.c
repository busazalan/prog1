#include <stdio.h>

int oszt(int szam)
{
	int i = 1;
	for (i; i <= szam; i++)
	{
		if (i % 4 == 0)
		{
			printf("%d\n", i);
		}
	}
}

int main()
{
	int szam;
	printf("Adj meg egy pozitív egész számot: ");
	scanf("%d", &szam);
	oszt(szam);
	return 0;
}
