#include <stdio.h>
#include <string.h>
#include "prog1.h"

#define SIZE 26

void abc_C(char tomb[]){
	char start = 'a';
	for (int i = 0; i < SIZE; i++){
		tomb[i] = start + i;
	}
	
}

void kiir(char tomb[]){
	for (int i = 0; i < SIZE; i++){
		printf("%c ", tomb[i]);
	}
	printf("\n");
}

string abc_S(char str[]){
	char start = 'a';
	for (int i = 0; i < SIZE + 1; i++){
		if (i == SIZE){
			str[i] = '\0';
		}
		else{
			str[i] = start + i;
		}
	}
}

int main(){
	char abc[SIZE];
	abc_C(abc);
	kiir(abc);
	
	char s[SIZE];
	abc_S(s);
	printf("%s\n", s);
	return 0;
}
