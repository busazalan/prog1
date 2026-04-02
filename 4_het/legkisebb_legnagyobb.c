#include <stdio.h>

int legkisebb(int meret, int const tomb[]){
	int i, j = tomb[0];
	for (i = 0; i < meret; i++){
		if (tomb[i] < j){
			j = tomb[i];
		}
	}
	return j;
}

int legnagyobb(int meret, int const tomb[]){
	int i, j = tomb[0];
	for (i = 0; i < meret; i++){
		if (tomb[i] > j){
			j = tomb[i];
		}
	}
	return j;
}

int main(){
	int tomb[] = {1, -2, 30, 4};
	int meret = 4;
	printf("A tömb legkisebb eleme: %d\n", legkisebb(meret, tomb));
	printf("A tömb legnagyobb eleme: %d\n", legnagyobb(meret, tomb));
	return 0;
}
