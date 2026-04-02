#include <stdio.h>

int paratlan(int szam)
{
	int i = 1;
	for (szam; i <= szam; szam -= 2)
	{
		printf("%d\n", szam);
	}
}

int main()
{
	int szam;
	printf("Adj meg egy pozitív egész számot: ");
	scanf("%d", &szam);
	paratlan(szam);
	return 0;
}
