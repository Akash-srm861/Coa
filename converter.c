##include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Convert decimal to binary
void toBinary(int n, char *res) {
    int i = 0;
    do {
        res[i++] = (n % 2) ? '1' : '0';
        n /= 2;
    } while (n != 0);
    res[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = temp;
    }
}

// Convert decimal to octal
void toOctal(int n, char *res) {
    int i = 0;
    do {
        res[i++] = (n % 8) + '0';
        n /= 8;
    } while (n != 0);
    res[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = temp;
    }
}

// Convert decimal to hexadecimal
void toHex(int n, char *res) {
    char hexChars[] = "0123456789ABCDEF";
    int i = 0;
    do {
        res[i++] = hexChars[n % 16];
        n /= 16;
    } while (n != 0);
    res[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = temp;
    }
}

void convert(int decimal) {
    char binary[65], octal[23], hex[17];
    toBinary(decimal, binary);
    toOctal(decimal, octal);
    toHex(decimal, hex);

    printf("\nNumber Conversions:\n");
    printf("Decimal     : %d\n", decimal);
    printf("Binary      : %s\n", binary);
    printf("Octal       : %s\n", octal);
    printf("Hexadecimal : %s\n", hex);
}

int main() {
    int choice;
    char input[100];

    while (1) {
        printf("\n--- Universal Number Converter ---\n");
        printf("1. Binary → (Decimal/Octal/Hex)\n");
        printf("2. Octal → (Decimal/Binary/Hex)\n");
        printf("3. Decimal → (Binary/Octal/Hex)\n");
        printf("4. Hexadecimal → (Decimal/Binary/Octal)\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter number: ");
        scanf("%s", input);

        int decimal = 0;

        switch (choice) {
            case 1: // Binary
                decimal = (int)strtol(input, NULL, 2);
                convert(decimal);
                break;
            case 2: // Octal
                decimal = (int)strtol(input, NULL, 8);
                convert(decimal);
                break;
            case 3: // Decimal
                decimal = (int)strtol(input, NULL, 10);
                convert(decimal);
                break;
            case 4: // Hex
                decimal = (int)strtol(input, NULL, 16);
                convert(decimal);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
