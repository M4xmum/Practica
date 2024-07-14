#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest_altitude = 0;
        int altitude = 0;
        for (int i = 0; i < gain.size(); i++) {
            altitude += gain[i];
            if (altitude > highest_altitude) {
                highest_altitude = altitude;
            }
        }
        return highest_altitude;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Solution solution;
    vector<int> gain;
    string input;
    char choice;

    do {
        gain.clear();

        cout << "Введите значения прироста высоты (через пробел):";
        getline(cin, input);
        stringstream s(input);

        int num;
        while (s >> num) {
            if (num >= -100 && num <= 100) { 
                gain.push_back(num);
            }
            else {
                cout << "Значений не соответствуют ограничению (-100 <= gain[i] <= 100)." << endl;
                break;
            }gain.push_back(num);
        }

        cout << "Наибольшая высота над уровнем моря: " << solution.largestAltitude(gain) << endl;

        cout << "Хотите попробовать другой прирост высоты? (1 - да / 0 - нет): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == '1');

    return 0;
}