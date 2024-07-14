// Задача № 3
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	string str, str1, str2;
	int max = 0, n = 0;
	cout << "Введите строку: ";
	getline(cin, str);
	for (auto it = str.begin(); it != str.end(); it++) {
		if (str2.find(*it) != -1) {
			str2.clear();
			max = max < n ? n : max;
			n = 0;
			str1 = *it;
			str2.append(str1);
			n++;
		}
		else {
			str1 = *it;
			str2.append(str1);
			n++;
		}
	}
	max = max < n ? n : max;
	cout << "Длина максимальной подстроки = " << max;
	char c = 0;
	c = _getch();
}