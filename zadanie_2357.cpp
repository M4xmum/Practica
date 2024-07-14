#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        bool found;

        do {
            int x = INT_MAX;
            found = false;

            for (int num : nums) {
                if (num > 0 && num < x) {
                    x = num;
                    found = true;
                }
            }

            if (found) {
                for (int& num : nums) {
                    if (num > 0) {
                        num -= x;
                    }
                }
                operations++;
            }
        } while (found);

        return operations;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));
    Solution solution;
    int n;
    char choice = '0';
    do {

        cout << "Введите количество элементов в массиве: ";
        cin >> n;
        if (n < 1 || n > 100) {
            cout << "Размер массива должен быть 1 <= n <= 100." << endl;
            continue;
        }

        vector<int> nums(n);
        cout << "Сгенерированный массив: ";
        for (int i = 0; i < n; ++i) {
            nums[i] = rand() % 101;
            cout << nums[i] << " ";
        }
        cout << endl;

        int result = solution.minimumOperations(nums);
        cout << "Минимальное количество операций: " << result << endl;

        cout << "Хотите попробовать другой массив? (1 - да / 0 - нет): ";
        cin >> choice;

    } while (choice == '1');

    return 0;
}
