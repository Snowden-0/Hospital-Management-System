#include<iostream>
using namespace std;


class Doctor : public Staff {
    int doctorId;
    char speclizationOfDoctor[50];
    Patient patient;
    Nurse nurse;
public:
    Doctor();
    void DoctorWork();
    void setDoctorId(int);
    void setDoctor();
    void showDoctor();
    int returnDocId();
    void doctorMenu();
    void writeDoctor();
    void searchDoctorId(int);
    void showAllDoctor();
    void updateDoctor(int);
    void deleteDoctor(int);
};
Doctor::Doctor() {
    doctorId = 0;
}
void Doctor::DoctorWork() {
    cout << "**********************" << endl;
    cout << "\t \t WELCOME TO THE DOCTOR MENU\t " << endl;
    cout << "**********************\n" << endl;
    int id;
    char choice;
    cout << "\n1. SEARCH PATIENT ";
    cout << "\n2. SEARCH DOCTOR ";
    cout << "\n3. SHOW ALL DOCTOR ";
    cout << "\n4. SEARCH NURSE ";
    cout << "\n5. SHOW ALL NURSE ";
    cout << "\n6. BACK ONE STEP";
    cout << "\n\n************************\n" << endl;
    cout << "\nPLEASE ENTER  (1-6) OPTION ";
    cin >> choice;
    switch (choice) {
    case '1':cout << "\nENTER PATIENT ID THAT YOU WANT TO SEARCH : ";
        cin >> id;
        patient.searchPatientId(id);
        break;
    case '2':cout << "ENTER DOCTOR ID THAT YOU WANT TO SEARCH : ";
        cin >> id;
        searchDoctorId(id);
        break;

    case '3':showAllDoctor();
        break;
    case '4':cout << "ENTER NURSE ID THAT YOU WANT SEARCH:";
        cin >> id;
        nurse.searchNurse(id);
        break;
    case '5': nurse.displayAllNurse();
        break;
    case '6':break;
    default:cout << "\b";
    }while (choice != '5');
}
void Doctor::setDoctorId(int id) {
    doctorId = id;
}
int Doctor::returnDocId() {
    return doctorId;
}
void Doctor::setDoctor() {
    helo:
    setStaff();

    try {
        cout << "\nEnter Doctor ID : ";
        cin >> doctorId;
        if (!doctorId > 0) {
            if (doctorId <= 0)
                throw 0;
            else
                throw runtime_error("you are Enter string\n");
        }
    }
    catch (int x) {
        cout << "\nyou enter less than one";
    }
    catch (runtime_error error) {
        cout << error.what();
    }
    goto helo;
    cin.ignore();
    cin.clear();
    cout << "\nEnter  speclization : ";
    cin.getline(speclizationOfDoctor, 50);
}
void Doctor::showDoctor() {

    cout << "\n\n\n ------ DISPLAYALLDATA -----------\n\n" << endl;
    cout << "\nDoctor id : #" << doctorId;
    cout << "\nDoctor speclization : " << speclizationOfDoctor;
    showStaff();
};
void Doctor::doctorMenu() {
    char choice;
    do {
        int id;
        cout << "\n1. ENTER NEW DOCTOR DATA";
        cout << "\n2. Search DOCTOR ";
        cout << "\n3. SHOW ALL DOCTOR ";
        cout << "\n4. UPDATE DOCTOR DATA";
        cout << "\n5. BACK ONE STEP";
        cout << "\n\n\tPLEASE ENTER  (1-5) OPTION ";
        cin >> choice;
        switch (choice) {
        case '1': writeDoctor();
            break;
        case '2':cout << "ENTER DOCTOR ID THAT YOU SEARCH:";
            cin >> id;
            searchDoctorId(id);
            break;

        case '3':showAllDoctor();
            break;
        case '4':cout << "ENTER DOCTOR ID THAT YOU WANT UPDATE:"; cin >> id;
            updateDoctor(id);
            break;
        case '5': cout << "ENTER DOCTOR ID THAT YOU WANT TO DELETE DOCTOR";
            cin >> id;
            deleteDoctor(id);
            break;
        case '6':break;
        default:cout << "\b";
        }
    } while (choice != '5');

}
void Doctor::writeDoctor() {
    Doctor doctor;
    ofstream out;
    out.open("Doctor.dat", ios::binary | ios::app);
    if (!out) {
        cout << "\nfile did't open";
    }
    doctor.setDoctor();

    //CHECK ID ALREADY EXIT OR NOT
    /*
    next:
    infile("Doctor.dat",ios::binary|ios::app|ios::in);
    while(infile.read(reinterpret_cast<char*> (&doctor2),sizeof(Doctor))){
    if(doctor.returnDoctorId()==doctor2.returnDoctorId()){
    cout<<"\nID ALREADY EXIT "<<endl;
    cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO NURSE ";
    cin>>id;
    doctor.setDoctorId(id);
    goto next;}
    }
    infile.close();
    */
    // check id End

    out.write(reinterpret_cast<char*> (&doctor), sizeof(Doctor));
    cout << "\nDOCTOR DATA SAVED";
    out.close();
};
void Doctor::searchDoctorId(int id) {
    Doctor doctor;
    ifstream in;
    in.open("Doctor.dat", ios::binary);
    if (!in) {
        cout << "\nFILE NOT OPEN";
    }
    bool present = 0;
    while (in.read(reinterpret_cast<char*> (&doctor), sizeof(Doctor)))
    {
        if (doctor.returnDocId() == id)
        {
            doctor.showDoctor();
            present = 1;
        }
    }
    in.close();
    if (present == 0)
        cout << "\nRECORD NOT EXIT";
};
void Doctor::showAllDoctor() {
    Doctor doctor;
    ifstream in;
    in.open("Doctor.dat", ios::binary);
    if (!in)
    {
        cout << "\nFile not open ";
    }
    cout << "\nDISPLAY ALL RECORD ";
    while (in.read(reinterpret_cast<char*> (&doctor), sizeof(Doctor)))
    {
        doctor.showDoctor();
        cout << "\n-----------------------------------------------------------------------";
    }
    cout << "\nEND FILE";
    in.close();
};
void Doctor::updateDoctor(int id) {

    bool present = 0;
    Doctor doctor;
    fstream File;
    File.open("Doctor.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\nFILE NOT OPEN";
    }
    while (!File.eof() && present == 0)
    {

        File.read(reinterpret_cast<char*> (&doctor), sizeof(Doctor));
        if (doctor.returnDocId() == id)
        {
            doctor.showDoctor();
            cout << "\nENTER NEW DATA " << endl;
            doctor.setDoctor();

            //CHECK ID ALREADY EXIT OR NOT
            /*
            next:
            infile("Doctor.dat",ios::binary|ios::app|ios::in);
            while(infile.read(reinterpret_cast<char*> (&doctor2),sizeof(Doctor))){
            if(doctor.returnDoctorId()==doctor2.returnDoctorId()){
            cout<<"\nID ALREADY EXIT "<<endl;
            cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO NURSE ";
            cin>>id;
            doctor.setDoctorId(id);
            goto next;}
            }
            infile.close();
            */
            // check id End

            int setPosition = sizeof(doctor);
            File.seekp(-setPosition, ios::cur);
            File.write(reinterpret_cast<char*> (&doctor), sizeof(Doctor));
            cout << "\nDOCTOR NEW RECORD SAVED ";
            present = 1;
        }
    }
};
void Doctor::deleteDoctor(int id) {
    Doctor doctor;
    ifstream in;
    in.open("Doctor.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN ";
    }
    ofstream out;
    out.open("Temp.dat", ios::out);
    in.seekg(0, ios::beg);
    while (in.read(reinterpret_cast<char*> (&doctor), sizeof(Doctor)))
    {
        if (doctor.returnDocId() != id)
        {
            out.write(reinterpret_cast<char*> (&doctor), sizeof(Doctor));
        }
    }
    out.close();
    in.close();
    remove("Doctor.dat");
    rename("Temp.dat", "Doctor.dat");
    cout << "\nRECORD  DELETED..";
};