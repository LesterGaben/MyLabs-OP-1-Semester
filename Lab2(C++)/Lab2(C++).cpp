#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    double x, y;
    cout << "Введите координату x: ";
    cin >> x;
    cout << "Введите координату y: ";
    cin >> y;
    if (x == 0 && y == 0) cout << "Точка находится в начале координат" << endl;
    else if (x == 0) cout << "Точка находится на оси Y" << endl;
    else if (y == 0) cout << "Точка находится на оси X" << endl;
    else if (x > 0 && y > 0) cout << "Точка находится в первом квадранте" << endl;
    else if (x > 0 && y < 0) cout << "Точка находится в четвертом квадранте" << endl;
    else if (x < 0 && y > 0) cout << "Точка находится во втором квадранте" << endl;
    else cout << "Точка находится в третьем квадранте" << endl;
    system("pause");
    return 0;
}
 