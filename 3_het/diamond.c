#include <stdio.h>
#include <math.h>

int beker()
{
	double magassag;
	do
	{
		printf("Add meg az alakzat magasságát (pozitív páratlan egész): ");
		scanf("%lf", &magassag);
		if (fmod(magassag, 1) != 0 || magassag < 1 || fmod(magassag, 2) == 0)
		{
			printf("Egy pozitív páratlan egész számot adj meg!\n");
		}
	}
	while (fmod(magassag, 1) != 0 || magassag < 1 || fmod(magassag, 2) == 0);
	printf("\n");
	return magassag;
}

void rajz(int magassag)
{
	int i, j;
	int kozep = magassag / 2 + 1;
	for (i = 1; i <= kozep; i++)
	{
		for (j = 1; j <= kozep - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j < 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < kozep; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * (kozep - i) - 1; j++)
		{
			printf("*");
		}
	printf("\n");
	}
}

int main()
{
	int magassag = beker();
	rajz(magassag);
	return 0;
}
