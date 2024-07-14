#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int n;
    char choice;

    do {
        cout << "Введите размер матрицы: ";
        cin >> n;
        if (n < 1 || n > 100) {
            cout << "Размер массива должен быть 1 <= n <= 100." << endl;
            continue;
        }

        // Генерация матрицы
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = rand() % 100 + 1; // Случайные числа от 1 до 100
            }
        }

        cout << "Сгенерированная матрица:\n";
        for (const auto& row : mat) {
            for (int val : row) {
                cout << val << "\t";
            }
            cout << "\n";
        }

        // Вычисление суммы диагоналей
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mat[i][i]; // Основная диагональ
            if (i != n - i - 1) {
                sum += mat[i][n - i - 1]; // Побочная диагональ
            }
        }

        cout << "Сумма диагоналей: " << sum << endl;

        cout << "Хотите попробовать другой массив? (1 - да / 0 - нет): ";
        cin >> choice;

    } while (choice == '1');

    return 0;
}
