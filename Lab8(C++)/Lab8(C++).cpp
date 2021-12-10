#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void matrix_generation(int**, int n);
void filling_the_matrix_A(int**, int n);
void output_matrix(int**, int n);
void find_central_element(int**, int n);  // Функція для знаходження значення матриці на перетині головної та побічної діагоналі(тобто центрального)
void filling_the_matrix_B(int**, int**, int n);
void delete_matrix(int**, int n);


int main() {
	int n;
	cout << "Input matrix size: ";
	cin >> n;
	cout << endl;
	int** A = new int* [n];
	matrix_generation(A, n);
	filling_the_matrix_A(A, n);
	cout << "Matrix A:" << endl;
	output_matrix(A, n);
	find_central_element(A, n);
	int** B = new int* [n];
	matrix_generation(B, n);
	filling_the_matrix_B(A, B, n);
	cout << "Matrix B:" << endl;
	output_matrix(B, n);
	delete_matrix(A, n);
	delete_matrix(B, n);
	system("pause");
	return 0;
}


void matrix_generation(int* array[], int n) {
	for (int i = 0; i < n; i++) {
		array[i] = new int[n];
	}
}


void filling_the_matrix_A(int* array[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = rand() % 100 + 1;
		}
	}
}


void output_matrix(int* array[], int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}


void find_central_element(int* array[], int n) {
	if (n % 2 != 0) {
		cout << "Central element: " << array[n / 2][n / 2] << endl;
	}
	else cout << "No central element" << endl;
	cout << endl;
}


void filling_the_matrix_B(int* A[], int* B[], int n) {
	int x, k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k = 0;
			B[i][j] = A[i][j];
			if (n > 2) {
				while (k < i && k < (n - 1 - i)) {
					x = A[i][k];
					B[i][k] = A[i][n - 1 - k];
					B[i][n - 1 - k] = x;
					k++;
				}
			}
		}
	}
}


void delete_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}