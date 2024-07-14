#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits> 

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int interval = k;
        for (int num : nums) {
            if (num == 1) {
                if (interval < k) {
                    return false;
                }
                interval = 0;
            }
            else {
                ++interval;
            }
        }
        return true;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Solution solution;
    vector<int> nums;
    int k;
    int num;
    string input;

    char choice;
    do {
        nums.clear();
        cout << "Введите значение k: ";
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Введите элементы массива через пробел (1 и 0): ";
        getline(cin, input);
        stringstream s(input);

        while (s >> num) {
            if (num != 0 && num != 1) {
                cout << "Неверный ввод. Пожалуйста, введите 1 или 0." << endl;
                return 1;
            }
            nums.push_back(num);
        }

        cout << "Ответ: " << (solution.kLengthApart(nums, k) ? "True" : "False") << endl;

        cout << "Хотите попробовать другой массив? (1 - да / 0 - нет): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == '1');

    return 0;
}
