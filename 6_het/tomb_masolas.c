#include <stdio.h>

int meret(){
	int n;
	printf("Hány darab számot szeretnél megadni? ");
	scanf("%d", &n);
	printf("\n");
	return n;
}

void beker(int n, int tomb[]){
	int m;
	for (int i = 0; i < n; i++){
		printf("%d. szám: ", i + 1);
		scanf("%d", &m);
		tomb[i] = m;
	}
	printf("\n");
}

void abs_t(int n, int const tomb[], int abs_tomb[]){
	for (int i = 0; i < n; i++){
		if (tomb[i] < 0){
			abs_tomb[i] = -tomb[i];
		}
		else{
			abs_tomb[i] = tomb[i];
		}
	}
}

void kiir(int n, int tomb[]){
	for (int i = 0; i < n; i++){
		printf("%d ", tomb[i]);
	}
	printf("\n");
}

int main(){
	int n = meret();
	int tomb_eredeti[n];
	beker(n, tomb_eredeti);
	
	int abs_tomb[n];
	abs_t(n, tomb_eredeti, abs_tomb);
	
	printf("A módosított tömb elemei: ");
	kiir(n, abs_tomb);
	printf("Az eredeti tömb elemei: ");
	kiir(n, tomb_eredeti);
	return 0;
}
