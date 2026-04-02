#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_strong(char password[]) {
    int length = strlen(password);
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;

    if (length < 8) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) has_lower = 1;
        if (isupper(password[i])) has_upper = 1;
        if (isdigit(password[i])) has_digit = 1;
    }

    return (has_lower && has_upper && has_digit);
}

int main() {
    char jelszo[100];

    printf("Adj meg jelszavakat, *-al kilépsz!\n\n");

    while (1) {
        printf("jelszo: ");
        if (fgets(jelszo, sizeof(jelszo), stdin) == NULL) break;
    
        jelszo[strcspn(jelszo, "\n")] = '\0';

        if (strcmp(jelszo, "*") == 0) {
            break;
        }

        if (is_strong(jelszo)) {
            printf("Erős jelszó\n\n");
        } else {
            printf("Gyenge jelszó\n\n");
        }
    }

    return 0;
}
