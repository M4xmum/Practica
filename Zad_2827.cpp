//������� �2827
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
		cout << "������� ������� �������� (�� < 1 � �� > 10^9)" << endl << "��: ";
		cin >> low;
		cout << "��: ";
		cin >> high;
		if (low > 0 && high <= pow(10, 9))
			break;
		else
			cout << "�������� ����! ��������� ��� ���!" << endl;
	}

	while (1) {
		cout << "������� �����, �� ������� ������ �������� �������� ����� (�� 1 �� 20): ";
		cin >> k;
		if (k > 0 && k <= 20)
			break;
		else
			cout << "�������� ����! ��������� ��� ���!" << endl;
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
		cout << "���������� �������� ����� � ��������� �� " << low << " �� " << high << " = " << result << endl;
	else
		cout << "�������� ����� � ��������� �� " << low << " �� " << high << " ���" << endl;
	system("pause");
}