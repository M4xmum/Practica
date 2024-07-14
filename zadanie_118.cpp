#include <iostream>
using namespace std;

// Функция для вычисления факториала
long long factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

// Функция для вычисления комбинации C(n, k)= n!/ (k!*(n - k)!)
long long combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void printPascalTriangle(int n) {
    cout << "[";
    for (int i = 1; i <= n; ++i) {
        cout << "[";
        // Вывод коэффициентов для (a + b)^i
        for (int j = 0; j < i; ++j) {
            cout << combination(i - 1, j);
            if (j < i - 1) { 
                cout << ", ";
            }
        }
        cout << "]";
        if (i < n) {
            cout << ", ";
        }
    }
    cout << "] \n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numRows;
    char choice;
    do {
    cout << "Введите количество строк треугольника Паскаля: ";
    cin >> numRows;
    printPascalTriangle(numRows);
    cout << "Посмотреть треугольник Паскаля с другим количесвтом строк? (1 - да / 0 - нет): ";
    cin >> choice;
    } while (choice == '1');
    return 0;
}
