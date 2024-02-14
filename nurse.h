#include<iostream>
using namespace std;


struct NurseDuty {
    char department[20];
    unsigned int wardNo = 0, roomNo = 0;
};
class Nurse : public Staff
{
    NurseDuty nurseDuty;
    int nurseID;
public:
    Nurse();
    void setNurseId(int);
    void setNurse();
    void showNurse();
    int returnNurseId();
    void nurseMenu();
    void writeNurse();
    void searchNurse(int);
    void displayAllNurse();
    void updateNurse(int);
    void deleteNurse(int);
};
Nurse::Nurse() {
    nurseID = 0;
}
void Nurse::setNurseId(int id) {
    nurseID = id;
}
void Nurse::setNurse()
{
    cout << "--------------------------------" << endl;
    helo:
    setStaff();

    try {
        cout << "\nEnter Nurse ID : ";
        cin >> nurseID;
        if (!nurseID > 0) {
            if (nurseID <= 0)
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
    cout << "\nEnter Department : ";
    cin.ignore();
    cin.clear();
    cin.getline(nurseDuty.department, 20);
    cout << "\nEnter ward No : ";
    cin >> nurseDuty.wardNo;
    cout << "\nEnter room NO : ";
    cin >> nurseDuty.roomNo;
}
void Nurse::showNurse()
{
    cout << "\nNurse ID : " << nurseID;
    cout << "\nDepartment : " << nurseDuty.department << " Ward No : " << nurseDuty.wardNo << " room no : " << nurseDuty.roomNo;
    showStaff();
};
int Nurse::returnNurseId() {
    return nurseID;
}
void Nurse::nurseMenu() {
    char choice;
    do {
        int id;
        cout << "\n1. INSERT NURSE DATA";
        cout << "\n2. SEARCH NURSE DATA";
        cout << "\n3. DISPLAY ALL NURSE DATA";
        cout << "\n4. UPDATE NURSE DATA ";
        cout << "\n5. DELETE NURSE DATA";
        cout << "\n6. BACK ONE STEP ";
        cout << "\nPLEASE ENTER OPTION (1-6) ";
        cin >> choice;

        switch (choice)
        {
        case '1': writeNurse();
            break;
        case '2':cout << "\nEnter NURSE ID THAT YOU WANT TO SEARCH :";
            cin >> id;
            searchNurse(id);
            break;

        case '3':displayAllNurse();
            break;
        case '4':cout << "\nEnter Nurse ID that you want update : ";
            cin >> id;
            updateNurse(id);
            break;
        case '5':cout << "\nEnter Nurse ID that you want delete : ";
            cin >> id;
            deleteNurse(id);
            break;

        }
    } while (choice != '6');

};
void Nurse::writeNurse() {
    Nurse nurse;
    ifstream infile;
    ofstream file;
    int id;
    nurse.setNurse();
    //CHECK ID ALREADY EXIT OR NOT
    
   /* next:
    ifstream infile("Nurse.dat",ios::binary|ios::app|ios::in);
    while(infile.read(reinterpret_cast<char*> (&nurse2),sizeof(Nurse))){
    if(nurse.returnNurseId()==nurse2.returnNurseId()){
    cout<<"\nID ALREADY EXIT "<<endl;
    cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO NURSE ";
    cin>>id;
    nurse.setNurseId(id);
    goto next;}
    }
    infile.close();
    
    // check id End

    file.open("Nurse.dat", ios::binary | ios::app);
    if (!file) {
        file.write(reinterpret_cast<char*> (&nurse), sizeof(Nurse));
        file.close();
    }*/

};
void Nurse::searchNurse(int id) {
    Nurse nurse;
    ifstream in;
    in.open("Nurse.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE DID'T OPEN";
    }
    bool present = 0;
    while (in.read(reinterpret_cast<char*> (&nurse), sizeof(Nurse)))
    {
        if (nurse.returnNurseId() == id)
        {
            nurse.showNurse();
            present = 1;
        }
    }
    in.close();
    if (present == 0)
        cout << "\nNURSE DATA NOT FOUND";
};
void Nurse::displayAllNurse() {
    ofstream out;
    out.open("Nurse.dat", ios::binary | ios::app);
    int obj = out.tellp() / sizeof(Nurse);
    cout << endl << " TOTAL NURSE = " << obj << endl;
    out.close();
    Nurse nurse;
    ifstream in;
    in.open("Nurse.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN";
    }
    cout << "\n SHOW ALL RECORD ";
    while (in.read(reinterpret_cast<char*> (&nurse), sizeof(Nurse)))
    {
        nurse.showNurse();
        cout << "\n  NEW RECORD DISPLAY \n";
    }
    in.close();
};
void Nurse::updateNurse(int id) {
    bool present = false;
    Nurse nurse;
    fstream File;
    File.open("Nurse.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\nFILE NOT OPEN";
    }
    while (!File.eof() && present == 0) {
        File.read(reinterpret_cast<char*> (&nurse), sizeof(Nurse));
        if (nurse.returnNurseId() == id) {
            nurse.showNurse();
            cout << "\nENTER NEW NURSE DATA" << endl;
            nurse.setNurse();

            //CHECK ID ALREADY EXIT OR NOT
            /*
            next:
            infile("Nurse.dat",ios::binary|ios::app|ios::in);
            while(infile.read(reinterpret_cast<char*> (&nurse2),sizeof(Nurse))){
            if(nurse.returnNurseId()==nurse2.returnNurseId()){
            cout<<"\nID ALREADY EXIT "<<endl;
            cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO NURSE ";
            cin>>id;
            nurse.setNurseId(id);
            goto next;}
            }
            infile.close();
            */
            // check id End

            int setPosition = sizeof(nurse);
            File.seekp(-setPosition, ios::cur);
            File.write(reinterpret_cast<char*> (&nurse), sizeof(Nurse));
            cout << "\nNURSE DATA SAVED";
            present = 1;
        }
    }
    File.close();
    if (present == 0)
        cout << "\nNURSE DATA NOT FOUND";
};
void Nurse::deleteNurse(int id) {
    Nurse nurse;
    ifstream in;
    in.open("Nurse.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN ";
    }
    ofstream out;
    out.open("Temp.dat", ios::out);
    in.seekg(0, ios::beg);
    while (in.read(reinterpret_cast<char*> (&nurse), sizeof(Nurse)))
    {
        if (nurse.returnNurseId() != id)
        {
            out.write(reinterpret_cast<char*> (&nurse), sizeof(Nurse));
        }
    }
    out.close();
    in.close();
    remove("Nurse.dat");
    rename("Temp.dat", "Nurse.dat");
    cout << "\nRECORD  DELETED..";

};