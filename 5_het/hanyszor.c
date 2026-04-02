#include <stdio.h>
#include <string.h>
#include "prog1.h"

int hanyszor(string s, char c){
	int count = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++){
		if (s[i] == c){
			count += 1;
		}
	}
	return count;
}

int main(){
	string s = "orbán viktor";
	char c = 'r';
	int x = hanyszor(s, c);
	printf("A karakter %d alkalommal fordult elő a szövegben.\n", x);
	return 0;
}
