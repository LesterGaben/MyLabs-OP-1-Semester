#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n, b, m;
	cout << "Введите натуральное число: ";
	cin >> n;
	b = n;
	cout << "Натуральные числа, которые меньше введённого числа и взаимно простые с ним: " << endl;
	for (int i = 1; i < n; i++) {
		m = i;
		while (m != 0 && b != 0) {
			if (m > b) {
				m = m % b;
			}
			else {
				b = b % m;
			}
		}
		if ((b + m) == 1) {
			cout << i << endl;
		}
		b = n;
	}
	system("pause");
	return 0;
}