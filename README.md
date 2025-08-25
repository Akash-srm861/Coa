#include <stdio.h>

void toBinary(int n, char *res) {
    int i = 0;
    do {
        res[i++] = (n % 2) ? '1' : '0';
        n /= 2;
    } while (n != 0);
    res[i] = '\0';

    // reverse
    for (int j = 0; j < i / 2; j++) {
        char temp = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = temp;
    }
}

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

int main() {
    int decimal;

    printf("-----------------------------------------------------------------------------------------------\n");
    printf("THIS IS A CONVERTER WHICH CONVERTS DECIMAL NUMBER TO BINARY, OCTAL AND HEXADECIMAL\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    do {
        printf("Enter A Non-Negative Integer: ");
        scanf("%d", &decimal);
        if (decimal < 0)
            printf("Enter a positive integer\n");
    } while (decimal < 0);

    char binary[65], octal[23], hex[17];
    toBinary(decimal, binary);
    toOctal(decimal, octal);
    toHex(decimal, hex);

    printf("\nNumber Conversions for %d:\n", decimal);
    printf("Binary      : %s\n", binary);
    printf("Octal       : %s\n", octal);
    printf("Hexadecimal : %s\n", hex);

    return 0;
}
