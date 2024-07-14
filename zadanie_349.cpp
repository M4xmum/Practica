#include <vector>
#include <iostream>
#include <set>

using namespace std;
int main() {
	vector<int> nums1 = { 4, 9, 5 };
	vector <int> nums2 = { 9,4,9,8,4 };
	set<int> result;
	for (int i : nums1) {
		for (int j : nums2) {
			if (i == j)
				result.insert(i);
		}
	}
	for (int i : result)
		cout << i << " ";
	cout << endl;
	system("pause");
}