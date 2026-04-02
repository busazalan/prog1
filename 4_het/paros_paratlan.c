#include <stdio.h>

int beker(int szam){
	printf("Adj meg egy egész számot: ");
	scanf("%d", &szam);
	return szam;
}

int is_even(int szam){
	if (szam % 2 == 0 && szam != 0){
		return 1;
	}
	else{
		return 0;
	}
}

int is_odd(int szam){
	if (is_even(szam) == 0 && szam != 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int a = beker(a);
	if (is_even(a) == 1){
		printf("A szám páros.\n");
	}
	else if (is_odd(a) == 1){
		printf("A szám páratlan.\n");
	}
	else{
		printf("A szám nulla.\n");
	}
	return 0;
}
