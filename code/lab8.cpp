#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char quitOrRestart = 'r';

    do
    {
        int n;
        cout << "\nEnter half of array length (greater than 0): ";
        cin >> n;
        if (n < 1)
        {
            cout << "length should be greater than 0";
        }

        int b[n * 2];
        for (int i = 0; i < 2 * n; i++) { cin >> b[i]; }


        int max_signed = -INFINITY;
        int max_signed_index;
        for (int i = 0; i < n * 2; i++)
        {
            if (b[i] < 0 && b[i] > max_signed)
            {
                max_signed = b[i];
                max_signed_index = i;
            }
        }
        if (max_signed == -INFINITY)
        {
            cout << "No signed numbers found!";
            continue;
        }


        int last_before_n_unsigned_index = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (b[i] > 0) last_before_n_unsigned_index = i;
        }
        if (last_before_n_unsigned_index == -1)
        {
            cout << "No unsigned numbers found in first half of array!";
            continue;
        }

        int left_bound = min(max_signed_index, last_before_n_unsigned_index);
        int right_bound = max(max_signed_index, last_before_n_unsigned_index);

        if (left_bound % 2 == 0) left_bound++;

        cout << "Left bound index: " << left_bound << endl;
        cout << "Right bound index: " << right_bound << endl;

        int sum = 0;
        for (int i = left_bound; i <= right_bound; i += 2)
        {
            sum += b[i];
        }

        cout << "Sum: " << sum;

        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}