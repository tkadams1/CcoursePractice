#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    char name[30];
    char hireDate[15];
    float salary;
};

struct item{
    char *itemName;
    int quantity;
    float price;
    float amount;
};

void structuresDemo();
void structAndPointers();
void readItem(struct item *itm);
void printItem(struct item *itm);


int main()
{
   // structuresDemo();
    structAndPointers();

    return 0;
}

void structuresDemo(){

    struct employee John = {"John", "7/16/15", 80000.00f};

    printf("\nEmployee Name: %s", John.name);
    printf("\nId: %s", John.hireDate);
    printf("\nSalary: %f", John.salary);

    struct employee emp;
    printf("\n\nEnter employee information: ");

    printf("\nName: ");
    scanf("%s", emp.name);

    printf("\nHire Date: ");
    scanf("%s", emp.hireDate);

    printf("\nSalary: ");
    scanf("%f", &emp.salary);  //Address of operator needed for anything other than a string inside a struct

    printf("\nEmployee Name: %s", emp.name);
    printf("\nId: %s", emp.hireDate);
    printf("\nSalary: %f\n", emp.salary);

    return;
}

void structAndPointers(){

    //create item struct
    struct item itm;
    //create pointer to item
    struct item *pItem;

    pItem = &itm;

    //(*pItem).itemName = (char *)malloc(30* sizeof(char)); //this works too
    pItem -> itemName = (char *) malloc(30* sizeof(char));

    //check for null
    if(pItem == NULL)
        exit(-1);

    readItem(pItem);
    printItem(pItem);

    free(pItem->itemName);
    return;
}

void readItem(struct item *itm){
    
    printf("\nEnter product name: ");
    scanf("%s", itm->itemName);

    printf("\nEnter price: ");
    scanf("%f", &itm->price);

    printf("\nEnter quantity: ");
    scanf("%d", &itm->quantity);

    itm->amount = itm->price * (float)itm->quantity;


    return;
}

void printItem(struct item *itm){

    printf("\nItem Name: %s", itm->itemName);
    printf("\nQuantity: %f", itm->price);
    printf("\nPrice: %d", itm->quantity);
    printf("\nAmount: %.2f\n", itm->amount);

    return;
}

