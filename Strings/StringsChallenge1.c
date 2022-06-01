#include <strings.h>
#include <stdio.h>
#include <stdbool.h>

//counts number of characters in string; basically strlen()
int countNumberOfChars();

//concatonates 2 strings together into results; basically strcat()
void concatenateString(char result[], const char str1[], const char str2[]);

//concatonates 2 strings together into results; basically strstr()
void stringEqual(const char str1[], const char str2[]);

int main(){

    int length = countNumberOfChars();

    const char str1[]= "Hello My ";
    const char str2[] = "Name is Taylor";
    char result[length];
    const char str3[strlen(str1)];
    strcpy(str3, str1);
    concatenateString(result, str1, str2);

    stringEqual(str1, str3);
    stringEqual(str1, str2);
return 0;
}

int countNumberOfChars(){

    char string[] = "Hello My Name is Taylor";
    printf("%s\n", string);
    int len = 0;
    char findEnd = string[0];

    while(findEnd != '\0'){
       findEnd = string[len];
     len++;
    }
    printf("Length %i\n", len);

return len;
}

void concatenateString(char result[], const char str1[], const char str2[]){

    char findEnd = str1[0];
    int len = 0;

    //runs through first string and appends to result[]
    while(findEnd != '\0'){
    len++;
     result[len] = findEnd;
     findEnd = str1[len];
     

    }   

    findEnd = str2[0];
    int resultsLen = len;
    len = 0;
    //runs through second string and appends to result[]
    while(findEnd != '\0'){
    len++;
    resultsLen++;
     result[resultsLen] = findEnd;
     findEnd = str2[len];
     
    }
    result[resultsLen+1] = '\0';
    resultsLen++;
    printf("%i\n", resultsLen);
    printf("Result: %s\n", result);

return;
}

void stringEqual(const char str1[], const char str2[]){

    char findEnd;
    bool notEqual = false;
    int currChar = 0;
    while(str1[currChar] == str2[currChar]){
        currChar++;
        if(str1[currChar] != str2[currChar]){
            notEqual = true;
            break;
        }
    }

    if(notEqual == true){
        printf("Strings not equal\n");
    }
    else{
        printf("The Strings are equal\n");
    }
    

return;
}