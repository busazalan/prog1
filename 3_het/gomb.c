#include <stdio.h>
#include <math.h>

double beker()
{
	double sugar;
	printf("Add meg a gömb sugarát (cm): ");
	scanf("%lf", &sugar);
	return sugar;
}

double felszin(double sugar)
{
	double felszin = 4 * pow(sugar, 2) * M_PI;
	return felszin;
}

double terfogat(double sugar)
{
	double terfogat = (4 * pow(sugar, 3) * M_PI) / 3;
	return terfogat;
}

int main()
{
	double sugar = beker();
	printf("\n");
	if (fmod(felszin(sugar), 1) != 0 || fmod(terfogat(sugar), 1) != 0)
	{
		printf("A gömb felszíne %.2lfcm^2.\n", felszin(sugar));
		printf("A gömb térfogata %.2lfcm^3.\n", terfogat(sugar));
	}
	else
	{
		printf("A gömb felszíne %dcm^2.\n", (int)felszin(sugar));
		printf("A gömb térfogata %dcm^3.\n", (int)terfogat(sugar));
	}
	return 0;
}
