#include <stdio.h>

int main() {
    int n = 100;
    long long negyzetosszeg = 0;
    long long osszeg = 0;
    long long osszeg_negyzete = 0;

    for (int i = 1; i <= n; i++) {
        negyzetosszeg += (long long)i * i;
        osszeg += i;
    }

    osszeg_negyzete = osszeg * osszeg;

    long long kulonbseg = osszeg_negyzete - negyzetosszeg;

    printf("Az első %d szám négyzetösszege: %lld\n", n, negyzetosszeg);
    printf("Az első %d szám összegének négyzete: %lld\n", n, osszeg_negyzete);
    printf("A kulonbseg: %lld\n", kulonbseg);

    return 0;
}
