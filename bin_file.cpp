#include <iostream>
#include <fstream>
#include <string>

//Use the entered service id to
//determine its name and price

using namespace std;

enum menu {
	Add = 1,
	Show,
	Data,
	Exit
};

struct service {
	char id[10];
	char name[20];
	int price;
};

int recordsCount;
int servQuantity;

service InputService();
void infoForm(service info);
void showOutput(service services);
void showAllData(service services);
int displayMenu();

fstream file("services.bin", ios::in | ios::out | ios::binary); // file for in and out

//int main(int argc, char** argv) {
int main(int argc, char** argv) {
	//service services{};

	int menuChoice = displayMenu();

	fstream file("services.bin", ios::in | ios::out | ios::binary); // file for in and out

	if (!file) { // if the file wasn't opened succesfully
		file.open("services.bin", ios::in | ios::out | ios::trunc | ios::binary); // create an empty file and open for in and out
	}
	if (!file) { // it still has no access
		cout << "Cannot open file!" << endl; // show an error
	}
	else {
			service services{};
			while (menuChoice != Exit) {
				switch (static_cast<menu>(menuChoice)) {
				case Add:
					cout << "You chose " << Add << ". Add a new service\n\n";
					service serv = InputService();
					//InputService();
					break;
				case Show:
					cout << "You chose " << Show << ". Show the service by id\n\n";
					showOutput(services);
					//file.read((char*)&services, sizeof(services)); // binary read from file
					break;
				case Data:
					cout << "You chose " << Data << ". Show all data\n\n";
					showAllData(services);
					//file.read((char*)&services, sizeof(services)); // binary read from file
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

		file.close(); // close the file
	}

	//system("PAUSE");
	return 0;
}

int displayMenu() {
	int choice;
	cout << Add << ". Add a new service\n"
		<< Show << ". Show the service by id\n"
		<< Data << ". Show all data\n"
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

service InputService() {
	file.seekg(0, ios::end); // place the current read position to the end

	cout << "=========== Data input ===========" << "\n\n";
	cout << "Enter number of the services: ";
	cin >> servQuantity;
	cout << endl;

	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input!" << endl;
			cout << "Enter number of the services: ";
			cin >> servQuantity;
		}
		else if (!cin.fail())
			break;
	}

	service serv{};
	for (int i = 0; i < servQuantity; i++) {

		cout << "Service " << i + 1 << endl;
		cout << "id is ";
		cin >> serv.id;
		cout << "name is ";
		cin >> serv.name;
		cout << "price is ";
		cin >> serv.price;
		cout << endl;

		file.write((char*)&serv, sizeof(serv)); // write to file
	}
	return serv;
}

void infoForm(service services) { //  file info

	cout << "id: " << services.id << " | ";
	cout << "name: " << services.name << " | ";
	cout << "price: " << services.price;
	cout << endl;
}

void showOutput(service services) { // output service by its id
	file.seekg(0, ios::end); // place the current read position to the end
	streamoff length = file.tellg(); // get current position in bytes, determine the length of the file
	recordsCount = length / sizeof(service); // determine the number of records
	file.seekg(0, ios::beg); // place the current read position back to beginning

	cout << "=========== Data searching ===========" << "\n\n";
	char id[10];
	
	cout << "Length of the file is " << length << " bytes" << endl; 
	cout << "File contains " << recordsCount << " records" << "\n\n";

	cout << "Enter id: ";
	cin >> id;

	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input!" << endl;
			cout << "Enter id: ";
			cin >> id;
		}
		else if (!cin.fail())
			break;
	}


	for (int i = 0; i < recordsCount; i++) {
		//service services{};
			file.read((char*)&services, sizeof(services)); // binary read from file

		if (strcmp(id, services.id) == 0) {

			infoForm(services);
		}
		cout << endl;
	}
}

void showAllData(service services) { // output service by its id
	file.seekg(0, ios::end); // place the current read position to the end
	streamoff length = file.tellg(); // get current position in bytes, determine the length of the file
	recordsCount = length / sizeof(service); // determine the number of records
	file.seekg(0, ios::beg); // place the current read position back to beginning

	for (int i = 0; i < recordsCount; i++) {
		//service services{};
			file.read((char*)&services, sizeof(services)); // binary read from file

			infoForm(services);
	}
	cout << endl;
}

//service InputForm() {
//	service serv{};
//
//	cout << "id is ";
//	cin >> serv.id;
//	cout << "name is ";
//	cin >> serv.name;
//	cout << "price is ";
//	cin >> serv.price;
//	cout << endl;
//
//	file.write((char*)&serv, sizeof(serv)); // WRITE TO FILE
//
//	return serv;
//}
// 
// //void InputService() {
//	file.seekg(0, ios::end); // place the current read position to the end
//
//	cout << "=========== Data input ===========" << "\n\n";
//	cout << "Enter number of the services: ";
//	cin >> servQuantity;
//	cout << endl;
//
//	while (1) {
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "You have entered wrong input!" << endl;
//			cout << "Enter number of the services: ";
//			cin >> servQuantity;
//		}
//		else if (!cin.fail())
//			break;
//	}
//
//	//service serv{};
//	for (int i = 0; i < servQuantity; i++) {
//		cout << "Service " << i + 1 << endl;
//		service services = InputForm();
//		//file.write((char*)&serv, sizeof(serv)); // WRITE TO FILE
//	}
//}