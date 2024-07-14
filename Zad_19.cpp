// Задача № 19
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

using namespace std;
struct Node {
	int value = 0;
	Node* next = NULL;
};
int main() {
	setlocale(LC_ALL, "RUS");
	int k = 0;
	Node* last = NULL;
	Node* t = NULL;
	Node* head = NULL;
	cout << "Введите количество узлов: ";
	cin >> k;
	for (int i = 0; i < k; i++) {
		if (last == NULL) {
			last = new Node;
			last->value = 0;
			last->next = NULL;
			head = last;
		}
		else {
			t = new Node;
			t->value = i;
			last->next = t;
			last = last->next;
		}
	}
	cout << "Изначальный список: " << endl;
	t = head;
	do {
		if (t != NULL) {
			cout << t->value << ((t->next != NULL) ? " -> " : " ");
			t = t->next;
		}
	} while (t != NULL);
	int n = 0, n1 = 0;
	Node* p = NULL;
	t = head;
	cout << endl << "Введите номер элемента, который нужно удалить с конца списка: ";
	cin >> n;
	if (n > 0 && n <= k) {
		for (int i = 0; i < k; i++) {
			if (n1 == k - n) {
				if (n1 == 0) {
					p = t->next;
					delete t;
					head = p;
					break;
				}
				if (n1 == k - 1) {
					p->next = NULL;
					delete t;
					break;
				}
				p->next = t->next;
				delete t;
				break;
			}
			p = t;
			t = t->next;
			n1++;
		}
	}
	k--;
	cout << "Измененный список: " << endl;
	t = head;
	do {
		if (t != NULL) {
			cout << t->value << ((t->next != NULL) ? " -> " : " ");
			t = t->next;
		}
	} while (t != NULL);
	t = head;
	do {
		if (t != NULL) {
			p = t->next;
			delete t;
			t = p;
		}
	} while (t != NULL);
	char c = 0;
	c = _getch();
}