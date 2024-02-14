#include<iostream>
using namespace std;

class Admin {
    Doctor doctor;
    Patient patient;
    Receptionist receptionist;
    Nurse nurse;

public:
    void adminMenu() {
        char ch;
        do {
            cout << "**********************" << endl;
            cout << "\t \t WELCOME TO THE ADMIN MENU\t " << endl;
            cout << "**********************\n" << endl;
            cout << "\n 1.Doctor";
            cout << "\n 2.Nurse";
            cout << "\n 3.Receptionist";
            cout << "\n 4.BACK ONE STEP";
            cout << "\n\n************************" << endl;
            cout << "\nPlease Enter Your Choice (1-4) ";
            cin >> ch;
            switch (ch)
            {
            case '1': doctor.doctorMenu();
                break;
            case '2': nurse.nurseMenu();
                break;
            case '3': receptionist.ReceptionistMenu();
                break;
            }
        } while (ch != '4');
    }
};