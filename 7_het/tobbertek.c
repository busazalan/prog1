#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Statisztika {
    int min;
    int max;
    double atlag;
};

void feltolt(int tomb[], int meret) {
    for (int i = 0; i < meret; i++) {
        tomb[i] = rand() % 90 + 10;
    }
}

void kiir_tomb(int tomb[], int meret) {
    printf("A tomb elemei: ");
    for (int i = 0; i < meret; i++) {
        printf("%d%s", tomb[i], (i == meret - 1) ? "" : ", ");
    }
    printf("\n");
}

struct Statisztika keszit_statisztika(int tomb[], int meret) {
    struct Statisztika s; 
    
    s.min = tomb[0];
    s.max = tomb[0];
    int osszeg = 0;

    for (int i = 0; i < meret; i++) {
        if (tomb[i] < s.min) s.min = tomb[i];
        if (tomb[i] > s.max) s.max = tomb[i];
        osszeg += tomb[i];
    }

    s.atlag = (double)osszeg / meret;
    
    return s; 
}

int main() { 

    int szamok[10];
    feltolt(szamok, 10);
    kiir_tomb(szamok, 10);

    struct Statisztika eredmeny = keszit_statisztika(szamok, 10);

    printf("Legkisebb elem: %d\n", eredmeny.min);
    printf("Legnagyobb elem: %d\n", eredmeny.max);
    printf("Az elemek átlaga: %.1f\n", eredmeny.atlag);

    return 0;
}
