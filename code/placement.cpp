#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

typedef int element;
typedef element *row;
typedef row *matrix;

int read_width()
{
    cout << "Enter half of matrix width: ";
    int n;
    cin >> n;
    return 2 * n;
}

void read_matrix(int width, matrix m)
{
    char auto_or_manual;
    while (true)
    {
        cout << "Enter \"A\" to fill automaticly matrix, or \"M\" to fill manually: ";
        cin >> auto_or_manual;
        if (auto_or_manual == 'a' || auto_or_manual == 'A')
        {
            // fill automaticly
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    m[i][j] = i * width + j;
                }
            }
            return;
        }
        else if (auto_or_manual == 'm' || auto_or_manual == 'M')
        {
            // fill manually
            cout << "Enter matrix " << width << 'x' << width << "\n";
            for (int y = 0; y < width; y++)
            {
                for (int x = 0; x < width; x++)
                    cin >> m[y][x];
            }
            return;
        }
    }
}

// Сортировка по убыванию методом обмена с флагом перестановки
void sort_row(row row, int start_index, int end_index)
{
    for (int i = start_index; i < end_index; i++)
    {
        for (int j = start_index; j < end_index - 1; j++)
        {
            if (row[j] < row[j + 1])
            {
                int b = row[j];
                row[j] = row[j + 1];
                row[j + 1] = b;
            }
        }
    }
}

void sort_matrix(int width, matrix m)
{
    for (int row_index = 0; row_index < width; row_index++)
    {
        int start_index = abs(((int)width / 2) - row_index);
        sort_row(m[row_index], start_index, width - start_index);
    }
}

void print_matrix(int width, matrix m)
{
    for (int i = 0; i < width; i++)
    {
        cout << endl;
        for (int j = 0; j < width; j++)
        {
            cout.width(4);
            cout << m[i][j];
        }
    }
}

int main()
{
    char quitOrRestart = 'r';

    do
    {
        quitOrRestart = 'r';
        int width = read_width();
        if (width <= 0)
        {
            cout << "Matrix width mast be positive";
            continue;
        }

        matrix m = new row[width];
        for (int i = 0; i < width; i++)
        {
            m[i] = new element[width];
        }

        read_matrix(width, m);

        cout << "\n\nOriginal matrix:";
        print_matrix(width, m);

        sort_matrix(width, m);

        cout << "\n\nSwaped matrix:";
        print_matrix(width, m);

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}