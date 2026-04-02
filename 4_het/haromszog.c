#include <stdio.h>

void beker(double *a, double *b, double *c){
	printf("Add meg a háromszög egyik oldalát (cm): ");
	scanf("%lf", a);
	printf("Add meg a háromszög másik oldalát (cm): ");
	scanf("%lf", b);
	printf("Add meg a háromszög harmadik oldalát (cm): ");
	scanf("%lf", c);
	printf("\n");
}

int valid_triangle(double a, double b, double c){
	if (a <= 0 || b <= 0 || c <= 0){
		return 0;
	}
	
	if (a + b > c && a + c > b && c + b > a){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	double a, b, c;
	beker(&a, &b, &c);
	
	if (valid_triangle(a, b, c) == 1){
		printf("A háromszög megszerkeszthető.\n");
	}
	else{
		printf("A háromszög nem megszerkeszthető.\n");
	}
	return 0;
}
