#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string input;
    char choice;

    do {
        cout << "Введите элементы массива через пробел: ";
        getline(cin, input);

        stringstream s(input);
        vector<int> nums;
        int num;

        int a = 0;
        while (s >> num) {
            if (num >= 1 && num <= 100) { // Проверка на ограничения
                nums.push_back(num);
                a++;
            }
            else {
                cout << "Число должно быть в диапазоне от 1 до 100." << endl;
                return 1;
            }
        }

        // Подсчет частоты
        int frequency[101] = { 0 };
        for (int num : nums) {
            frequency[num]++;
        }

        // Суммирование уникальных элементов
        int sum = 0;
        for (int i = 1; i <= 100; ++i) {
            if (frequency[i] == 1) {
                sum += i;
            }
        }

        cout << "Сумма уникальных элементов: " << sum << endl;

        cout << "Хотите попробовать другой массив? (1 - да / 0 - нет): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == '1');

    return 0;
}
