#include <cmath>
#include <stdio.h>
#include <tuple>
using namespace std;

double precision;

tuple<double, int> CalculateViaFor(double Y0, double Y1, double Y2);
tuple<double, int> CalculateViaWhile(double Y0, double Y1, double Y2);
tuple<double, int> CalculateViaDoWhile(double Y0, double Y1, double Y2);
double Calculate(double Y0, double Y2, int n);

int main()
{
    double Y0, Y1, Y2;
    char quitOrRestart;

    do
    {
        printf("Enter Y0, Y1, Y2 and calculation precision: ");
        scanf("%lf %lf %lf %lf", &Y0, &Y1, &Y2, &precision);
        if (precision == 0)
        {
            printf("too precise!");
            continue;
        }

        tuple<double, int> limFor = CalculateViaFor(Y0, Y1, Y2);
        printf("Calculated via FOR:      %lf   n: %i\n", get<0>(limFor), get<1>(limFor));

        tuple<double, int> limWhile = CalculateViaWhile(Y0, Y1, Y2);
        printf("Calculated via WHILE:    %lf   n: %i\n", get<0>(limWhile), get<1>(limWhile));

        tuple<double, int> limDoWhile = CalculateViaDoWhile(Y0, Y1, Y2);
        printf("Calculated via DO-WHILE: %lf   n: %i\n", get<0>(limDoWhile), get<1>(limDoWhile));

        printf("\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ");

        scanf("  %c", &quitOrRestart);
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}

tuple<double, int> CalculateViaFor(double Y0, double Y1, double Y2)
{
    int n = 3;
    double y = Calculate(Y0, Y2, n);
    for (; fabs(y - Y2) > precision;)
    {
        Y0 = Y1;
        Y1 = Y2;
        Y2 = y;
        n++;
        y = Calculate(Y0, Y2, n);
    }

    return {y, n};
}

tuple<double, int> CalculateViaWhile(double Y0, double Y1, double Y2)
{
    int n = 2;
    double y = Calculate(Y0, Y2, n);
    while (fabs(y - Y2) > precision)
    {
        Y0 = Y1;
        Y1 = Y2;
        Y2 = y;
        n++;
        y = Calculate(Y0, Y2, n);
    }

    return {y, n};
}

tuple<double, int> CalculateViaDoWhile(double Y1, double Y2, double y)
{
    int n = 3;
    double Y0;
    do
    {
        Y0 = Y1;
        Y1 = Y2;
        Y2 = y;
        n++;
        y = Calculate(Y0, Y2, n);
    } while (fabs(y - Y2) > precision);

    return {y, n};
}

double Calculate(double Y0, double Y2, int n)
{
    return (Y2 + 2 * Y0 + 3) /
           (7 * sqrt(pow(n, 3) + 2) + 3 * sqrt(pow(n, 2) + 5));
}