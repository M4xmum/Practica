#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x, result = 0;
        while (left <= right) {
            long long middle = left + (right - left) / 2;
            if (middle * middle <= x) {
                result = middle;
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Solution solution;
    int number;
    char choice;
    do {
        cout << "Введите неотрицательное целое число: ";
        cin >> number;
        cout << "Квадратный корень из " << number << " равен: " << solution.mySqrt(number) << endl;
        cout << "Хотите попробовать другое число? (1 - да / 0 - нет): ";
        cin >> choice;
    } while (choice == '1');
    return 0;
}