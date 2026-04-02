#include <stdio.h>
#include <math.h>

double kerulet(double sugar)
{
	double ker = 2*sugar*M_PI;
	return ker;
}

double terulet(double sugar)
{
	double ter = pow(sugar,2)*M_PI;
	return ter;
}

int main()
{
	double sugar;
	printf("Add meg a kör sugarát (cm): ");
	scanf("%lf", &sugar);
	printf("\n");
	printf("A kör kerülete: %.2lfcm\n", kerulet(sugar));
	printf("A kör területe: %.2lfcm\n", terulet(sugar));
	return 0;
}
