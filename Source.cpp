#include <iostream>
#include <stdio.h>
#include <limits>

//1.A user enters size of square two - dimensional array: n(integer, positive).
//2.Declare a two - dimensional dynamic array of double with size n – number of rows and n – number of columns.
//3.Fill the array with random double numbers between - 5 and 5, inclusive.
//4.Display array values to the screen as a table.
//5.Using the developed algorithm write a code that finds the minimum value(value and position i - row, j - column) 
//	of the values on the secondary diagonal the two - dimensional array.
//6.Display the found values to the screen.

using namespace std;

void findMinOfDiag(double **p2dArr, int row) {
	if (row == 0)
		return;
	double minSecValue = p2dArr[0][row - 1];
	int j = row - 1;
	double index = 0;
	int indexRow = 0;
	int indexCol = 0 + 1;
	for (int i = 0; i < row; i++) {
		if (p2dArr[i][j] < minSecValue) {
			minSecValue = p2dArr[i][j];
			indexRow = i;
			indexCol = j;
		}
		j--;
	}
	cout << "The minimum value of the secondary diagonal is " << minSecValue << endl;
	cout << "The row position of the minimum value is [" << indexRow << "][" << indexCol << "]" << endl;
}
int main(int argc, char** argv) {

	unsigned int row = 0;
	cout << "Enter a size of the square two-dimensional array!" << endl;
	cout << "Size: " << endl;
	cin >> row;

	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			cout << "Enter a size of two-dimensional array: " << endl;
			cin >> row;
		}
		else if (row <= 0) {
			cerr << "The size of the array is wrong! It should be not less or equal zero." << endl;
			cout << "Change the size of the array: ";
			cin >> row;
		}
		else if (!cin.fail())
			break;
	}
	// allocate the array
	double** p2dArr;
	p2dArr = new double*[row];
	for (unsigned int i = 0; i < row; i++) {
		p2dArr[i] = new double[row];
	}
	// getting input from the user
	for (unsigned int i = 0; i < row; i++) {
		for (unsigned int j = 0; j < row; j++) {
			cout << "arr[" << i << "][" << j << "]=";
			cin >> p2dArr[i][j];
		}
	}
	// displaying the array as a table
	cout << "The array you entered is " << endl;
	for (unsigned int i = 0; i < row; i++) {
		for (unsigned int j = 0; j < row; j++) {
			cout << p2dArr[i][j] << " ";
		}
		cout << "\n";
	}

	findMinOfDiag(p2dArr, row);

	for (unsigned int i = 0; i < row; i++)
	{
		delete[] p2dArr[i];
	}
	delete[] p2dArr;

	system("PAUSE");
	return 0;
}