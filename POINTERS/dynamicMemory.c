#include <stdio.h>
#include <stdlib.h>

int main(){

    int size;
    char *string = NULL;
    printf("Enter size of the text: \n");
    scanf("%d", &size);
    // char* at the beginning cast the malloc call to a char pointer and malloc allocates memory based on the size of a char in a system * the number of chars
    string = (char *)malloc(size*sizeof(char)); 
    
    if (string != NULL)
    {
        printf("Enter text: \n");
        scanf(" ");
        gets(string);

        printf("Text that was input is: %s\n", string);
        //printf("Text that was input is: %s\n", *string); adding the * to string breaks this for some reason not sure why you cant dereference a char pointer with strings
    }

    free(string);
    string = NULL;


    return 0;
}