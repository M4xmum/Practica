//Задание №315
#include <iostream>
#include <locale.h>
#include <vector>

using namespace std;


int main() {
	setlocale(LC_ALL, "Rus");
	vector <int> nums = { 5,-4,3,7,8,10,15,1,-3 };//массив целых чисел, который надо пройти
	vector <int> counts;
	int c = 0;
	for (auto it1 = nums.begin(); it1 != nums.end();it1++) {
		for (auto it2 = it1 + 1; it2 != nums.end();it2++) {
			if (*it1 > *it2)
				c++;
		}
		counts.push_back(c);
		c = 0;
	}
	for (int i : counts)
		cout << i << " ";
	cout << endl;
	system("pause");
}