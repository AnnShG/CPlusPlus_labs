#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

	double x, f1, f2, f3;
	double expr;

	cout << "Please, enter the x: " << endl;
	cin >> x;

	expr = (pow(x, 2) + 3);

	if ((- 1 < x) < 0) { // here always will be false
		f1 = 1 / (pow((x + 1), 3));
		cout << "The f1(x) is equal to " << f1 << endl;
	}
	else if ((0 <= x) <= 1) {
		f2 = pow(cos(x - 1), 2); // this one will be always true
		cout << "The f2(x) is equal to " << f2 << endl;
	}
	else {
		f3 = log(expr); // this is a natural logarithm
		cout << "The f3(x) is equal to " << f3 << endl;
	}

	system ("PAUSE");
	return 0;
}