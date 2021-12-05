#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void input_arrays(int*, int*, int n);
void creating_array_D(int*, int*, int*, int n);

int main() {
	setlocale(LC_ALL, "rus");
	int *A = NULL, *C = NULL, *D = NULL;
	int n;
	cout << "Введите желаемое количество элементов в массивах: ";
	cin >> n ;
	cout << endl;
	A = new int[n];
	C = new int[n];
	D = new int[n];
	input_arrays(A, C, n);
	creating_array_D(A, C, D, n);
	delete[] A;
	delete[] C;
	delete[] D;
	system("pause");
	return 0;
}

void input_arrays(int A[], int C[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 99 + 1;
		C[i] = rand() % 99 + 1;
	}
	cout << "Массив A: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Массив C: ";
	for (int i = 0; i < n; i++) {
		cout << C[i] << " ";
	}
	cout << endl << endl;
}

void creating_array_D(int A[], int C[], int D[], int n) {
	int min = 100, i_of_min = 0, end_D;
	cout << "Массив D до изменений: ";
	for (int i = 0; i < n; i++) {
		if (A[i] > C[i]) {
			D[i] = A[i];
		}
		else if (C[i] > A[i]) {
			D[i] = C[i];
		}
		else {
			D[i] = 0;
		}
		cout << D[i] << " ";
		if (min > D[i]) {
			min = D[i];
			i_of_min = i;
		}
	}
	cout << endl;
	end_D = D[n - 1];
	D[n - 1] = min;
	D[i_of_min] = end_D;
	cout << "Последний элемент массива D: " << end_D << endl;
	cout << "Минимальный элемент массива D: " << min << endl;
	cout << "Номер размещения минимального элемента массива D: " << i_of_min + 1 << endl << endl;
	cout << "Массив D после изменений: ";
	for (int i = 0; i < n; i++) {
		cout << D[i] << " ";
	}
	cout << endl;
}