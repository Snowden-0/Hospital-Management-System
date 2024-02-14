#include<iostream>
using namespace std;


struct Date {
    unsigned int day, month, year;
};
struct Bill
{
    unsigned int bedcharges, doctorFees, personCharges, maintainceCharges, careCharges;
};
class Patient :public Person {
    Date dateAd, dateDis;
    int patientNo;
    Date admitDate[30];
    Date dischargeDate[30];
    Bill bill;
    int totalBill;

public:
    Patient();
    void setPatientNo(int);
    void setPatientBill();
    void showPatientBill();
    void setPatient();
    void showPatient();
    int returnPatId();
    void patientMenu();
    void writePatient();
    void searchPatientId(int);
    void showAllPatient();
    void updatePatient(int);
    void deletePatient(int);
};
Patient::Patient() {
    // Date dateAd,dateDis;
    int patientNo = 0;
    //Date admitDate[30];
    //Date dischargeDate[30];
   // Bill bill;
    int totalBill = 0;
}
void Patient::setPatientNo(int id) {
    patientNo = id;
};
void Patient::setPatientBill()
{
    cout << "\nEnter Doctor  Fee Charges : ";
    cin >> bill.doctorFees;
    cout << "\nEnter Hospital bed Charges : ";
    cin >> bill.bedcharges;
    cout << "\nEnter Hospital Care Charges : ";
    cin >> bill.careCharges;
    cout << "\nEnterHospital Maintaince Charges : ";
    cin >> bill.maintainceCharges;
    cout << "\nEnterPatient personal Charges : ";
    cin >> bill.personCharges;
    totalBill = bill.doctorFees + bill.bedcharges + bill.careCharges + bill.maintainceCharges + bill.personCharges;
};
void Patient::showPatientBill()
{
    cout << "\nDoctor  Fee Charges : " << bill.doctorFees;
    cout << "\nHospital bed Charges : " << bill.bedcharges;
    cout << "\nHospital Care Charges : " << bill.careCharges;
    cout << "\nHospital Maintaince Charges : " << bill.maintainceCharges;
    cout << "\nPatient personal Charges : " << bill.personCharges;
    cout << "\nTotal Fee Charge :\t" << totalBill;
}
void Patient::setPatient()
{
    helo:
    setPerson();
    try {
        cout << "\nEnter The registration number : ";
        cin >> patientNo;
        if (!patientNo > 0) {
            if (patientNo <= 0)
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
    cout << "\nEnter admit day :";
    cin >> dateAd.day;
    cout << "\nEnter admit month :";
    cin >> dateAd.month;
    cout << "\nEnter admit year :";
    cin >> dateAd.year;
    cout << "\nEnter Discharge day : ";
    cin >> dateDis.day;
    cout << "\nEnter Discharge month : ";
    cin >> dateDis.month;
    cout << "\nEnter Discharge year : ";
    cin >> dateDis.year;

    setPatientBill();
}
void Patient::showPatient()
{
    cout << "\nRegistration number of patient: " << patientNo << "\n";
    cout << "\nAdmit date : " << dateAd.day << "/" << dateAd.month << "/" << dateAd.year << endl;;
    cout << "\nDischarhge date :" << dateDis.day << "/" << dateDis.month << "/" << dateDis.year << endl;
    showPatientBill();
    showPerson();
}
int Patient::returnPatId() {
    return patientNo;
};
void Patient::patientMenu() {

    char choice;
    int num;
    do {
        cout << "**************" << endl;
        cout << "\n1.ENTER NEW PATIENT DATA";
        cout << "\n2.DISPLAY ALL PATIENTS DATA";
        cout << "\n3.SEARCH PATIENT DATA ";
        cout << "\n4.UPDATE PATIENT DATA";
        cout << "\n5.DELETE PATIENT DATA";
        cout << "\n6.BACK ONE STEP";
        cout << "\n****************" << endl;
        cout << "\nSELECT ONR OPTION (1-6) ";
        cin >> choice;
        switch (choice)
        {
        case '1': writePatient();
            break;
        case '2': showAllPatient();
            break;
        case '3': cout << "\nENTER REGISTRATION NO THAT YOU WANT TO SEARCH : ";
            cin >> num;
            searchPatientId(num);
            break;
        case '4': cout << "\nENTER THE REGISTRATION NO THAT YOU WANT TO UPDATE : ";
            cin >> num;
            updatePatient(num);
            break;
        case '5': cout << "\nENTER THE REGISTRATION NO THAT YOU WANT TO DELETE : ";
            cin >> num;
            deletePatient(num);
            break;
        }
    } while (choice != '6');

};
void Patient::writePatient() {
    Patient patient;
    ofstream out;
    out.open("Patient.dat", ios::binary | ios::app);
    if (!out) {
        cout << "\nfile did't open";
    }
    patient.setPatient();

    //CHECK ID ALREADY EXIT OR NOT
    /*
    Patient patient2;
    next:
    infile("Patient.dat",ios::binary|ios::app|ios::in);
    while(infile.read(reinterpret_cast<char*> (&patient2),sizeof(Patient))){
    if(patient.returnpatientId()==patient2.returnNurseId()){
    cout<<"\nID ALREADY EXIT "<<endl;
    cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO Patient ";
    cin>>id;
    patient.setpatientId(id);
    goto next;}
    }
    infile.close();
    */
    // check id End

    out.write(reinterpret_cast<char*> (&patient), sizeof(Patient));
    cout << "\nPATIENT DATA SAVED";
    out.close();
};
void Patient::searchPatientId(int id) {
    Patient patient;
    ifstream in;
    in.open("Patient.dat", ios::binary);
    if (!in) {
        cout << "\nFILE NOT OPEN";
    }
    bool present = 0;
    while (in.read(reinterpret_cast<char*> (&patient), sizeof(Patient)))
    {
        if (patient.returnPatId() == id)
        {
            patient.showPatient();
            present = 1;
        }
    }
    in.close();
    if (present == 0)
        cout << "\nRECORD NOT EXIT";
};
void Patient::showAllPatient() {
    Patient patient;
    ifstream in;
    in.open("Patient.dat", ios::binary);
    if (!in)
    {
        cout << "\nFile not open ";
    }
    cout << "\nDISPLAY ALL RECORD ";
    while (in.read(reinterpret_cast<char*> (&patient), sizeof(Patient)))
    {
        patient.showPatient();
        cout << "\n-----------------------------------------------------------------------";
    }
    cout << "\nEND FILE";
    in.close();
};
void Patient::updatePatient(int id) {
    bool present = 0;
    Patient patient;
    fstream File;
    File.open("Patient.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\nFILE NOT OPEN";
    }
    while (!File.eof() && present == 0)
    {

        File.read(reinterpret_cast<char*> (&patient), sizeof(Patient));
        if (patient.returnPatId() == id)
        {
            patient.showPatient();

            //CHECK ID ALREADY EXIT OR NOT
            /*
            Patient patient2;
            next:
            infile("Patient.dat",ios::binary|ios::app|ios::in);
            while(infile.read(reinterpret_cast<char*> (&patient2),sizeof(Patient))){
            if(patient.returnpatientId()==patient2.returnNurseId()){
            cout<<"\nID ALREADY EXIT "<<endl;
            cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO Patient ";
            cin>>id;
            patient.setpatientId(id);
            goto next;}
            }
            infile.close();
            */
            // check id End

            cout << "\nENTER NEW DATA " << endl;
            patient.setPatient();
            int setPosition = sizeof(patient);
            File.seekp(-setPosition, ios::cur);
            File.write(reinterpret_cast<char*> (&patient), sizeof(Patient));
            cout << "\nPatient NEW RECORD SAVED ";
            present = 1;
        }
    }

};
void Patient::deletePatient(int id) {
    Patient patient;
    ifstream in;
    in.open("Patient.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN ";
    }

    ofstream out;
    out.open("Temp.dat", ios::out);
    if (out) {
        in.seekg(0, ios::beg);
        while (in.read(reinterpret_cast<char*> (&patient), sizeof(Patient)))
        {
            if (patient.returnPatId() != id)
            {
                out.write(reinterpret_cast<char*> (&patient), sizeof(Patient));
            }
        }
    }
    else
        cout << "temp file not open";
    out.close();
    in.close();
    remove("Patient.dat");
    rename("Temp.dat", "Patient.dat");
    cout << "\nRECORD  DELETED..";
};