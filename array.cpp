#include <iostream>
#include <stdio.h>
#include <limits>

//1) a user enters size of array: n(integer, positive).
//2) declare an one - dimensional dynamic array of 
//   integers of size n.
//3) implement filling the array by the user.
//4) display array values to the screen.
//5) calculate the sum of the positive elements of the
//	array located between the minimum and
//	maximum elements(use the developed
//	algorithm in the first task).
//6) display the calculated sum to the screen
// 
// + add the validation, if the user enters a letter for the array size.
// + to sort the elements

using namespace std;

// functions to find a sum
int getMin(int array[], int n) {
	int min = 0;

	for (int i = 0; i < n; ++i) {
		if (array[min] > array[i]) {
			min = i;
		}
	}
	return min;
}

int getMax(int array[], int n) {
	int max = 0;

	for (int i = 0; i < n; ++i) {
		if (array[max] < array[i]) {
			max = i;
		}
	}
	return max;
}

int findSum(int array[], int n) {
	int min = getMin(array, n);
	int max = getMax(array, n);
	int sum = 0;

	if (min < max) {
		for (int i = min + 1; i < max; ++i) {
			sum += array[i];
		}
	}
	else if (min > max) {
		for (int i = max + 1; i < min; ++i) {
			sum += array[i];

		}
	}
	return sum;
}

//int res = array[0];
//for (int i = 1; i < n; i++) {
//		res = min(res, array[i]);
//	}

int main(int argc, char** argv) {
	const int maxSize = 10;
	int n;

	cout << "The size should be: 0 < size <= 10." << endl << "Enter size of the array:  ";
	cin >> n;

	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input!" << endl;
			cout << "Enter size of the array:  ";
			cin >> n;
		}
		else if (n > maxSize) {
			cerr << "the size of the array is too large! Check it out!" << endl;
			cout << "Change the size of the array: ";
			cin >> n;
		}
		else if (n <= 0) {
			cerr << "the size of the array is too  small! Check it out!" << endl;
			cout << "Change the size of the array: ";
			cin >> n;
		}
		else if (!cin.fail())
			break;
	}

	// returns a pointer to the first element of the sequence
	int * array;
	array = new int [n]; // allocate memory for our array
	cout << "Size is " << n << endl;
	cout << endl;

	cout << "Enter " << n << " numbers, please!" << endl;
	for (int num = 0; num < n; num++) { //(sizeof(array) / sizeof(array[i]))
		cout << "Enter a number: ";
		cin >> array[num]; // looping till you enter all the required numbers
	}

	cout << endl;
	cout << endl;

	cout << "The array is: ";
	for (int num = 0; num < n; num++) { // shows all the numbers of the array
		cout << array[num] << " ";
	}
	cout << endl;

	// to sort the elementts of the arraay
	int j, temp;

	for (int i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) { // j = i + 1 -> j is the next element after i

			if (array[j] < array[i]) {
				temp = array[j]; // storing that smaller j in temp
				array[j] = array[i]; // swapping: overwrite i with j
				array[i] = temp; // and putting j on i place
			}
		}
	}

	cout << "Sorted array is: ";
	for (int sortNum = 0; sortNum < n; sortNum++) {
		cout << array[sortNum] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "The sum of numbers between max and min is: " << findSum(array, n) << endl;
	
	delete[] array;

	return 0;
}