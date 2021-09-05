#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void encrypt(char str[], int key) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char crypted_char = str[i]+key;
        if (crypted_char < 0) {
            crypted_char = crypted_char*-1;
        }

        if (str[i] >= 'a' && str[i] <= 'z') {
            if (crypted_char > 'z') {
                str[i] = crypted_char - 'z' + 'a' - 1;
            } else {
                str[i] = crypted_char;
            }
        } else if (crypted_char >= 'A' && crypted_char <= 'Z') {
            if (crypted_char > 'Z') {
                str[i] = crypted_char - 'Z' + 'A' - 1;
            } else {
                str[i] = crypted_char;
            }
        }
    }
}

void decrypt(char str[], int key) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char uncrypted_char = str[i]-key;
        if (uncrypted_char < 0) {
            uncrypted_char = uncrypted_char*-1;
        }

        if (str[i] >= 'a' && str[i] <= 'z') {
            if (uncrypted_char < 'a') {
                str[i] = uncrypted_char + 'z' - 'a' + 1;
            } else {
                str[i] = uncrypted_char;
            }
        } else if (uncrypted_char >= 'A' && uncrypted_char <= 'Z') {
            if (uncrypted_char < 'A') {
                str[i] = uncrypted_char + 'Z' - 'A' + 1;
            } else {
                str[i] = uncrypted_char;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "portuguese");

    char message[100];
    printf("Digite algum texto: \n");
    scanf("%[^\n]s%*c", message);
    printf("\n\nTexto: %s", message);
    encrypt(message, 2);
    printf("\nTexto cifrado: %s", message);
    decrypt(message, 2);
    printf("\nTexto cifrado decifrado novamente: %s", message);
}
