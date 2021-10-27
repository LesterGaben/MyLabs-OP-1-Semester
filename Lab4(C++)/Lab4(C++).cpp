#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    double Tc, Tf;
    int n;
    cout << "Введите n: ";
    cin >> n;
    cout << endl;
    printf("|%19s %8s|\n", "Температура", "");
    printf("|По Цельсию|   |По Фаренгейту| \n");
    for (Tc = 0; Tc <= n; Tc++) {
        Tf = (9. / 5) * Tc + 32;
        printf("|%7.2f   |   |%9.2f    | \n", Tc, Tf);
    }
    system("pause");
    return 0;
}