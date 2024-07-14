#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:

    vector<vector<int>> generateMatrix(int n, bool valid) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (valid) {
                // Генерация X-матрицы
                grid[i][i] = rand() % 201 - 100;
                grid[i][n - i - 1] = rand() % 201 - 100;
            }
            else {
                // Генерация не X-матрицы
                for (int j = 0; j < n; ++j) {
                    if (i != j && i != n - j - 1) {
                        grid[i][j] = rand() % n + 1;
                    }
                }
            }
        }
        return grid;
    }

    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == j || i == n - 1 - j) && grid[i][j] == 0)
                    return false;
                if ((i != j && j != n - i - 1) && grid[i][j] != 0)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    Solution solution;
    int n;
    char choice;
    do {

        cout << "Введите размер матрицы (3 <= n <= 100): ";
        cin >> n;
        if (n < 3 || n > 100) {
            cout << "Размер матрицы должен быть 3 <= n <= 100." << endl;
            continue;
        }

    bool actual_invalid_matrix = rand() % 2; // Х-матрица или нет
    vector<vector<int>> matrix = solution.generateMatrix(n, actual_invalid_matrix);
    cout << "Сгенерированная матрица:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }

    bool result = solution.checkXMatrix(matrix);
    cout << "Матрица является Х-матрицей: " << (result ? "True" : "False") << endl;

    cout << "Хотите попробовать другую матрицу? (1 - да / 0 - нет): ";
    cin >> choice;

    } while (choice == '1');

    return 0;
}