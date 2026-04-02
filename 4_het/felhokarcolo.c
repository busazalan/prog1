#include <stdio.h>

int karcolas(int meret, int const tomb[]){
	int i, j = 0;
	for (i = 0; i < meret - 1; i++){
		if (tomb[i] > tomb[i + 1]){
			j += tomb[i] - tomb[i + 1];
		}
		else if (tomb[i] < tomb[i + 1]){
			j += tomb[i + 1] - tomb[i];
		}
	}
	return j;
}

int main(){
	int tomb[] = {2, 4, 8, 3, 9, 7, 1};
	int meret = 7;
	printf("A tömb elemeinek külömbségének összege: %d\n", karcolas(meret, tomb));
	return 0;
}
