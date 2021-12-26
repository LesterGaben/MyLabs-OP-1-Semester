#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int num_of_words(string line, int num);
string delete_words_ending_in_symbols(string line, string symbols, int num, int*);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string line, symbols;
    int num = 0, num_of_delete = 0;
    cout << "Введіть слова: ";
    getline(cin, line);
    cout << "Введіть групу символів: ";
    getline(cin, symbols);

    num = num_of_words(line, num);
    cout << "Кількість слів в рядку: " << num << endl;
    line = delete_words_ending_in_symbols(line, symbols, num, &num_of_delete);

    cout << endl << "Рядок після всіх можливих змін: " << line << endl;
    cout << "Кількість видалень слів: " << num_of_delete << endl;

    system("pause");
    return 0;
}

int num_of_words(string line, int num) {
    int x = 0, pre_x;
    while (x > -1) {
        pre_x = x;
        x = line.find(" ", pre_x + 1);
        if (x > 0 && x > pre_x) {
            num++;
        }
    }
    ++num;
    return num;
}

string delete_words_ending_in_symbols(string line, string symbols, int num, int* num_of_delete) {
    string temp;
    int i_of_space_1 = 0, i_of_space_2 = 0, leng_of_temp, leng_of_symbols;
    leng_of_symbols = symbols.length();
    for (int i = 0; i < num; i++) {

        i_of_space_1 = line.find(" ", i_of_space_1);
        i_of_space_2 = line.find(" ", i_of_space_1 + 1);

        temp = line.substr(i_of_space_1 + 1, i_of_space_2 - i_of_space_1 - 1);
        leng_of_temp = temp.length();

        if (i_of_space_1 == -1 && i_of_space_2 == -1) {
            temp = temp.substr(leng_of_temp - leng_of_symbols, leng_of_temp);
            if (temp == symbols) {
                line = line.erase(0, leng_of_temp);
                *num_of_delete += 1;
            }
        }
        else if (leng_of_temp > leng_of_symbols) {
            temp = temp.substr(leng_of_temp - leng_of_symbols, leng_of_temp - 1);
            if (temp == symbols) {
                if (i_of_space_1 == -1) i_of_space_1 = 0;
                line = line.erase(i_of_space_1, leng_of_temp + 1);
                *num_of_delete += 1;
            }
            else i_of_space_1 = i_of_space_2;
        }
        else if (leng_of_temp == leng_of_symbols) {
            temp = temp.substr(leng_of_temp - leng_of_symbols, leng_of_temp);
            if (temp == symbols) {
                if (i_of_space_1 == -1) i_of_space_1 = 0;
                line = line.erase(i_of_space_1, leng_of_temp + 1);
                i_of_space_1 = i_of_space_2;
                *num_of_delete += 1;
            }
            else i_of_space_1 = i_of_space_2;
        }
        else i_of_space_1 = i_of_space_2;

    }
    return line;
}