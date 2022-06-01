#include <stdio.h>
#include <stdlib.h>

int main(){

int minutes;
double days;
double years;

printf("Enter the number of minutes to convert: ");
scanf("%i", &minutes);
printf("You entered %i minutes\n", minutes);
days = (double)minutes / 1440;
years = days/365;
printf("In %i minutes there are %lf days \n", minutes, days);
printf("In %i minutes there are %lf years", minutes, years);
return 0;
}