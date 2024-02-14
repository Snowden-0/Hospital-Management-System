#include<iostream>
using namespace std;


struct DOB {
    unsigned int date, month, year;
};
struct Address {
    char city[20], tehsil[20], district[20];
};
class Person {
    char name[40], gender[8], bloodGroup[5];
    Address address; //object of address
    DOB dob; //object of dateOFBirth
    unsigned int age;
    unsigned long long phoneNum, CNIC;
public:
    Person();
    void setPerson();
    void showPerson();
};
Person::Person() {
    char name[40], gender[8], bloodGroup[5];
    Address address; //object of address
    DOB dob; //object of dateOFBirth
    unsigned int age = 0;
    unsigned long long phoneNum = 0, CNIC = 0;
}
void Person::setPerson() {
    cin.ignore();
    cin.clear();
    cout << "\nEnter Name : ";
    cin.getline(name, 50);
    cout << "\nEnter Gender : ";
    cin.getline(gender, 8);
    cout << "\nEnter Blood group:";
    cin.getline(bloodGroup, 5);

    cout << "\nEnter address ";
    cin.clear();
    cout << "\nEnter City/Village: ";
    cin.getline(address.city, 20);
    cin.clear();
    cout << "\nEnter Tehsil : ";
    cin.getline(address.tehsil, 20);
    cin.clear();
    cout << "\nEnter district : ";
    cin.getline(address.district, 20);
    cout << "\nEnter Age :";
    cin >> age;
    cout << "\nEnter DateOfBirth DD/MM/YYYY";
    cout << "\nEnter Day : ";
    cin >> dob.date;
    cout << "\nEnter month : ";
    cin >> dob.month;
    cout << "\nEnter Year : ";
    cin >> dob.year;
    cout << "\nEnter phoneNum :";
    cin >> phoneNum;
    cout << "\nEnter CNIC (without dashes):";
    cin >> CNIC;
}
void Person::showPerson() {
    cout << "\nName: " << name;
    cout << "\nGender: " << gender;
    cout << "\nBlood Group:" << bloodGroup;
    cout << "\nAddress : " << address.city << ", Tehsil " << address.tehsil << ", District " << address.district;
    cout << "\nAge: " << age << endl;
    cout << "\nDOB : " << dob.date << "/" << dob.month << "/" << dob.year;
    cout << "\nPhoneNum: 0" << phoneNum;
    cout << "\nCNIC : " << CNIC << endl;

};