#include <stdio.h>
#include <math.h>

double kerulet(double a, double b)
{
	double ker = 2*a+2*b;
	return ker;
}

double terulet(double a, double b)
{
	double ter = a*b;
	return ter;
}

int main()
{
	float rovid;
	float hosszu;
	printf("Add meg a téglalap rövidebb oldalát (cm): ");
	scanf("%f", &rovid);
	printf("Add meg a téglalap hosszabb oldalát (cm): ");
	scanf("%f", &hosszu);
	printf("\n");
	
	if (fmod(kerulet(rovid, hosszu),1) != 0)
	{
		printf("A téglalap kerülete: %.2lfcm\n", kerulet(rovid, hosszu));
		printf("A téglalap területe: %.2lfcm\n", terulet(rovid, hosszu));
	}
	else
	{
		printf("A téglalap kerülete: %dcm\n", (int)kerulet(rovid, hosszu));
		printf("A téglalap területe: %dcm\n", (int)terulet(rovid, hosszu));
	}
	return 0;
}
