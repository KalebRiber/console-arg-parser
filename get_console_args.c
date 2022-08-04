#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function returns zero if argument wasn't found. */
char *get_console_arg(char **inputs, int *count, char *argument){
    for (int i = 0; i < *count; ++i){
        if(!strcmp(*(inputs + i), argument)){
            if (i + 1 < *count){
                i++;
                return *(inputs + i);
            }
            else
                return (char *) 0x00;
        }
    }
    return (char *) 0x00;
}

int main(int argc, char *argv[]){
    char *argument_name = "--test",
         *arg = get_console_arg(argv, &argc, argument_name);

    if (!arg)
        printf("argument %s not found\r\n", argument_name);
    else
        printf("value of %s: %s\r\n", argument_name, arg);

    return 0;
}
