#include <stdio.h>


#define MONTHS 12
#define YEARS 5

int main()
{
    // initialize rainfall data for 2011-2015
    float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };


    float total = 0.0, averageRainfall;
    float monthRainfall= 0;
    int monthNum = 0;
    float overallTotal = 0.0, overallTotalAvg = 0.0;


    for(int i = 0; i < YEARS; i++){
        for(int j = 0; j < MONTHS; j++){
            total += rain[i][j];
        }
        averageRainfall = total/MONTHS;
        printf("For year %i the average rainfall was: %f\n", i, averageRainfall);
        printf("The total rainfall was %f\n", total);
        overallTotal += total;
        total = 0;
        averageRainfall = 0;
    }
    overallTotalAvg = overallTotal / (float)YEARS;

    printf("The overall total Avg is: %f\n", overallTotalAvg);

    printf("\n");
    printf("Calculating monthly rainfall...\n");

    for(int i = 0; i < MONTHS; i++){
        for(int j = 0; j < YEARS; j++){
            monthRainfall += rain[j][i];
        }
        averageRainfall = monthRainfall/YEARS;
        printf("For Month %i the average rainfall was %f over a five year period.\n", i + 1, averageRainfall);
        monthRainfall = 0;
    }

}