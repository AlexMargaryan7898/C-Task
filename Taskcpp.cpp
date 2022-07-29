#include <iostream>
#include <string>
#include <vector>

#include <numeric>

using namespace std;


enum Profession {
	Unknown,
	Developer,
	Manager,
	QA,
	Marketing,
	HR,
};
constexpr unsigned int str2int(const char* str, int h = 0)
{
	return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}
Profession professionchecker(string s) {

	switch (str2int(s.c_str())) {
	case  str2int("Developer"):
		return Profession::Developer;
		break;
	case  str2int("Manager"):
		return Profession::Manager;
		break;
	case  str2int("QA"):
		return Profession::QA;
		break;
	case  str2int("Marketing"):
		return Profession::Marketing;
		break;
	case  str2int("HR"):
		return Profession::HR;
		break;
	case  str2int("Unknown"):
		return Profession::Unknown;
		break;
	}
};
class  Employee {
public:
	string name;
	string surname;
	int age;
	Profession profession;
	Employee(string empl_name, string empl_surname, int empl_age, string empl_profession) {
		name = empl_name;
		surname = empl_surname;
		age = empl_age;
		profession = professionchecker
		(empl_profession);
	}
};
void EmployeeChecker(int n, vector<Employee*> employees, string namefilter, string surnamefilter, int agefilter, string professionfilter) {
	for (auto i = employees.begin(); i < employees.end(); i++) {
		Employee employee = **i;
		Profession professionfilt = professionchecker(professionfilter);
		if (employee.name.compare(namefilter) == 0 || employee.surname.compare(surnamefilter) == 0 || employee.age == agefilter || employee.profession == professionfilt) {
			std::cout << employee.name << " " << employee.surname << " " << employee.age << std::endl;
		}
	}
}
int main() {
	string n;
	std::cout << "Enter Number of Employees - ";
	std::cin >> n;


	bool numOfEmployeeCHecker = true;
	while (numOfEmployeeCHecker) {
		for (int j = 0; j < n.size(); j++) {
			if (n[j] < '0' || n[j] > '9') {
				std::cout << std::endl << "The Number of Array Should be a Value!  Please Enter Number!";
				std::cin >> n;

			}
			else {
				numOfEmployeeCHecker = false;
			}
		}
	}
	vector<Employee*> employees;
	for (int i = 0; i < stoi(n); i++) {
		bool agechecker = true;
		string age;
		string name, surname, professionStr;
		std::cout << "enter Employee" << " " << i + 1 << "  " << "Name Surname Age Profession ";
		std::cin >> name >> surname >> age >> professionStr;
		while (agechecker) {
			for (int j = 0; j < age.size(); j++) {
				if (age[j] < '0' || age[j] > '9') {
					std::cout << std::endl << age << " is not a number please enter number";
					std::cin >> age;
				}
				else {
					agechecker = false;
				}
			}
		}
		Employee* emp = new Employee(name, surname, stoi(age), professionStr);
		employees.push_back(emp);
	}

	string namefilter, professionfilter, surnamefilter;
	int  agefilter;
	std::cout << "Search Employees using name or surname or age or profession if you don't ";
	std::cin >> namefilter >> surnamefilter >> agefilter >> professionfilter;

	EmployeeChecker(stoi(n), employees, namefilter, surnamefilter, agefilter, professionfilter);
	return 0;
};