

#include <iostream>

using namespace std;

// Возвращаем количество необходимых ящиков 
int nextFit(int weight[], int n, int c)
{
    // инициализируем результат  (количество ящиков) и оставшуюсю вместимость текущего ящика
    int res = 0, bin_rem = c;

    // Скалдываем предметы один за другим
    for (int i = 0; i < n; i++) {
        // если предмет не помещается в ящик
        if (weight[i] > bin_rem) {
            res++; // помещаем в новый
            bin_rem = c - weight[i];
        }
        else
            bin_rem -= weight[i];
    }
    return res;
}


int main()
{
    int weight[] = { 2, 5, 4, 7, 1, 3, 8 };
    int c = 10;
    int n = sizeof(weight) / sizeof(weight[0]);
    cout << "Number of bins required in Next Fit : "
        << nextFit(weight, n, c);
    return 0;
}