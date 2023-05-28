#include <iostream>
//#include "header.h"

//Service id, name, price. 
//
//Use the entered service id to
//determine its name and price

using namespace std;

int n;

enum menu {
	Add = 1,
	Show,
	Exit
};

struct service {
	char id[10];
	char name[20];
	int price;
};

int displayMenu() {
	int choice;
	cout << Add << ". Add a new service\n"
		<< Show << ". Show all the services\n"
		<< Exit << ". Exit\n\n";
	cout << "Enter menu choice: ";
	cin >> choice;

	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input!" << endl;
			cout << "Enter menu choice: ";
			cin >> choice;
		}
		else if (!cin.fail())
			break;
	}

	return choice;
};

service* services;
void AddInput() {
		cout << "=========== Data input ===========" << "\n\n";
		cout << "Enter number of the services: ";
		cin >> n;

		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input!" << endl;
				cout << "Enter number of the services: ";
				cin >> n;
			}
			else if (!cin.fail())
				break;
		}
		services = new service[n];

		for (int i = 0; i < n; i++) {
			cout << "Service " << i + 1 << endl;
			cout << "id is ";
			cin >> services[i].id;
			cout << endl;
			cout << "name is ";
			cin >> services[i].name;
			cout << endl;
			cout << "price is ";
			cin >> services[i].price;
			cout << endl;
		}

		cout << "The array contains of " << endl;
		for (int i = 0; i < n; i++) { // shows all the data of the array
			cout << "id: " << services[i].id << 
				" | " << "name: " << services[i].name << 
				" | " << "price: " << services[i].price << "\n";
		}
}
void showOutput(service* services) {

	cout << "=========== Data searching ===========" << "\n\n";
	char id[10];
	cout << "Enter id: ";
	cin >> id;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (strcmp(id, services[i].id) == 0)
			cout << "id -> " << services[i].id << " | " << "name -> " << services[i].name << " | " << "price -> " << services[i].price << endl;
	}
	cout << " All the services are: " << n << "\n\n";
}
//data searching, show info about the service by its id

int main(int argc, char** argv) {

	int menuChoice = displayMenu();

	while (menuChoice != Exit) {
		switch (static_cast<menu>(menuChoice)) {
		case Add:
			cout << "You chose " << Add << ". Add a new service\n\n";
			AddInput();
			break;
		case Show:
			cout << "You chose " << Show << ". Show all the services\n\n";
			showOutput(services);
			break;
		case Exit:
			cout << "You chose " << Exit << ". Exit\n\n";
			break;
		default:
			cout << "You did not make any choice!";
			break;
		}
		menuChoice = displayMenu();
	}

	system("PAUSE");
	return 0;
}

