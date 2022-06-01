#include <stdio.h>

void pointerBasics();
void pointerPassing();
void pointerRecieving();
void pointerPassingArray();
void pointerRecievingArray(int (*pnumber));
void pointerPassingArray2D();
void pointerRecievingArray2D(int (*pnumber)[3]);

int main(void)
{
    //pointerBasics();
    //pointerPassing();
    //pointerPassingArray();
    pointerPassingArray2D();

return 0;

}

void pointerBasics(){
    int number = 0;             //A variable of type int initializsed to 0
    int *pnumber = NULL;        //A pointer that can point to type int

    number = 10;
    printf("number's address: %p\n", &number);          //Output the address
    printf("number's value: %d\n\n", number);           //Output the value

    pnumber = &number;      //Store the address of number in pnumber

    printf("pnumber's address %p\n", (void*)&pnumber);      //Output the address
    printf("pnumber's size: %lu bytes\n", sizeof(pnumber));  //Output the size
    printf("pnumber's value %p\n", pnumber);                //Output the value (address)
    printf("value pointed to: %d\n", *pnumber);             //Value at the address
return;
}

void pointerPassing(){
    printf("\n\nRunning pointer Passing:\n");
    int number = 9;
    int* pnumber = &number;
    printf("pnumber's value before passing: %d\n", *pnumber); 
    pointerRecieving(pnumber);
    printf("pnumber's value before passing: %d\n", *pnumber);
    return;
}

void pointerRecieving(int* pnumber){
    printf("\nValue Passed:\n");
    *pnumber +=10;

    return;
}

void pointerPassingArray(){
    printf("\nRunning pointer Array Passing:\n");
    int number[3] = {17, 9, 90};
    int(* pnumber) = &number[0];
    //int(* pnumber) = number; Alternative syntax to above code
    printf("pnumber's value before passing: %p\n", &pnumber);  
    pointerRecievingArray(pnumber);
    return;
}

void pointerRecievingArray(int (*pnumber)){
    printf("\nValue Passed:\n");
    printf("pnumber's value after passing: %p\n", &pnumber);                //Output the value (address)
    ++pnumber;
    printf("value pointed to: %d\n", (*pnumber));                             //Value at the address

    return;
}

void pointerPassingArray2D(){
    printf("\nRunning pointer Array Passing:\n");
    int number[3][3] = {{17, 9, 90}, {11,13,14}, {55,56,57}};
    int(* pnumber)[3] = &number[0];
    printf("pnumber's value before passing: %p\n", &pnumber);  
    pointerRecievingArray2D(pnumber);
    return;
}

void pointerRecievingArray2D(int (*pnumber)[3]){
    printf("\nValue Passed:\n");
    printf("pnumber's value after passing: %p\n", &pnumber);                //Output the value (address)
    printf("value pointed to: %d\n", (*pnumber)[2]);                             //Value at the address
    ++pnumber;
    printf("value pointed to: %d\n", (*pnumber)[2]);                             //Value at the address
    ++pnumber;
    printf("value pointed to: %d\n", (*pnumber)[2]);                             //Value at the address

    return;
}



