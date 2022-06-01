#include <stdio.h>
#include <stdbool.h>


void generatePrimeNumbers(){

    int primeNumbers[50] = {0};
    int count = 2;

    //hardcode prime Numbers
    primeNumbers[0] = 2;
    primeNumbers[1] = 3;

    bool isPrime;

    for(int i = 5; i <= 100; i = i+2){

        isPrime = true;

        for (int j = 1; isPrime && i/primeNumbers[j] >=primeNumbers[j]; j++){  //isprime && i/primeNumbers[j] >= primeNumbers[j] is the for loops continuation statement
            //if number is not prime set isPrime to false
            if(i % primeNumbers[j] == 0){
                isPrime = false;
            }
             //if number is prime add it to prime Numbers array
            else{
                primeNumbers[count] = i;
                count++;
            }

        }
    }
    printf("Prime Numbers:\n");

    //prints out the prime numbers
    for (int i =0; i < count; i++){
        printf("%i\n", primeNumbers[i]);
    }
}

int main(){

    printf("Generating Prime Numbers\n");   
    generatePrimeNumbers();


    int grades[10];     //declareing an array of size 10 
    int count = 10;
    long sum = 0;
    float average = 0.0f;

    printf("\nEnter the 10 grades:\n");

    for(int i =0; i < count; i++){
        printf("%2u>", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];

    }

    average = (float)sum/count;
    printf("\nAverage of the ten grades entered is: %2f\n", average);

    return 0;

}

