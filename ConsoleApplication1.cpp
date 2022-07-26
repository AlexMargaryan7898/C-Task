#include <iostream>
#include <string>
#include <vector>

using namespace std;


enum Profession {
	Unknown,
	Developer,
    Manager,
	QA,
	Marketing,
	HR,
};
Profession changer(string s) {
	if (s == "Developer") {
		return Profession::Developer;
	}
	else if (s == "Manager") {
		return Profession::Manager;
	}
	else if (s == "QA") {
		return Profession::QA;
	}
	else if (s == "HR") {
		return Profession::HR;
	}
	else if (s == "Marketing") {
		return Profession::Marketing;
	}
	else {
		return Profession::Unknown;
	}
};

class  Employee {
public: 
	string name;
    string surname;
	int age;
	Profession profession;

	Employee(string x, string y, int z, string professionstr) {
		name = x;
		surname = y;
		age = z;
		profession = changer(professionstr);
	}
};

int main() {
	int n;
	cout << "Enter Number of Employees - ";
	cin >> n;
	vector<Employee*> employees;

	for (int i = 0; i < n; i++) {
		string age;
		string name, surname, professionstr;
		cout << "enter Employee" << " " << i + 1 << "  " << "Name Surname Age Profession ";
		std::cin >> name >> surname >> age >> professionstr;

		for (int j = 0; j < age.size(); j++) {
			if (age[j] < '0' || age[j] > '9') {
				std::cout << std::endl << "Age is not a number";
				return 0;
			}
		}

		Employee* emp = new Employee(name, surname, stoi(age), professionstr);
		employees.push_back(emp);
	}

	for (int i = 0; i < n; i++) {
		Employee employee = *employees[i];

		if (employee.name.compare("Vazgen") == 0 && employee.age >= 25 && employee.profession == Profession::Developer) {
			
			cout << employee.name << " " << employee.surname << " " << employee.age << " " << "Developer";
		}
	}
	return 0;
};

































































//#include <iostream>
//#include <string>
//
//using namespace std;
//
//enum Profession {
//	Developer,
//	Manager,
//	QA,
//	Marketing,
//	HR,
//};
//class  Employee {
//public:
//	char name[20];
//	char surname[20];
//	int age;
//	Profession profession;
//}obj[3];
//
//Profession changer(string s) {
//	if (s == "Developer") {
//		return 	 Profession::Developer;
//	}
//}
//int main() {
//
//	for (int i = 0; i < 3; i++) {
//		string professionStr;
//		std::cout << "enter Employee" << " " << i + 1 << "  " << "Name Surname Age Profession ";
//		std::cin >> obj[i].name >> obj[i].surname >> obj[i].age >> professionStr;
//		obj[i].profession = changer(professionStr);
//
//	}
//	for (int i = 0; i < 3; i++) {
//
//
//		char name[] = "Vazgen";
//		int result = strcmp(name, obj[i].name);
//
//		if (result == 0 && obj[i].age >= 25 && obj[i].profession == Profession::Developer) {
//			std::cout << obj[i].name << " " << obj[i].surname << " " << obj[i].age << " " << "Developer";
//		}
//	}
//
//}
//




