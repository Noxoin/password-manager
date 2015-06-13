#include <openssl/ssl.h>
#include <stdio.h>
#include "constants.h"
#include "generator.h"

int main() {
    FILE *ptr_file;
    int counter, length;
    char *password, *commandcopy;

    ptr_file = fopen("pass.bin", "wb");

    if (!ptr_file) {
        printf("Not able to open file\n");
        return -1;
    }

    length = DEFAULT_LENGTH;

    password = (char*) malloc(length+1);
    generatePass(password, length);
    password[length] = (char) 0;

    fwrite(password, sizeof(password), 1, ptr_file);

    printf("%s\n", password);
    copyToClipboard(password, length);

    fclose(ptr_file);
    free(password);

    return 0;
}
