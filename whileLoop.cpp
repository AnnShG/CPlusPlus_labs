#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(int argc, char** argv) {
	int number;
	string numberString;

	cout << "Enter a positive number: " << endl;
	cin >> number;

	// to check if the input is valid
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input" << endl;
			cin >> number;
		}
		if (!cin.fail())
			break;
	}
	cout << "The number is: " << number << endl;
	
	// convert number to String
	numberString = to_string(number);

	// calculate string length 
	int stringLength = numberString.length();
	cout << "The string/number length is " << stringLength << endl;

	int index = 0;
	int numberOfZeroSymbols = 0;
	int numberOfNineSymbols = 0;

	string zeroString = "0";
	string nineString = "9";

	while (index < stringLength) {
		// examine first symbol in the string
		string symbol = numberString.substr(index, 1);

		// compare characters in the string
		if (zeroString == symbol) {
			numberOfZeroSymbols += 1;
		}
		else if (nineString == symbol) {
			numberOfNineSymbols += 1;
		}

		index += 1;
		// 9 + 1 = 10
		// 10 + 1 = 11
	}

	// output
	if (numberOfZeroSymbols == numberOfNineSymbols && numberOfZeroSymbols > 0 && numberOfNineSymbols > 0) {
		cout << "Equal" << endl;
	}
	else if (numberOfZeroSymbols > numberOfNineSymbols) {
		cout << "0" << endl;
	}
	else if (numberOfNineSymbols > numberOfZeroSymbols) {
		cout << "9" << endl;

		//cout << "0 - " << zeroSymbols << endl;
		//cout << "9 - " << nineSymbols << endl;
	}

	system("PAUSE");
	return 0;
}
