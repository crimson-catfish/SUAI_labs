#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

double precision;

double Calculate(double Y0, double Y2, int n);

int main()
{
    float start, end, step;
    char quitOrRestart;

    do
    {
        cout << "Enter argument start (0 < start < 1): ";
        cin >> start;
        if (start >= 1 || start <= 0)
        {
            cout << "Invalid input! Please enter a number between 0 and 1";
            continue;
        }

        cout << "Enter argument end (start <= end < 1): ";
        cin >> end;
        if (end >= 1 || start < end)
        {
            cout << "Invalid input! Please enter a number between start and 1";
            continue;
        }

        cout << "Enter argument step (step > 0): ";
        cin >> start;
        if (step <= 0)
        {
            cout << "Invalid input! Please enter a number greater than 0";
            continue;
        }

        cout << "Enter precision (0 < precision <= 0.1): ";
        cin >> precision;
        if (0 >= precision || precision > 0.1)
        {
            cout << "Invalid input! Please enter a number between than 0";
            continue;
        }

        cout << "\n| argument |  sum  | terms count | reference value |\n";

        for (int n = start; n <= end; n += step)
        {
        }

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}

double Calculate(double Y0, double Y2, int n)
{
    return (Y2 + 2 * Y0 + 3) /
           (7 * sqrt(pow(n, 3) + 2) + 3 * sqrt(pow(n, 2) + 5));
}