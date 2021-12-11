#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void filling_arrays_A_and_C(int*, int*, int n);
void creating_array_D(int*, int*, int*, int n);
void output_arrays(int*, int n);
void find_min_and_last_element_in_array_D(int*, int n, int*, int*);
void changes_to_array_D(int*, int n, int*, int*);

int main() {
	setlocale(LC_ALL, "rus");
	int *A = NULL, *C = NULL, *D = NULL;
	int n, min_in_D, num_min_in_D;
	cout << "Введите желаемое количество элементов в массивах: ";
	cin >> n ;
	cout << endl;
	A = new int[n];
	C = new int[n];
	D = new int[n];
	filling_arrays_A_and_C(A, C, n);
	creating_array_D(A, C, D, n);
	cout << "Массив A:";
	output_arrays(A, n);
	cout << "Массив C:";
	output_arrays(C, n);
	cout << "Массив D:";
	output_arrays(D, n);
	cout << endl;
	find_min_and_last_element_in_array_D(D, n, &min_in_D, &num_min_in_D);
	cout << "Минимальный элемент в массиве D: " << min_in_D << endl;
	cout << "Номер минимального элемента в массиве D: " << num_min_in_D + 1 << endl;
	cout << "Последний элемент в массиве D: " << D[n - 1] << endl << endl;
	changes_to_array_D(D, n, &min_in_D, &num_min_in_D);
	cout << "Массив D после изменений:";
	output_arrays(D, n);
	delete[] A;
	delete[] C;
	delete[] D;
	system("pause");
	return 0;
}

void filling_arrays_A_and_C(int A[], int C[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 99 + 1;
		C[i] = rand() % 99 + 1;
	}
}

void creating_array_D(int A[], int C[], int D[], int n) {
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
	}
}

void output_arrays(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(3) << x[i];
	}
	cout << endl;
}

void find_min_and_last_element_in_array_D(int D[], int n, int* min_in_D, int* num_min_in_D) {
	*min_in_D = 100;
	for (int i = 0; i < n; i++) {
		if (*min_in_D > D[i]) {
			*min_in_D = D[i];
			*num_min_in_D = i;
		}
	}
}

void changes_to_array_D(int D[], int n, int* min_in_D, int* num_min_in_D) {
	D[*num_min_in_D] = D[n - 1];
	D[n - 1] = *min_in_D;
}