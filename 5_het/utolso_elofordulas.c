#include <stdio.h>
#include <string.h>
#include "prog1.h"

int utolso(string s, char c){
	int flag = -1;
	int n = strlen(s);
	for (int i = 0; i < n; i++){
		if (s[i] == c){
			flag = i;
		}
	}
	return flag;
}

int main(){
	string s = "orbán viktor";
	char c = 'r';
	int x = utolso(s, c);
	if (x != -1){
		printf("Utoljára a %d helyen fordul elő a %c karakter.\n", x, c);
	}
	else{
		printf("A keresett karakter nincs a szövegben.\n");
	}
	return 0;
}
