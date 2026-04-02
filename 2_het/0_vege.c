#include <stdio.h>

int vizsgal()
{
	int szam;
	printf("Addj meg egy egész számot (0-al kilépsz): ");
	scanf("%d", &szam);
	return szam;
}

int main()
{
	int szamlalo = 0;
	int szam;
	do
	{
		szam = vizsgal();
		if (szam != 0)
		{
			szamlalo++;
		}
	}
	while(szam != 0);
	printf("\n");
	printf("%d input volt nem 0 értékű.\n", szamlalo);
	return 0;
}
