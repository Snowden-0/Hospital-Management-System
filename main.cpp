#include<iostream>
#include<string.h>
#include<fstream>
#include<exception>
#include<stdexcept>
#include"person.h"
#include"staff.h"
#include"nurse.h"
#include"patient.h"
#include"doctor.h"
#include"receptionist.h"
#include"admin.h"
using namespace std;



int main()
{
	Admin admin;
	Receptionist receptionist;
	Doctor doctor;
	int choice;
	char password[15];
	do {
		cout << "**********************" << endl;
		cout << "\t \t WELCOME TO THE HOSPITAL \t " << endl;
		cout << "**********************\n" << endl;

		cout << "\n\t1.ADMIN";
		cout << "\n\t2.RECEPTIONIST";
		cout << "\n\t3.DOCTOR";
		cout << "\n\t4.FINISH PROGRAM";
		cout << "\n\n************************" << endl;

		cin >> choice;
		switch (choice) {
		case 1:
		adminLogIn:
			cout << "ENTER YOUR PASSWORD : ";

			cin >> password;

			if (strcmp(password, "umar") == 0)
			{
				admin.adminMenu();
			}
			else
			{
				cout << "WRONG PASSWORD!!!\n";
				goto adminLogIn;
			}
			break;
		case 2:
		receptionistLogIn:
			cout << "Enter Receptionist password: ";

			cin >> password;

			if (strcmp(password, "ubaid") == 0)
			{
				receptionist.receptionWork();
			}
			else
			{
				cout << "WRONG PASSWORD!!!\n";
				goto receptionistLogIn;
			}
			break;
		case 3:

		doctorLogIn:
			cout << "ENTER DOCTOR PASSWORD : ";

			cin >> password;

			if (strcmp(password, "hammad") == 0)
			{
				doctor.DoctorWork();
			}
			else
			{
				cout << "WRONG PASSWORD!!!\n";
				goto doctorLogIn;
			}
			break;
		}
	} while (choice != 4);
	return 0;
}


