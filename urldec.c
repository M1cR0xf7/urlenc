#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"



void urldec(char *s)
{

    size_t i;
    size_t size;

    char mod = '%';

    char tmp[4];

    size = count(s);

    // hex delimter
    tmp[0]='0';
    tmp[1]='x';

    /* printf("%c => %c",mod, s[0]); */

    long tmp_ret;


    for(i = 0; i < size; ++i){
        if (s[i] == mod){
            /* printf("%c%c%c ", s[i], s[i+1], s[i+2]); */
            tmp[2]=s[i+1];
            tmp[3]=s[i+2];

            tmp_ret = hextodecimal(tmp);
            printf("%c", (int)tmp_ret);

            memmove(s+i, s+i+2, strlen(s) - i+1);
            /* memmove(s+i, s+i+3, strlen(s) - i+2); */

        } else {
            printf("%c", s[i]);
        }
    }
}

int main()
{
    char *buffer = stdin_recv(BUFFER_SIZE);

    if(buffer == NULL){
        free(buffer);
        return 1;
    }

    urldec(buffer);
    free(buffer);
    printf("\n");

    return 0;
}
