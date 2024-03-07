#include <cmath>
#include <stdio.h>

double A, B;
int n;

double CalculateViaFor();
double CalculateViaWhile();
double CalculateViaDoWhile();
double Calculate(int i);

int main()
{
    char quitOrRestart;

    do
    {
        printf("Enter A, B and n parameters: ");
        scanf("%lf %lf %i", &A, &B, &n);
        printf("%f %f %i", A, B, n);

        double S_for = CalculateViaFor();
        double S_While = CalculateViaWhile();
        double S_DoWhile = CalculateViaDoWhile();

        printf("Result calculated via FOR: %f\n", S_for);
        printf("Result calculated via WHILE: %f\n", S_While);
        printf("Result calculated via DO-WHILE: %f\n", S_DoWhile);

        printf("\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ");

        scanf(" %c", &quitOrRestart);
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}

double CalculateViaFor()
{
    double S = 0;

    for (int i = 2; i < (2 * n + 2); i += 2)
    {
        S += Calculate(i);
    }

    S *= ((double)2 / (double)n - B);
    return S;
}

double CalculateViaWhile()
{
    double S = 0;

    int i = 2;
    while (i < (2 * n + 2))
    {
        S += Calculate(i);
        i += 2;
    }

    S *= ((double)2 / (double)n - B);
    return S;
}

double CalculateViaDoWhile()
{
    double S = 0;

    int i = 2;
    do
    {
        S += Calculate(i);
        i += 2;
    } while (i < (2 * n + 2));

    S *= ((double)2 / (double)n - B);
    return S;
}

double Calculate(int i)
{
    double x = (double)4 * (double)i / (double)5 + 1.5;
    return A * (x - (double)i / (double)n) / (B * x + A - i);
}