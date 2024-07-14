//Задание №60
#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	string s = "", str = "";
	int k1 = 1, k = 0, n = 0, nf = 1;
	while (1) {
		cout << "Введите значение n (количество элементов для перестановки n!(1 <= n <= 9)): ";
		cin >> n;
		if (n >= 1 && n <= 9)
			break;
		else
			cout << "Игнорированы ограничения! Повторите ещё раз!" << endl;
	}
	for (int i = 1; i < n + 1; i++) {
		str = to_string(i);
		s.append(str);
		nf *= i;
	}
	while (1) {
		cout << "Введите значение k (номер перестановки(1 <= k <= n!)): ";
		cin >> k;
		if (k >= 1 && k <= nf)
			break;
		else
			cout << "Несуществующий номер перестановки! Повторите ещё раз!" << endl;
	}
	do {
		if (k1 == k) {
			cout << s << endl;
			break;
		}
		k1++;
	} while (next_permutation(s.begin(), s.end()));
	system("pause");
}