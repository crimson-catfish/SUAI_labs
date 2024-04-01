#include <iostream>
using namespace std;

unsigned int read_width()
{
    cout << "Enter half of matrix width: ";
    unsigned int n;
    cin >> n;
    return 2 * n + 1;
}

int ** read_matrix(unsigned int width)
{
    int ** m;
    m = new int * [width];
    cout << "Enter matrix " << width << 'x' << width << "\n";
    for (int y = 0; y < width; y++)
    {
        m[y] = new int [width];
        for (int x = 0; x < width; x++)
        {
            cin >> m[y][x];
        }
    }
    return m;
}

int ** swap_middle_row_and_column(int ** m, unsigned int width)
{
    unsigned int buffer;
    for (int i = 0; i < width; i++)
    {
        buffer = m[width / 2][i];
        m[width / 2][i] = m[i][width / 2];
        m[i][width / 2] = buffer;
    }
    return m;
}

void  print_matrix(int ** m, unsigned int width)
{
    for (int i = 0; i < width; i++)
    {
        cout << endl << endl;
        for (int j = 0; j < width; j++)
        {
            cout << m[i][j] << '\t';
        }
    }
}

int main()
{
    char quitOrRestart = 'r';

    do
    {
        unsigned int width = read_width();
        int ** m = read_matrix(width);

        cout << "\n\nOriginal matrix:";
        print_matrix(m, width);

        m = swap_middle_row_and_column(m, width);

        cout << "\n\nSwaped matrix:";
        print_matrix(m, width);

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}