#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	double  x, ε, PreSin, sin, f, fact = 1, i = 0;
	cout << "Введите значение аргумента синуса: ";
	cin >> x;
	cout << "Введите точность вычисления: ";
	cin >> ε;
	sin = x;
	do {
		i = i + 1;
		f = 2 * i + 1;
		while (f != 1) {
			fact = fact * f;
			f = f - 1;
		}
		PreSin = sin;
		sin = sin + ((pow(-1, i) * pow(x, 2 * i + 1)) / fact);
		fact = 1;
	} while (abs(sin - PreSin) > ε);
	cout << sin << endl;
	system("pause");
	return 0;
}