#include <stdio.h>
#include <string.h>
#include "prog1.h"

int vegek(int n, string szavak[]){
	int count = 0;
	for (int i = 0; i < n; i++){
		int len = strlen(szavak[i]);
		if (len >= 2 && szavak[i][0] == szavak[i][len - 1]){
			count += 1;
		}
	}
	return count;
}

int main(){
    string szavak[] = { "aba", "xyz", "aa", "x", "bbb" };
    int meret = 5;
    int darab = vegek(meret, szavak);
    printf("A listában %d ilyen elem van.\n", darab);
    return 0;
}
