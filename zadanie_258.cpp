#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int result = num % 9;
        if (result == 0) return 9;
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Solution solution;
    int num;
    char choice;
    do {
        cout << "Введите целое число: ";
        cin >> num;
        cout << "Цифровой корень из числа " << num << " равен: " << solution.addDigits(num) << endl;
        cout << "Хотите попробовать другое число? (1 - да / 0 - нет): ";
        cin >> choice;
    } while (choice == '1');
    return 0;
}