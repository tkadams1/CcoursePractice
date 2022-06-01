#include <stdio.h>
#include <string.h>

void stringConcationation();
void stringCompare();
void stringSearch();

int main(){

    //Declares a char array and populates the length with the total length of the initialized text
    char myString[] = "My name is Taylor";

    char temp[50];
    //copy string myString to string temp and only copy up to 49 characters
    strncpy(temp,myString, sizeof(temp)-1);
    printf("The length is: %lu\n", strlen(myString));

    stringConcationation();
    stringSearch();
   

    return 0;
}

void stringConcationation(){
    char src[50], dest[50];

    strcpy(src, "This is source");
    strcpy(dest, "This is destination");

    //Destination is what you will concationate to and source is what will be appended to destination
    //15 is the maximum number of characters to copy from src
    strncat(dest,src,15);

    printf("Final destination string : |%s|\n", dest);

    return;

}

void stringCompare(){
//string compare will retrun 0 if two string arguments are the same and nonzero otherwise
//if return value < 0 then it indicates str1 is less than str2
//if return value > 0 then it indicates str2 is less than str1
//strcmp("arg1", "arg2")
//strncmp("arg1, arg2", "Number of characters in string to compare")

if(strncmp("astronomy","astro",5)==0){
    printf("Found: astronomy");
}
}

void stringSearch(){
//strchr searches a given string for a specified character; The first argument to the function is the string to be searched and the second argument is the character that you are looking for
//will retrun a pointer to the first position in the string where the character is found

char str[] = "The quick brown fox";
char ch = 'q';
char *pGot_char = NULL;
pGot_char = strchr(str,ch);

printf("The memory address of the character found in the string is: %p\n", (void*)&pGot_char);
printf("This character has an address of: %s\n", pGot_char);

//strstr searchs a string for an occurance of a substring
//returns a pointer to the position of the first string where the substring is found
//if no match returns NULL
//strstr("String to search", "Substring to search for")
//case sensitive

char text[] = "Every dog has his day";
char word[] = "dog";
char *pFound = NULL;
pFound = strstr(text,word);

printf("The memory address of the first character found in the substring is: %p\n",(void*)&pFound);
printf("This string has a starting address of: %s\n", pFound);



}
