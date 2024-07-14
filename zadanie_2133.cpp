#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    bool isValidMatrix(const vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            vector<bool> row(n, false);
            vector<bool> column(n, false);
            for (int j = 0; j < n; ++j) {
                // Проверка строк
                if (matrix[i][j] < 1 || matrix[i][j] > n || row[matrix[i][j] - 1]) {
                    return false;
                }
                row[matrix[i][j] - 1] = true;
                // Проверка столбцов
                if (matrix[j][i] < 1 || matrix[j][i] > n || column[matrix[j][i] - 1]) {
                    return false;
                }
                column[matrix[j][i] - 1] = true;
            }
        }
        return true;
    }

    vector<vector<int>> generateMatrix(int n, bool valid) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (valid) {
                // Генерация действительной матрицы
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = (i + j) % n + 1;
                }
            }
            else {
                // Генерация недействительной матрицы
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = rand() % n + 1;
                }
            }
        }
        return matrix;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    Solution solution;
    int n;
    char choice;
    do {
    cout << "Введите n: ";
    cin >> n;
    
    cout << "Сгенерированная матрица:" << endl;
    bool actual_invalid_matrix = rand() % 2; // действительная или недействительная матрица
    vector<vector<int>> matrix = solution.generateMatrix(n, actual_invalid_matrix);
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }

    cout << "Матрица: действительна?" << endl;
    cout << "Ответ: " << (solution.isValidMatrix(matrix) ? "True" : "False") << endl;

    cout << "Хотите попробовать другую матрицу? (1 - да / 0 - нет): ";
    cin >> choice;

    } while (choice == '1');

    return 0;
}