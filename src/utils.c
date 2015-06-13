#include <stdlib.h>
#include <string.h>
#include "utils.h"

void copyToClipboard(char *s, int length) {
    char *command;

    command = (char *) malloc(length+17);

    strcpy(command, "echo '");
    strcat(command, s);
    strcat(command, "' | pbcopy");
    system(command);

    free(command);
}

