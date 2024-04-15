#include <iostream>
using namespace std;

const int MATRIX_SIDE = 16;

typedef int my_element;
typedef my_element matrix[MATRIX_SIDE][MATRIX_SIDE];

unsigned int read_width()
{
    cout << "Enter half of matrix width: ";
    unsigned int n;
    cin >> n;
    return 2 * n + 1;
}

void read_matrix(unsigned int width, matrix m)
{
    cout << "Enter matrix " << width << 'x' << width << "\n";
    for (int y = 0; y < width; y++)
    {
        for (int x = 0; x < width; x++)
            cin >> m[y][x];
    }
}

void swap_middle_row_and_column(unsigned int width, matrix m)
{
    unsigned int buffer;
    for (int i = 0; i < width; i++)
    {
        buffer = m[width / 2][i];
        m[width / 2][i] = m[i][width / 2];
        m[i][width / 2] = buffer;
    }
}

void print_matrix(unsigned int width, matrix m)
{
    for (int i = 0; i < width; i++)
    {
        cout << endl;
        for (int j = 0; j < width; j++)
        {
            cout.width(3);
            cout << m[i][j];
        }
    }
}

int main()
{
    char quitOrRestart = 'r';

    do
    {
        unsigned int width = read_width();
        matrix m;
        read_matrix(width, m);

        cout << "\n\nOriginal matrix:";
        print_matrix(width, m);

        swap_middle_row_and_column(width, m);

        cout << "\n\nSwaped matrix:";
        print_matrix(width, m);

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}