#include <iostream>
#include <algorithm>

using namespace std;
/*
* 1. Creating and outputting an array of random numbers consisting of n integers to
		the screen elements (n – set number).
2. Sorting the initial array with the two methods given in table P1:
		3. Bingo sort and 7. Two way insertion sort

Note: Sorting elements in each of the methods is accompanied by sorting time or
		calculating the number of comparison operations that have been executed by the
		program (characterization is chosen by the developer).

II. Execute the developed program for different values of n in the range 100 to 1000.
*/

void print_array(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int bingo_sort(int array[], int n) {
	int comparisons = 0;
	for (int i = 0; i < n - 1; ++i) {
		int min_index = i;
		for (int j = i + 1; j < n; ++j) {
			comparisons++;
			if (array[j] < array[min_index]) {
				min_index = j; // we foind the min value, it is j now
			}
		}
		if (min_index != i) { // if min_index and current index are different, so the min_value is in incorrect position
			int min_value = array[min_index];
			for (int j = i; j < n; ++j) {
				comparisons++;
				if (array[j] == min_value) { // checks if the element at index j in the array is equal to the min_value
					swap(array[j], array[i]);
					++i;
				}
			}
			--i;
		}
		
	}

return comparisons;
}

int two_way_insertion_sort(int array[], int n) {
	int comparisons = 0;
	for (int i = 1; i < n; i++) { // iterates from the second element to the last element of the array
		int j = i;
		int temp = array[i]; // store the current element at index i in the variable temp

		// Leftward search and insertion
		while (j > 0 && ++comparisons && array[j - 1] > temp) { // compares the element temp with the elements on its left (towards smaller indices)
			array[j] = array[j - 1]; // shifts them to the right if they are greater than temp
			j--;
		}
		array[j] = temp; // the element temp is inserted into its correct position at index j

		// Rightward search and insertion
		j = i;
		temp = array[n - i - 1];
		while (j < n - 1 && ++comparisons && array[n - j] < temp) { // compares the element temp with the elements on its right (towards greater indices) 
			array[n - j - 1] = array[n - j]; // shifts them to the left if they are smaller than temp
			j++;
		} // j = n - 1 is the end of the unsorted array
		array[n - j - 1] = temp;
	}

	return comparisons;

}

int main(int argc, char** argv) {
	int n;


	cout << "Enter a size of the array ";
	cin >> n;
	cout << endl;

	int* array;
	array = new int[n];

	cout << "Here is the original array with 10 random numbers from 100 to 1000:\n";

	//srand(time(0));

	for (int i = 0; i < n; i++) {
		array[i] = 100 + rand() % 901;
		cout << array[i] << " ";
	}

	cout << endl << endl;

	cout << "Bingo sorted array:\n";

	int bingoComparisons = bingo_sort(array, n);
	print_array(array, n);
	cout << "Number of comparisons: " << bingoComparisons << endl << endl;

	cout << "The Two - way insertion sorted array:\n";

	int twoWayInsertionComparisons = two_way_insertion_sort(array, n);
	print_array(array, n);
	cout << "Number of comparisons: " << twoWayInsertionComparisons << endl << endl;

	delete[] array;
}