#include <stdio.h>
#include <string.h>
#include "prog1.h"

void elofordul(string s, char c){
	int n = strlen(s);
	for (int i = 0; i < n; i++){
		if (s[i] == c){
			printf("Benne van, elsőnek a %d helyen.\n", i + 1);
			n = 0;
		}
	}
	if (n != 0){
		printf("Nincs benne.\n");
	}
}



int main(){
	string s = "apache helikopter";
	char c = 'x';
	elofordul(s, c);
	return 0;
}
