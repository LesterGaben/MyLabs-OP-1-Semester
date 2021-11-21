#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

double integral_arctg(double a, double b, double n);
double integral_sin(double a, double b, double n);

int main() {
	setlocale(LC_ALL, "rus");
	double a, b, n, sum; 
	cout << "Введите целое число a: ";
	cin >> a;
	cout << "Введите целое число b: ";
	cin >> b;
	cout << "Введите целое число, большее или равное 1: ";
	cin >> n;
	while (n < 1) {
		cout << "Введите целое число, большее или равное 1: ";
		cin >> n;
	}
	sum = integral_arctg(a, b, n) + integral_sin(0, M_PI, n);
	cout << "Приблизительная сумма интегралов: " << sum << endl;
	system("pause");
	return 0;
}

double integral_arctg(double a, double b, double n) {
	double h = (b - a) / n;
	double arctg = 0;
	for (int i = 1; i <= (n - 1); i++) {
		arctg += pow(atan(a + i * h), 2);
	}
	int arctg_1;
	arctg_1 = (pow(atan(a), 2) + pow(atan(b), 2)) / 2 + arctg;
	double arctg_2 = arctg_1 * h;
	return arctg_2;
}

double integral_sin(double a, double b, double n) {
	double h = (b - a) / n;
	double sinus = 0;
	for (int i = 1; i <= (n - 1); i++) {
		sinus += sin(pow(M_E, (10 * (a + i * h))));
	}
	int sinus_1;
	sinus_1 = (sin(pow(M_E, (10 * a))) + sin(pow(M_E, (10 * b)))) / 2 + sinus;
	double sinus_2 = sinus_1 * h;
	return sinus_2;
}