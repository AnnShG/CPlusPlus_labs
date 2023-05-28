#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

//1. OK Create an empty integer vector and add to it 10 random integer values in the range[-15; 15]
//2. OK Develop a function to display the content of the vector. Use the index operator to access the items of the vector. 
//3. OK Count and display the number of values in the vector in the range[-5; +5].
//4. OK Remove all negative values from the vector and display the resulting vector to the screen.
//5. OK Sort the vector in descending order using the sort() algorithmand display the resulting vector to the screen.

using namespace std;

vector<int> generateVector(int size);
void printVector(vector<int> v);

//bool predicate(int x) {
//	//return 5 >= x >= -5;
//	//return x == (5, -5);
//}
bool isNegative(int i) {
	return i < 0;
}
int compare(int a, int b) {
	return a > b;
}

int main(int argc, char** argv) {

	//int num;

	vector<int> v(10); // create a vector with 10 elements
	cout << "Size of the vector is " << v.size() << "." << endl;

	vector<int> vec = generateVector(10);
	cout << "Vector is ";
	printVector(vec);
	
	// Sort the vector elements
	cout << endl << "Sorted vector in descending order." << endl;
	sort(vec.begin(), vec.end());
	cout << "Vector is "; 
	printVector(vec);
	cout << endl;

	// count number of values in the vector that are in [-5; +5] range
	vector<int>::iterator itvec;

	auto start = lower_bound(vec.begin(), vec.end(), -5);
	auto end = upper_bound(vec.begin(), vec.end(), 5);
	int count = 0;

	cout << "Numebrs of vector in the range [-5; +5] -> ";
	for (auto itvec = start; itvec != end; itvec++) {
		cout << *itvec << " ";
		count++;
	}
	cout << endl;
	cout << "How many numbers in the range [-5; +5] ? -> " << count << endl;
	//int count = count_if(vec.begin(), vec.end(), predicate);

	// remove all negative elements
	cout << endl << "Remove negative numbers from vector" << endl;
	auto it = remove_if(vec.begin(), vec.end(), isNegative);
	vec.erase(it, vec.end());
	cout << "vec = "; 
	printVector(vec);
}

vector<int> generateVector(int size) { // generate 10 random numbers
	vector<int> v;
	v.reserve(size);

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		//v.push_back(rand() % 15 -15);
		v.push_back(rand() % 30 + -15); // range of -15 till 15
	return v;
}

void printVector(vector<int>v) {

	vector<int>::iterator it; // declare iterator variable

	cout << "{ ";
	for (it = v.begin(); it != v.end(); it++) { // iterate through vector elements with iterator
		cout << *it << " "; // use operator * to access value that correspond to iterator
	}
	cout << " }" << endl;
}