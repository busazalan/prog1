#include <stdio.h>

void kiir(int meret, int const tomb[]){
	int i, j = 0;
	for (i = 0; i < meret; i++){
		printf("%d, ", tomb[i]);
	}
	printf("\n");
}

int main(){
	int tomb[] = {2, 4, 8, 3, 9, 7, 1};
	int meret = 7;
	kiir(meret, tomb);
	return 0;
}
