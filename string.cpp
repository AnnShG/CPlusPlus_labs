#include <iostream>
#include <string>

//Write an application that
//	*takes an array of strings from the user,
//	*deletes all punctuation symbols from the string and 
//	*displays strings on the screen.

using namespace std;

string RemoveStringPuncts(const string& input) {
	string temp(input);
	temp.erase(remove_if(temp.begin(), temp.end(), ispunct), temp.end());
	
	return temp;
}

int main(int argc, char** argv) {
	string input;
	cout << "Enter the string, please ";
	getline(cin, input);

	string correctedString = RemoveStringPuncts(input);
	cout << "The string without punctuations symbols " << correctedString << endl;

	system("PAUSE");
	return 0;
}