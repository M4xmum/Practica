#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> answer(n); // Вектор размером n
        for (int index = 1; index <= n; index++) {

            if (index % 3 == 0 && index % 5 == 0) {
                answer[index-1] = "FizzBuzz";
            }
            else if (index % 3 == 0) {
                answer[index-1] = "Fizz";
            }
            else if (index % 5 == 0) {
                answer[index-1] = "Buzz";
            }
            else {
                answer[index-1] = to_string(index);
            }
        }
        return answer;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    Solution solution;
    char choice;
    do {
        cout << "Введите целое число - кол-во элементов: ";
        cin >> n;
        vector<string> result = solution.fizzBuzz(n);
        cout << "Массив: \"";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << "\", \"";
            }
        }
        cout << "\"" << endl;
        cout << "Хотите попробовать другое число? (1 - да / 0 - нет): ";
        cin >> choice;
    } while (choice == '1');

    return 0;
}

