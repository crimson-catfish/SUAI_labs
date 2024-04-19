#include <iostream>
#include <limits>
using namespace std;

const int ARRAY_SIZE = 32;

typedef int my_element;
typedef my_element my_array[ARRAY_SIZE];
typedef int half_array_length;
typedef int last_max_nonpositive;
typedef int last_max_nonpositive_index;
typedef int last_before_n_unsigned_index;
typedef int sum_of_odd_elements;

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

last_max_nonpositive_index find_last_max_nonpositive_index(my_array b, half_array_length half_array_length)
{
    last_max_nonpositive max_nonpositive;
    last_max_nonpositive_index last_max_nonpositive_index = -1;
    for (int i = 0; i < half_array_length * 2; i++)
    {
        if (b[i] <= 0)
        {
            max_nonpositive = b[i];
            last_max_nonpositive_index = i;
            break;
        }
        if (i == half_array_length * 2 - 1)
            return -1;
    }

    for (int i = last_max_nonpositive_index + 1; i < half_array_length * 2; i++)
    {
        if (b[i] <= 0 && b[i] >= max_nonpositive)
        {
            max_nonpositive = b[i];
            last_max_nonpositive_index = i;
        }
    }
    return last_max_nonpositive_index;
}

last_before_n_unsigned_index find_last_before_n_unsigned_index(my_array b, half_array_length half_array_length)
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

sum_of_odd_elements find_sum_of_odd_elements(my_array b, last_max_nonpositive_index bound1, last_before_n_unsigned_index bound2)
{
    int left_bound = min(bound1, bound2);
    int right_bound = max(bound1, bound2);

    cout << "Left bound index: " << left_bound << endl;
    cout << "Right bound index: " << right_bound << endl;

    // Если левая граница четная - делаем ее нечетной
    // Если нечетная - ничего не меняем
    if (left_bound % 2 == 0)
        left_bound++;

    sum_of_odd_elements sum = 0;
    for (int i = left_bound; i < right_bound; i += 2)
    {
        sum += b[i];
    }

    return sum;
}

int main()
{
    char quitOrRestart = 'r';

    do
    {
        int n = read_array_length();
        my_array b;
        read_user_array(n, b);

        last_max_nonpositive_index last_max_nonpositive_index = find_last_max_nonpositive_index(b, n);
        if (last_max_nonpositive_index == -1)
        {
            cout << "No nonpositive numbers found!\n";
            continue;
        }

        last_before_n_unsigned_index last_before_n_unsigned_index = find_last_before_n_unsigned_index(b, n);
        if (last_before_n_unsigned_index == -1)
        {
            cout << "No unsigned numbers found in first half of array!\n";
            continue;
        }

        sum_of_odd_elements sum = find_sum_of_odd_elements(b, last_max_nonpositive_index, last_before_n_unsigned_index);
        cout << "Sum: " << sum;

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}