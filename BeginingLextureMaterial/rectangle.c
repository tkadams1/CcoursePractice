#include <stdio.h>
#include <stdlib.h>

int main() 
{
double height = 0;
double width = 0;
double perimeter = 2 *(height+width);
double area = width * height;

printf("Enter the height of the rectangle: ");
scanf("%lf", &height);
printf("Enter the width of the rectangle: ");
scanf("%lf", &width);

printf("%f", height);
return 0;
}