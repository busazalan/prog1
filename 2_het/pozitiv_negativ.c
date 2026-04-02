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
	int negativ = 0, pozitiv = 0;
	int szam;
	do
	{
		szam = vizsgal();
		if (szam > 0)
		{
			pozitiv++;
		}
		else if (szam < 0)
		{
			negativ++;
		}
	}
	while(szam != 0);
	printf("\n");
	printf("%d input volt pozitív.\n", pozitiv);
	printf("%d input volt negatív.\n", negativ);
	return 0;
}
