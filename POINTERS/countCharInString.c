#include <stdio.h>

int main(){
    char *str = "Hello World";
    int i = 0;

    while(*str != '\0'){
        i++;
        str++;
    }

    printf("%d\n", i);
    return 0;
}