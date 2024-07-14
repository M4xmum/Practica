#include <iostream>
#include <vector>
#include <string>

#include <sstream> 

using namespace std;

bool char_row(char symbol, const char* keyboard_row) {
    for (int i = 0; keyboard_row[i] != '\0'; ++i) {
        if (keyboard_row[i] == symbol) {
            return true;
        }
    }
    return false;
}

bool from_one_row(const string& word, const char* keyboard_row_1, const char* keyboard_row_2, const char* keyboard_row_3) {
    if (char_row(tolower(word[0]), keyboard_row_1)) {
        for (char symbol : word) {
            if (!char_row(tolower(symbol), keyboard_row_1)) {
                return false;
            }
        }
        return true; // Все символы на первой строке
    }

    else if (char_row(tolower(word[0]), keyboard_row_2)) {
        for (char symbol : word) {
            if (!char_row(tolower(symbol), keyboard_row_2)) {
                return false;
            }
        }
        return true; // Все символы на второй строке
    }

    else if (char_row(tolower(word[0]), keyboard_row_3)) {
        for (char symbol : word) {
            if (!char_row(tolower(symbol), keyboard_row_3)) {
                return false;
            }
        }
        return true; // Все символы на третьей строке
    }

    else {
        return false; // Первый символ не найден ни на одной из строк
    }
}bool char_row(char symbol, const char* keyboard_row) {
    for (int i = 0; keyboard_row[i] != '\0'; ++i) {
        if (keyboard_row[i] == symbol) {
            return true;
        }
    }
    return false;
}

bool from_one_row(const string& word, const char* keyboard_row_1, const char* keyboard_row_2, const char* keyboard_row_3) {
    if (char_row(tolower(word[0]), keyboard_row_1)) {
        for (char symbol : word) {
            if (!char_row(tolower(symbol), keyboard_row_1)) {
                return false;
            }
        }
        return true;
    }

    else if (char_row(tolower(word[0]), keyboard_row_2)) {
        for (char symbol : word) {
            if (!char_row(tolower(symbol), keyboard_row_2)) {
                return false;
            }
        }
        return true;
    }

    else if (char_row(tolower(word[0]), keyboard_row_3)) {
        for (char symbol : word) {
            if (!char_row(tolower(symbol), keyboard_row_3)) {
                return false;
            }
        }
        return true;
    }

    else {
        return false;
    }
}

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        const char* keyboard_row_1 = "qwertyuiop";
        const char* keyboard_row_2 = "asdfghjkl";
        const char* keyboard_row_3 = "zxcvbnm";

        vector<string> words_OneRow;
        for (const string& word : words) {
            if (from_one_row(word, keyboard_row_1, keyboard_row_2, keyboard_row_3)) {
                words_OneRow.push_back(word);
            }
        }
        return words_OneRow;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Solution solution;
    vector<string> words;
    string input;

    char choice;
    do {   
    cout << "Введите слова, разделенные пробелами (используя английский алфавит): ";
    getline(cin, input);

    stringstream s(input);
    string word;
    while (getline(s, word, ' ')) {
        words.push_back(word);
    }

    vector<string> result = solution.findWords(words);

    cout << "Из введённых слов, с одной строки клавиатуры можно ввести:: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Хотите попробовать другие слова? (1 - да / 0 - нет): ";
    cin >> choice;
    } while (choice == '1');

    return 0;
}