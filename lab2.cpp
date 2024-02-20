// Вычислить x = max(min(b, c) - d , min(a, b))
#include <stdio.h>
using namespace std;

// функции выбора
int max_choose(int a, int b) { return (a > b)? a : b;}
int min_choose(int a, int b) { return (a < b)? a : b;}

// функции обхода
int max_bypass(int a, int b) { int max = a; return (b > max)? b : max; }
int min_bypass(int a, int b) { int min = a; return (b < min)? b : min; }

int x;

int main()
{
    int a, b, c, d;
    printf("\nEnter numbers to compare a, b, c, d: ");
    scanf("%i%i%i%i", &a, &b, &c, &d);

    // Решение задачи с использованием структуры "Выбор"
    x = max_choose(min_choose(b, c) - d , min_choose(a, b));
    printf("Using choose: x = %i\n", x);

    // Решение задачи с использованием структуры "Обход"
    x = max_bypass(min_bypass(b, c) - d , min_bypass(a, b));
    printf("Using bypass: x = %i\n", x);

    char quitOrRestart;
    printf("\nPress \"R\" to run again, or enter any other letter to quit programm: ");
    scanf(" %c", &quitOrRestart);
    if (quitOrRestart == 'q' || quitOrRestart == 'Q') return 0;
    else main();
}