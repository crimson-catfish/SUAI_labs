#include <iostream>

int factorial(int num)
{
    if (num <= 1)
        return 1;
    return (num * factorial(num - 1));
}

int factorial2(int n)
{
    if (n == 1)
        return (1); /*Terminating condition*/
    else
    {
        return (n * factorial2(n - 1));
    }
}

int main()
{
    std::cout << "factorial: ";
    std::cout << factorial(4);
}