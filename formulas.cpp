#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

	double b, z1, z2;

	cout << "Enter the input number: ";
	cin >> b;

	z1 = (sqrt(2 * b + 2 * sqrt(pow(b, 2) - 4))) / (sqrt(pow(b, 2) - 4) + b + 2);
	z2 = 1 / (sqrt(b + 2));

	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;

	system("PAUSE");
	return 0;
}