#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <limits> 

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int char_mass[26] = { 0 };
        for (char symbol: words[0]) {
            char_mass[symbol - 'a']++;
        }

        for (int i = 1; i < words.size(); ++i) {
            int char_temp[26] = { 0 }; // Временный массив для подсчета символов в текущем слове
            for (char symbol: words[i]) {
                char_temp[symbol - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (char_temp[j] > 0) {
                    char_temp[j] = min(char_mass[j], char_temp[j]);
                }
                else {
                    char_mass[j] = 0;
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < char_mass[i]; ++j) {
                result.push_back(string(1, 'a' + i));
            }
        }
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Solution solution;
    string input;
    vector<string> words;
    char choice;
    do {
    words.clear();

    cout << "Введите слова, разделенные пробелами (используя английский алфавит): ";
    getline(cin, input);

    stringstream s(input);
    string word;
    while (getline(s, word, ' ')) {
        words.push_back(word);
    }

    vector<string> result = solution.commonChars(words);
    cout << "Общие символы: ";
    for (string& symbol : result) {
        cout << symbol << " ";
    }
    cout << endl;
    cout << "Хотите попробовать другие слова? (1 - да / 0 - нет): ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /

    } while (choice == '1');

    return 0;
}



