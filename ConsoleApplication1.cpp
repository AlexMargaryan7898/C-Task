#include <iostream>
#include <string>

using namespace std;

enum Profession {
	Developer,
	Manager,
	QA,
	Marketing,
	HR,
};
class  Employee {
public:
	char name[20];
	char surname[20];
	int age;
	Profession profession;
}obj[3];

Profession changer(string s) {
	if (s == "Developer") {
		return 	 Profession::Developer;
	}
}
int main() {

	for (int i = 0; i < 3; i++) {
		string professionStr;
		std::cout << "enter Employee" << " " << i + 1 << "  " << "Name Surname Age Profession ";
		std::cin >> obj[i].name >> obj[i].surname >> obj[i].age >> professionStr;
		obj[i].profession = changer(professionStr);

	}
	for (int i = 0; i < 3; i++) {
		char name[] = "Vazgen";
		int result = strcmp(name, obj[i].name);

		if (result == 0 && obj[i].age >= 25 && obj[i].profession == Profession::Developer) {
			std::cout << obj[i].name << " " << obj[i].surname << " " << obj[i].age << " " << "Developer";
		}
	}

}





