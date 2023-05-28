#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	double a, b;

	cout << "Enter A and B numbers!" << endl;
	cin >> a >> b;
	double product;

	if (a < b) {
		product = 1;
		for (int i = a; i <= b; i++) {
			product *= i;
		}
		cout << "The product of the numbers in the range of A and B is " << product << endl;
	} // (a < b), (a < 0 && b > 0)

	if (a > b) {
		product = 1;
		for (int i = b; i <= a; i++) {
			product *= i;
		}
		cout << "The product of the numbers in the range of A and B is " << product << endl;
	}

	if (a == b) {
		product = 1;
		for (int i = a; i <= b; i++) {
			product *= i;
		}
		cout << "The product of the numbers in the range of A and B is " << product << endl;
	}

	system("PAUSE");
	return 0;
}