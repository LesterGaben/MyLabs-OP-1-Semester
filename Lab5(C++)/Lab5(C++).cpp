#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n, N, m;
	cout << "Введите натуральное число: ";
	cin >> n;
	N = n;
	cout << "Натуральные числа, которые меньше введённого числа и взаимно простые с ним: " << endl;
	for (int i = 1; i < n; i++) {
		m = i;
		while (m != 0 && N != 0) {
			if (m > N) {
				m = m % N;
			}
			else {
				N = N % m;
			}
		}
		if ((N + m) == 1) {
			cout << i << endl;
		}
		N = n;
	}
	system("pause");
	return 0;
}