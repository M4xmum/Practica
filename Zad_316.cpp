//Задание №316
#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	string str = "", str1;
public:
	string removeDuplicateLetters(string s) {
		for (auto it = s.begin(); it != s.end(); it++) {
			if (str.find(*it) == -1) {
				str1 = *it;
				str.append(str1);
			}
		}
		sort(str.begin(), str.end());
		return str;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");
	string s = "bcabc";
	Solution r;
	cout << r.removeDuplicateLetters(s) << endl;

	system("pause");
}