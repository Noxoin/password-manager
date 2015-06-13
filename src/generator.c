#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "generator.h"

/* ASCII TABLE 
** 
** NUMERIC => 0-9, 48-57, 0x30-0x39
** ALPHACAP => A-Z, 65-90, 0x41-0x5A
** ALPHALOW => a-z, 97-122, 0x61-0x7A
*/
void generatePass(char *password, int length) {
    int i;
    srand(time(NULL));
    for(i = 0; i < length; ++i) {
        int random = rand()%(10+26+26);
        if(random < 10) {
            random = random + 48;
        } else if (random < 36) {
            random = random - 10 + 65;
        } else {
            random = random - 36 + 97;
        }
        password[i] = (char) random;
        printf("%d => %c\n", random, password[i]);
    }
}
