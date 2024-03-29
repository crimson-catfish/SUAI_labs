#include <iostream>
using namespace std;

int main()
{
    char quitOrRestart = 'r';

    do
    {
        


        cout << "\n\nEnter \"R\" to run again, or enter any other letter to quit programm: ";
        cin >> quitOrRestart;
    } while (quitOrRestart == 'r' || quitOrRestart == 'R');

    return 0;
}