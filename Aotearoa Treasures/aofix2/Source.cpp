#include <iostream>
#include <string>
#include <vector>
using namespace std;

//ADD USER ROLES HERE (CUSTOMER, ADMINISTRATOR)
//CLASS STORE HERE

class Store {

public:
	string name;
	int id;
};

//CLASS PRODUCT HERE
class Employee {
public:
	int id;
	string name;
	int storeId;
	string storeName;

	vector<string> schedule;

	Employee(int i, string n, int sId, string sName) {
		id = i;
		name = n;
		storeId = sId;
		storeName = sName;
		schedule = vector<string>(7, "off");
		
		for (int day = 0; day < 7; day++) { // change? for (int day = 0; day < 7; day++)
			schedule[day] = "off";
		}
	}

	void showRoster() {
		cout << "\nID: " << id << ", Name: " << name << ", Store: " << storeName << endl;
		cout << "Mon: " << schedule[0] << " Tue: " << schedule[1] << " Wed: " << schedule[2] << endl;
		cout << "Thu: " << schedule[3] << " Fri: " << schedule[4] << " Sat: " << schedule[5] << " Sun: " << schedule[6] << endl;
		cout << endl;
	}

	void updateShift(int day, string shift) {
		if (day >= 1 && day <= 7) {
			schedule[day - 1] = shift;
		}
		else {
			cout << "Entered incorrect day" << endl;
		}
	}
};

vector<Employee> employees;

void setupEmployees() {
	Employee e1(101, "Example employee 1", 1, "Auckland");
	e1.schedule[0] = "am";
	e1.schedule[1] = "pm";
	e1.schedule[2] = "am";
	employees.push_back(e1);


	Employee e2(102, "Example employee 2", 1, "Auckland");
	e2.schedule[0] = "PM";
	e2.schedule[3] = "AM";
	e2.schedule[4] = "PM";
	employees.push_back(e2);
}

void editEmployeeShift() {
	int id;
	cout << "Please enter the employee ID ";
	cin >> id;

	int index = -1; // to set that we haven't found an ID yet
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i].id == id) { // checks through id to match employee id to inputted id
			index = i; // remembers where we found the matching id
			break; // stops searching
		}
	}
	if (index == -1) {
		cout << "No matching employee with entered ID" << endl;
		return;
	}

	employees[index].showRoster();

	int day;
	cout << "Select a day to change" << endl;
	cout << "(1) Monday, (2) Tuesday, (3) Wednesday, (4) Thursday, (5) Friday" << endl;
	cout << "(6) Saturday, (7) Sunday\n" << endl;
	cin >> day;

	string shift;
	cout << "Select a new shift (am/pm/off)" << endl;
	cin >> shift;

	employees[index].updateShift(day, shift);
	cout << "Shift has been updated" << endl;
	employees[index].showRoster();
}

void addNewEmployee() {
	int id, storeId;
	string name, storeName;

	cout << "Please enter the new employee ID: ";
	cin >> id;

	cout << "Please enter the new employee name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Please enter the store ID: ";
	cin >> storeId;

	cout << "Please enter the store name: ";
	cin.ignore();
	getline(cin, storeName);

	Employee newEmployee(id, name, storeId, storeName);
	employees.push_back(newEmployee);

	cout << "Thank you. New employee has now been added\n" << endl;
	newEmployee.showRoster();
}

int main() {
	Store s1;
	s1.name = "Auckland";
	s1.id = 1;

	vector<Store> stores;
	stores.push_back(s1);

	setupEmployees();

	int choice;
	cout << "Welcome to the Roster Menu" << endl;

	do {
		cout << "Select an option" << endl;
		cout << "(1) View Employees, (2) Edit a shift, (3) Add new employee (4) Exit\n" << endl;
		cin >> choice;

		if (choice == 1) {
			for (int i = 0; i < employees.size(); i++) {
				employees[i].showRoster();
			}
		}
		else if (choice == 2) {
			cout << endl;
			editEmployeeShift();
		}
		else if (choice == 3) {
			addNewEmployee();
		}
		else if (choice == 4) {
			cout << "goodbye" << endl;
		}

	} 
	while (choice != 4);

	return 0;
}