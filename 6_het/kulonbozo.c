#include <stdio.h>

int beker(int tomb[]) {
    int input = 1;
    int i = 0;
    while (input != 0) {
        printf("Adj meg egy számot: ");
        scanf("%d", &input);
        if (input < 0 || input > 99) {
            printf("0 és 99 közötti számot adj meg!\n");
        } else if (input != 0) {
            tomb[i] = input;
            i++;
        }
    }
    return i;
}

int kulonbozo(int n, int tomb[], int darab_tomb[]) {
    int db = 0;
    for (int i = 0; i < n; i++) {
        int mar_szerepel = 0;
    
        for (int j = 0; j < db; j++) {
            if (tomb[i] == darab_tomb[j]) {
                mar_szerepel = 1;
                break;
            }
        }

        if (mar_szerepel == 0) {
            darab_tomb[db] = tomb[i];
            db++;
        }
    }
    return db;
}

void novekvo(int n, int tomb[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tomb[j] > tomb[j + 1]) {
                int ideiglenes = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = ideiglenes;
            }
        }
    }
}

void kiir(int n, int tomb[]) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", tomb[i], (i == n - 1) ? "" : ", ");
    }
    printf("\n");
}

int main() {
    int tomb[100];
    int darab[100];
    
    printf("Adj meg számokat 1-99 között, 0-val kilépsz!\n");
    printf("\n");
    
    int osszes_db = beker(tomb);
    int egyedi_db = kulonbozo(osszes_db, tomb, darab);
    
    printf("\n%d db különböző szám lett megadva.\n", egyedi_db);
    
    novekvo(egyedi_db, darab);
    
    printf("Ezek növekvő sorrendben: ");
    kiir(egyedi_db, darab);
    
    return 0;
}
