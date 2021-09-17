#include <iostream>
#define PI 3.141592
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukr");
    double d, square;
    cout << "Довжина кола: ";
    cin >> d;
    square = PI * pow((d / (2 * PI)), 2);
    cout << "Площа кола: " << square;
    return 0;
}