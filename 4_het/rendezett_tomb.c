#include <stdio.h>

int rendezett(int meret, int const tomb[]){
	if (meret == 0){
		return 1;
	}
	else{
		int i;
		for (i = 1; i <= meret; i++){
			if (tomb[i] < tomb[i - 1]){
				return 0;
			}
		}
		return 1;
	}
}

int main(){
	int tomb[] = {1, 2, 3, 4};
	int meret = 4;
	if (rendezett(meret, tomb) == 1){
		printf("A tömb rendezett.\n");
	}
	else{
		printf("A tömb nem rendezett.\n");
	}
}
