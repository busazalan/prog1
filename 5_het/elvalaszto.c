#include <stdio.h>

void vonal(char karakter, int darab){
	for (int i = 1; i <= darab; i++){
		printf("%c", karakter);
	}
	printf("\n");
}



int main(){
	char karakter = '-';
	int darab = 30;
	vonal(karakter, darab);
	return 0;
}
