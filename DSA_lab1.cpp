/*
*  1. Creating and outputting to the screen an array of random numbers consisting of
		n integers elements (n – set number).
	2. Searching the unsorted starting array for the given key
	The key value is entered in dialog mode or generated with a random number generator.
		A sequential search method with a barrier.

	3. students with journal numbers from 16 to 30 need to place a starting array
		elements in the new array using the hash method and execute in it assigned
		key search by calculating the address.
*/

#include <iostream>
#include <cstdlib>
//#include <ctime>
#include <algorithm>

using namespace std;

// Function to generate an array of random integers
void generate_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 1000;
	}
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	cout << endl << endl;
}

// Function to perform a sequential search with a barrier in an unsorted array
int sequential_search_with_barrier(int arr[], int n, int key, int& comparisons) {
	int last = arr[n - 1]; // saves the last element of the array(arr[n - 1]) in the variable last
	arr[n - 1] = key; //  replaces the last element of the array with the key (barrier)

	int i = 0;
	while (arr[i] != key) { // iterates through the elements of the array until it finds the key
		comparisons++;
		i++;
	}

	arr[n - 1] = last; // restores the last element of the array (arr[n - 1]) to its original value
	return (i < n - 1 || last == key) ? i : -1; // it returns the index of the found key
}
// Function to perform a key search in a sorted array using a hash table
int hash_search(int arr[], int n, int key, int hashSize, int& comparisons) {
	//const int hashSize = 100;
	int* hashTable = new int[hashSize]; // allocate memory for hash table
	for (int i = 0; i < hashSize; i++) {
		hashTable[i] = -1; // initialize hash table to -1
	}

	// Build hash table
	for (int i = 0; i < n; i++) {
		int hash = arr[i] % hashSize;
		while (hashTable[hash] != -1 && arr[hashTable[hash]] != arr[i]) {
			hash = (hash + 1) % hashSize;
			comparisons++;
		}
		hashTable[hash] = i;
	}

	// Search for key in hash table
	int hash = key % hashSize;
	while (hashTable[hash] != -1 && arr[hashTable[hash]] != key) {
		hash = (hash + 1) % hashSize;
		comparisons++;
	}

	// Check if key was found
	if (hashTable[hash] == -1) {
		return -1;
	}

	int index = hashTable[hash];
	delete[] hashTable;
	return index;
}

int main() {
	//srand(time(nullptr)); // seed random number generator with current time
	srand(12345); // seed random number generator with fixed value
	int n;
	int hashSize;
	cout << "Enter size of the array? ";
	cin >> n;
	cout << "Enter size of the hash table? ";
	cin >> hashSize;
	//const int n = 100;  // specify array size
	int* arr = new int[n];
	generate_array(arr, n);

	cout << "Array of size " << n << ":\n\n";
	print_array(arr, n);

	int key = rand() % 1000; // generate random key
	int comparisons1 = 0;
	int index1 = sequential_search_with_barrier(arr, n, key, comparisons1);
	cout << "Sequential search with barrier: key = " << key << ", index = ";
	if (index1 == -1) {
		cout << "not found";
	}
	else {
		cout << index1;
	}
	cout << ", comparisons = " << comparisons1 << endl << endl;

	sort(arr, arr + n);
	int comparisons2 = 0;
	int index2 = hash_search(arr, n, key, hashSize, comparisons2);
	cout << "Hash search in sorted array: key = " << key << ", index = ";
	if (index2 == -1) {
		cout << "not found";
	}
	else {
		cout << index2;
	}
	cout << ", comparisons = " << comparisons2 << endl;

	delete[] arr;

	return 0;
}