#define _USE_MATH_DEFINES

#include <cmath>
#include <stdio.h>

enum Areas
{
    M1,
    M2,
    M3,
    M4,
    M5
};

class PointToCheck
{
public:
    float x, y;

    bool isInSircle(int circleX, int circleY)
    {
        return (pow((x - circleX), 2) + pow((y - circleY), 2) <= 1);
    }

    bool isInSquare(int squareLeftX, int squareDownY, int squareRightX, int squareUpY)
    {
        return (x > squareLeftX && x < squareRightX && y > squareDownY && y < squareUpY);
    }
};

int main()
{
    char quitOrRestart;

    do
    {
        PointToCheck point;
        printf("Enter point's coordinates: ");
        scanf(" %f %f", &point.x, &point.y);

        Areas area;

        if (point.isInSircle(1, 1) && !point.isInSircle(0, 1) && !point.isInSquare(0, 0, 2, 1))
            area = M1;
        else if (point.isInSircle(-1, 1) && !point.isInSircle(-1, 0) && point.isInSquare(-2, 0, -1, 1))
            area = M2;
        else if (point.isInSircle(0, 0) && !point.isInSircle(-1, -1) && !point.isInSircle(1, -1))
            area = M3;
        else if (point.isInSircle(-1, 0) && point.isInSircle(0, -1) && !point.isInSircle(0, 0))
            area = M4;
        else if (point.isInSircle(1, -1) && !point.isInSircle(0, 0) && !point.isInSircle(1, 0))
            area = M5;
        else
            printf("Point does not belong to any area");

        float S;
        switch (area)
        {
        case M1:
            S = M_PI / 6 + sqrt(3) / 4;
            printf("Point belongs to area M1. S1 = %f", S);
            break;
        case M2:
            S = sqrt(3) / 4 - M_PI / 12;
            printf("Point belongs to area M2. S2 = %f", S);
            break;
        case M3:
            S = 2;
            printf("Point belongs to area M3. S3 = %f", S);
            break;
        case M4:
            S = M_PI / 12 - 1 + sqrt(3) / 2;
            printf("Point belongs to area M4. S4 = %f", S);
            break;
        case M5:
            S = 1 + M_PI / 4;
            printf("Point belongs to area M5. S5 = %f", S);
            break;
        }

        printf("\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ");
        scanf(" %c", &quitOrRestart);
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}