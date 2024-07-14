//Задание №2827
#include <iostream>
#include <locale.h>
#include <vector>

using namespace std;

int countc(int num) {
	int dl = 0;
	while (num > 0) {
		dl++;
		num /= 10;
	}
	return dl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int low = 0, high = 0, k = 0, c = 1, t = 0, ch = 0, nch = 0, result = 0;
	while (1) {
		cout << "Введите дипазон значений (не < 1 и не > 10^9)" << endl << "От: ";
		cin >> low;
		cout << "До: ";
		cin >> high;
		if (low > 0 && high <= pow(10, 9))
			break;
		else
			cout << "Неверный ввод! Повторите ещё раз!" << endl;
	}

	while (1) {
		cout << "Введите число, на которое должны делиться красивые числа (от 1 до 20): ";
		cin >> k;
		if (k > 0 && k <= 20)
			break;
		else
			cout << "Неверный ввод! Повторите ещё раз!" << endl;
	}
	for (int i = low; i < high + 1; i++) {
		if (i % k == 0) {
			for (int j = 0; j < countc(i);j++) {
				t = i / c % 10;
				c *= 10;
				if (t % 2 == 0)
					ch++;
				else
					nch++;
			}
			if (nch == ch && nch != 0 && ch != 0)
				result++;
			nch = 0;
			ch = 0;
			c = 1;
		}

	}
	if (result != 0)
		cout << "Количество красивых чисел в диапазоне от " << low << " до " << high << " = " << result << endl;
	else
		cout << "Красивых чисел в диапазоне от " << low << " до " << high << " нет" << endl;
	system("pause");
}