#include <stdio.h>
#include <string.h>

int main() {
    char szo[100];
    int db = 0;
    int max_hossz = 0;

    printf("Adj meg szavakat, *-al kilépsz!\n");

    while (1) {
        printf("Adj meg egy szavat: ");
        if (fgets(szo, sizeof(szo), stdin) == NULL) break;
        szo[strcspn(szo, "\n")] = '\0';

        if (strcmp(szo, "*") == 0) {
            break;
        }

        db++;
        int aktualis_hossz = strlen(szo);
        
        if (aktualis_hossz > max_hossz) {
            max_hossz = aktualis_hossz;
        }
    }

    printf("\n%d db szót adtál meg. A leghosszabb szó %d karakterből áll.\n", db, max_hossz);

    return 0;
}
