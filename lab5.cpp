#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

double precision;

double CalculateViaFor(double Y0, double Y1, double Y2);
double CalculateViaWhile(double Y0, double Y1, double Y2);
double CalculateViaDoWhile(double Y0, double Y1, double Y2);
double Calculate(double Y0, double Y2, int n);

int main()
{
    char quitOrRestart;
    double Y0, Y1, Y2;

    do
    {
        printf("Enter Y0, Y1, Y2 and calculation precision: ");
        scanf("%lf %lf %lf, %lf", &Y0, &Y1, &Y2, &precision);

        double limFor = CalculateViaFor(Y0, Y1, Y2);
        double limWhile = CalculateViaWhile(Y0, Y1, Y2);
        double limDoWhile = CalculateViaDoWhile(Y0, Y1, Y2);

        printf("Calculated via FOR: %f\n", limFor);
        printf("Calculated via WHILE: %f\n", limWhile);
        printf("Calculated via DO-WHILE: %f\n", limDoWhile);

        printf("\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ");

        scanf(" %c", &quitOrRestart);
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}

double CalculateViaFor(double Y0, double Y1, double Y2)
{
    double y = Calculate(Y0, Y2, 3);
    for (int n = 3; fabs(y - Y2) <= precision; n++)
    {
        Y0 = Y1;
        Y1 = Y2;
        Y2 = y;
        y = Calculate(Y0, Y2, n);
    }

    return y;
}

double CalculateViaWhile(double Y0, double Y1, double Y2)
{
    double y = Calculate(Y0, Y2, 3);

    int n = 3;
    while (fabs(y - Y2) <= precision)
    {
        Y0 = Y1;
        Y1 = Y2;
        Y2 = y;
        y = Calculate(Y0, Y2, n);
        n++;
    }

    return y;
}

double CalculateViaDoWhile(double Y0, double Y1, double Y2)
{
    double y;

    int n = 3;
    do
    {
        y = Calculate(Y0, Y2, n);
        Y0 = Y1;
        Y1 = Y2;
        Y2 = y;
        n++;
    } while (fabs(y - Y1) <= precision);

    return y;
}

double Calculate(double Y0, double Y2, int n)
{
    return (Y2 + 2 * Y0 + 3) /
           (7 * sqrt(pow(n, 3) + 2) + 3 * sqrt(pow(n, 2) + 5));
}