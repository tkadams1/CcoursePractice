#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countLinesInFile();
void convertToUpperCase();
void printFileInReverse();
char * FILENAME = "exampleFile.txt";

int main(){
    //countLinesInFile();
    //convertToUpperCase();
    printFileInReverse();
    return 0;
}

void printFileInReverse(){
    FILE *fp;
    char c;
    int cnt =0;
    int i =0;
    fp = fopen(FILENAME, "r");
    if (fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    //move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    //get the postion of the file pointer
    cnt = ftell(fp);


    while (i<cnt){
        i++;
        //seek to the position of end of file - i
        fseek(fp, -i, SEEK_END);
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("\n");
}

void convertToUpperCase(){
    char* ch;
    FILE *aFile = NULL;
    FILE *aFile1 = NULL;

    aFile = fopen(FILENAME, "r");

    if (aFile == NULL){
        printf("Error opening file\n");
        return;
    }
    //creates a new temp file
    aFile1 = fopen("temp.txt", "w");

    if (aFile1 == NULL){
        printf("Error creating file\n");
        return;
    }

    while((ch = fgetc(aFile)) != EOF){
        if (islower(ch)){
            ch = ch - 32;
        }
        fputc(ch, aFile1);
    }

    fclose(aFile);
    fclose(aFile1);

    //rename temp file to original file
    rename("temp.txt", FILENAME);

    //remove temp file
    remove("temp.txt");

    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL){
        printf("Error opening file\n");
        return;
    }

    //print out contents of file
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
}

void countLinesInFile(){
    FILE *aFile;
    int lineCount = 1; //Start at 1 because we are counting the first line
    char ch;

    aFile = fopen(FILENAME, "r");
    if (aFile == NULL){
        printf("Error opening file");
        return;
    }
    // reads through the file and counts the number of lines
    while((ch =fgetc(aFile)) != EOF){
        if (ch == '\n'){
            lineCount++;
        }
    }
    printf("%d", lineCount);
    fclose(aFile);
}