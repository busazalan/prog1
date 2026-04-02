#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int benne_van(int szam, int tomb[], int meret) {
    for (int i = 0; i < meret; i++) {
        if (tomb[i] == szam) {
            return 1;
        }
    }
    return 0;
}

void general_egyedi(int n, int also, int felso, int tomb[]) {
    int talalt_db = 0;
    int intervallum = felso - also + 1;

    while (talalt_db < n) {
        int uj_szam = rand() % intervallum + also;
        
        if (!benne_van(uj_szam, tomb, talalt_db)) {
            tomb[talalt_db] = uj_szam;
            talalt_db++;
        }
    }
}

void rendez(int n, int tomb[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tomb[j] > tomb[j + 1]) {
                int temp = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = temp;
            }
        }
    }
}

void kiir(int n, int tomb[]) {
    printf("\nA generált számok: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tomb[i]);
    }
    printf("\n");
}

int main() {
    int n, also, felso;
    srand(time(NULL));

    printf("HÁny db random számot kérsz? ");
    scanf("%d", &n);
    printf("Add meg az alsó határt: ");
    scanf("%d", &also);
    printf("Add meg a felső határt: ");
    scanf("%d", &felso);

    if (n > (felso - also + 1)) {
        printf("\nHiba: Túl kicsi az intervallum %d db egyedi számhoz!\n", n);
        return 1;
    }

    int szamok[n];
    general_egyedi(n, also, felso, szamok);
    rendez(n, szamok);
    kiir(n, szamok);

    return 0;
}
