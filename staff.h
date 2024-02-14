#include<iostream>
using namespace std;


struct WorkingHours {
	char startTime[10], endTime[10];
};
class Staff :public Person {
	char salary[15];
	WorkingHours workingHours;
public:
	Staff();
	void setStaff();
	void showStaff();
};
Staff::Staff() {

}
void Staff::setStaff()
{
	setPerson();
	cin.ignore();
	cin.clear();
	cout << "\nEnter salary:";
	cin.getline(salary, 15);

	cin.clear();
	cout << "\nDuty Starting Time : ";
	cin.getline(workingHours.startTime, 10);
	cin.clear();
	cout << "\nDuty Ending Time : ";
	cin.getline(workingHours.endTime, 10);
};
void Staff::showStaff()
{

	cout << "\nSalary : " << salary;
	cout << "\nDuty Time : " << workingHours.startTime << "--" << workingHours.endTime << endl;
	showPerson();
};