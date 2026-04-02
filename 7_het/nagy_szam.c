#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char szam_szoveg[1000];
    int osszeg = 0;

    printf("Szam: ");
    
    if (scanf("%999s", szam_szoveg) != 1) {
        return 1;
    }

    for (int i = 0; szam_szoveg[i] != '\0'; i++) {
        if (isdigit(szam_szoveg[i])) {
            osszeg += szam_szoveg[i] - '0';
        }
    }

    printf("\nA szamjegyek osszege: %d\n", osszeg);

    return 0;
}
