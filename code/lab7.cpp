#include <iostream>
#include <cmath>
using namespace std;


class Vertex
{
    public: float x, y;
};

float traingle_area(Vertex v1, Vertex v2, Vertex v3)
{
    // Calculate the sides of the triangle
    float a = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
    float b = sqrt(pow(v3.x - v2.x, 2) + pow(v3.y - v2.y, 2));
    float c = sqrt(pow(v3.x - v1.x, 2) + pow(v3.y - v1.y, 2));

    // Calculate the semi-perimeter of the triangle
    double s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

void traingle_area(Vertex v1, Vertex v2, Vertex v3, float * out)
{
    // Calculate the sides of the triangle
    float a = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
    float b = sqrt(pow(v3.x - v2.x, 2) + pow(v3.y - v2.y, 2));
    float c = sqrt(pow(v3.x - v1.x, 2) + pow(v3.y - v1.y, 2));

    // Calculate the semi-perimeter of the triangle
    double s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    *out = area;
}

void traingle_area(Vertex v1, Vertex v2, Vertex v3, float & out)
{
    // Calculate the sides of the triangle
    float a = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
    float b = sqrt(pow(v3.x - v2.x, 2) + pow(v3.y - v2.y, 2));
    float c = sqrt(pow(v3.x - v1.x, 2) + pow(v3.y - v1.y, 2));

    // Calculate the semi-perimeter of the triangle
    double s = (a + b + c) / 2;

    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    out = area;
}

int main()
{
    char quitOrRestart = 'r';

    do
    {
        Vertex quad[4];
        cout << "Enter X and Y for each vertex of convex quadrilateral:\n";
        for (int i = 0; i < 4; i++)
        {
            cin >> quad[i].x;
            cin >> quad[i].y;
        }

        cout << "\nOutput via return:    ";
        if (traingle_area(quad[0], quad[1], quad[2]) == traingle_area(quad[0], quad[3], quad[2])
            && traingle_area(quad[1], quad[2], quad[3]) == traingle_area(quad[1], quad[0], quad[3]))
        { cout << "This is a parallelogram!"; }
        else cout << "This is just a quadrilateral";

        float traingle_areas[4];

        cout << "\nOutput via pointer:   ";
        traingle_area(quad[0], quad[1], quad[2], &traingle_areas[0]);
        traingle_area(quad[0], quad[3], quad[2], &traingle_areas[1]);
        traingle_area(quad[1], quad[2], quad[3], &traingle_areas[2]);
        traingle_area(quad[1], quad[0], quad[3], &traingle_areas[3]);
        if (traingle_areas[0] == traingle_areas[1] && traingle_areas[2] == traingle_areas[3])
        { cout << "This is a parallelogram!"; }
        else cout << "This is just a quadrilateral";

        cout << "\nOutput via reference: ";
        traingle_area(quad[0], quad[1], quad[2], traingle_areas[0]);
        traingle_area(quad[0], quad[3], quad[2], traingle_areas[1]);
        traingle_area(quad[1], quad[2], quad[3], traingle_areas[2]);
        traingle_area(quad[1], quad[0], quad[3], traingle_areas[3]);
        if (traingle_areas[0] == traingle_areas[1] && traingle_areas[2] == traingle_areas[3])
        { cout << "This is a parallelogram!"; }
        else cout << "This is just a quadrilateral";

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}

