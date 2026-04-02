#include <stdio.h>

int main()
{
	int egyik, masik;
	printf("Adj meg egy számot: ");
	scanf("%d", &egyik);
	printf("Adj meg mégegy számot: ");
	scanf("%d", &masik);
	printf("\n");
	if (egyik > masik)
	{
		printf("Egyik > Másik\n");
	}
	else if (egyik < masik)
	{
		printf("Egyik < Másik\n");
	}
	else
	{
		printf("A két szám egyenlő.\n");
	}
	return 0;
}
