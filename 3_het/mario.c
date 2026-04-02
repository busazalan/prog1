#include <stdio.h>

int beker()
{
	int magassag;
	printf("Add meg a háromszög magasságát: ");
	scanf("%d", & magassag);
	return magassag;
}

void rajz(int magassag)
{
	int i, j;
	for (i = 1; i <= magassag; i++)
	{
		for (j = magassag - i; j > 0; j--)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("#");
		}
		printf("  ");
		for (j = 1; j <= i; j++)
		{
			printf("#");
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
