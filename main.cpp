#include <iostream>
#include <string>

using namespace std;

/*The user enters a string(possibly with spaces).
	Remove all extra spaces from the string
		*at the beginning of the string,
		*at the end of the string, and
		*if there is more than one space between words).
	Display the resulting string to the screen*/

int main(int argc, char** argv) {
	string input;
	string string;

	cout << "Enter a string, please ";
	getline(cin, input);

	// loop through all the chars of the input
	for (int i = 0; i < input.length(); ) {
		// check if a char is a white space
		if (input[i] == ' ') {
			if (i == 0 || i == input.length() - 1) { // beginning and end
				i++;
				continue;
			}
			while (input[i + 1] == ' ') {
				i++;
			}
		}
		// to concetenate input to the string
		string += input[i++];
	}

	cout << "This is a new string: " << string << endl;

	system("PAUSE");
	return 0;
}