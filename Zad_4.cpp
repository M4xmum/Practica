//Задание №4
#include <iostream>
#include <locale.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	vector <int> s1 = { 1, 2 };
	vector <int> s2 = { 3, 4 };
	int m = 2, n = 2;
	double mediana = 0;
	vector <int> s(n + m);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	merge(s1.begin(), s1.end(), s2.begin(), s2.end(), s.begin());
	for (int i : s)
		cout << i << " ";
	cout << endl;
	int i = 0;
	if (s.size() != 0) {
		if (s.size() % 2 == 0) {
			i = (m + n) / 2;
			mediana = (s[i] + s[i - 1]);
			mediana /= 2;
		}
		else {
			i = (m + n) / 2;
			mediana = s[i];
		}
		cout << "Медиана двух массивов = " << mediana << endl;
	}
	else
		cout << "Списки элементов пусты!" << endl;
	system("pause");
}