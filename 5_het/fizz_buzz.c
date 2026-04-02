#include <stdio.h>
#include <string.h>
#include "prog1.h"
 
void fizzbuzz(int n){
	for (int i = 1; i <= 100; i++){
		if (i % 3 == 0 && i % 5 == 0){
			printf("FizzBuzz\n");
		}
		else if (i % 3 == 0 && i % 5 != 0){
			printf("Fizz\n");
		}
		else if (i % 3 != 0 && i % 5 == 0){
			printf("Buzz\n");
		}
		else{
			printf("%d\n", i);
		}
	}
}

int main(){
    int n = 100;
    fizzbuzz(n);
    return 0;
}
