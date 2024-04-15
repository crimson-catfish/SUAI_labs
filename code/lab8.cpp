#include <iostream>
#include <limits>
using namespace std;

const int ARRAY_SIZE = 32;

typedef int my_element;
typedef my_element my_array[ARRAY_SIZE];

int read_array_length()
{
    int n;
    cout << "\nEnter half of array length (greater than 0): ";
    cin >> n;
    if (n < 1)
    {
        cout << "length should be greater than 0";
    }
    return n;
}

void read_user_array(int n, my_array out)
{
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> out[i];
    }
}

int find_max_nonpositive_index(my_array b, int half_array_length)
{
    int max_nonpositive;
    int max_nonpositive_index = -1;
    for (int i = 0; i < half_array_length * 2; i++)
    {
        if (b[i] <= 0)
        {
            max_nonpositive = b[i];
            max_nonpositive_index = i;
            break;
        }
        if (i == half_array_length * 2 - 1)
            return -1;
    }

    for (int i = 0; i < half_array_length * 2; i++)
    {
        if (b[i] <= 0 && b[i] > max_nonpositive)
        {
            max_nonpositive = b[i];
            max_nonpositive_index = i;
        }
    }
    return max_nonpositive_index;
}

int find_last_before_n_unsigned_index(my_array b, int half_array_length)
{
    for (int i = half_array_length - 1; i >= 0; i--)
    {
        if (b[i] > 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char quitOrRestart = 'r';

    do
    {
        int n = read_array_length();
        my_array b;
        read_user_array(n, b);

        int max_nonpositive_index = find_max_nonpositive_index(b, n);
        if (max_nonpositive_index == -1)
        {
            cout << "No nonpositive numbers found!\n";
            continue;
        }

        int last_before_n_unsigned_index = find_last_before_n_unsigned_index(b, n);
        if (last_before_n_unsigned_index == -1)
        {
            cout << "No unsigned numbers found in first half of array!\n";
            continue;
        }

        int left_bound = min(max_nonpositive_index, last_before_n_unsigned_index);
        int right_bound = max(max_nonpositive_index, last_before_n_unsigned_index);

        cout << "Left bound index: " << left_bound << endl;
        cout << "Right bound index: " << right_bound << endl;

        if (left_bound % 2 == 0)
            left_bound++;

        int sum = 0;
        for (int i = left_bound; i < right_bound; i += 2)
        {
            sum += b[i];
        }

        cout << "Sum: " << sum;

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}