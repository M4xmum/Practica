#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    int sum(int num1, int num2){
        return num1 + num2;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    Solution solution;
    int num1, num2;
    char choice;
    do {
        //-100 <= num1, num2 <= 100
        num1 = rand() % 201 - 100;
        num2 = rand() % 201 - 100;

        cout << "Число 1: " << num1 << " и число 2: " << num2 << endl;

        if (num1 < 0) {
            cout << "(" << num1 << ")";
        }
        else {
            cout << num1;
        }
        cout << " + ";
        if (num2 < 0) {
            cout << "(" << num2 << ")";
        }
        else {
            cout << num2;
        }
        cout << " = " << solution.sum(num1, num2) << endl;

        cout << "Хотите попробовать другие числа? (1 - да / 0 - нет): ";
        cin >> choice;

    } while (choice == '1');

    return 0;
}