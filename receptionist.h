#include<iostream>
using namespace std;


class Receptionist :public Staff {
    int receptionistID;
    Patient patient;

public:
    Receptionist();
    void receptionWork();
    void setReceptionistId(int);
    void setReceptionist();
    void showReceptionist();
    int returnRecId();
    void ReceptionistMenu();
    void writeReceptionist();
    void searchReceptionistId(int);
    void showAllReceptionist();
    void updateReceptionist(int);
    void deleteReceptionist(int);
};
Receptionist::Receptionist() {
    receptionistID = 0;
}
void Receptionist::receptionWork() {
    patient.patientMenu();
}
void Receptionist::setReceptionistId(int id) {
    receptionistID = id;
};
void Receptionist::setReceptionist() {
    helo:
    setStaff();


    try {
        cout << "\nEnter Receptionist ID";
        cin >> receptionistID;
        if (!receptionistID > 0) {
            if (receptionistID <= 0)
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
}
void Receptionist::showReceptionist() {
    cout << "\nReceptionist Id : " << receptionistID;
    showStaff();

}
int Receptionist::returnRecId() {
    return receptionistID;
};
void Receptionist::ReceptionistMenu() {
    char choice;

    do
    {
        int id;
        cout << "\n1. ENTER RECEPTIONIST DATA";
        cout << "\n2. SEARCH RECEPTIONIST DATA ";
        cout << "\n3. SHOW ALL RECEPTIONIST DATA ";
        cout << "\n4. UPDATE RECEPTIONIST DATA";
        cout << "\n5. DELETE RECEPTIONIST DATA";
        cout << "\n6. ONE STEP BACK ";
        cout << "\n SELECT OPTION (1-5) ";
        cin >> choice;

        switch (choice)
        {
        case '1': writeReceptionist();
            break;
        case '2':cout << "ENTER RECEPTIONIST ID THAT YOU SEARCH :";
            cin >> id;
            searchReceptionistId(id);
            break;

        case '3':showAllReceptionist();
            break;
        case '4':cout << "ENTER RECEPTIONIST ID THAT YOU UPDATE :";
            cin >> id;
            updateReceptionist(id);
            break;
        case '5':cout << "ENTER RECEPTIONIST ID THAT YOU DELETE :";
            cin >> id;
            deleteReceptionist(id);
            break;

        }
    } while (choice != '6');

};
void Receptionist::writeReceptionist() {
    Receptionist receptionist;
    ofstream out;
    out.open("Receptionist.dat", ios::binary | ios::app);
    receptionist.setReceptionist();

    //CHECK ID ALREADY EXIT OR NOT
    /*
    Receptionist receptionist2;
    next:
    infile("Receptionist.dat",ios::binary|ios::app|ios::in);
    while(infile.read(reinterpret_cast<char*> (&receptionist2),sizeof(Receptionist))){
    if(receptionist.returnRecId()==receptionist2.returnRecId()){
    cout<<"\nID ALREADY EXIT "<<endl;
    cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO NURSE ";
    cin>>id;
    receptionist.setreceptionistId(id);
    goto next;}
    }
    infile.close();
    */
    // check id End

    out.write(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist));
    out.close();
    cout << "**************" << endl;
    cout << "\nRECEPTIONIST DATA IS ENTERED";
    cout << "**************" << endl;

};
void Receptionist::searchReceptionistId(int id) {
    Receptionist receptionist;
    ifstream in;
    in.open("Receptionist.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN";
    }
    bool present = 0;
    while (in.read(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist)))
    {
        if (receptionist.returnRecId() == id)
        {
            receptionist.showReceptionist();
            present = 1;
        }
    }
    in.close();
    if (present == 0)
        cout << "\nRECOUR NOT FOUND";


};
void Receptionist::showAllReceptionist() {
    Receptionist receptionist;
    ifstream in;
    in.open("Receptionist.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN";
    }
    cout << "\nDISPLAY ALL RECORD ";
    while (in.read(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist)))
    {
        receptionist.showReceptionist();
        cout << "\nDISPLAY NEW DATA RECORD ";
    }
    in.close();

};
void Receptionist::updateReceptionist(int id) {
    bool present = 0;
    Receptionist receptionist;
    fstream File;
    File.open("Receptionist.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\nFILE NOT OPEN";
    }
    while (!File.eof() && present == 0)
    {

        File.read(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist));
        if (receptionist.returnRecId() == id)
        {
            receptionist.showReceptionist();
            cout << "\n ENTER NEW DATA " << endl;
            receptionist.setReceptionist();

            //CHECK ID ALREADY EXIT OR NOT
            /*
            Receptionist receptionist2;
            next:
            infile("Receptionist.dat",ios::binary|ios::app|ios::in);
            while(infile.read(reinterpret_cast<char*> (&receptionist2),sizeof(Receptionist))){
            if(receptionist.returnRecId()==receptionist2.returnRecId()){
            cout<<"\nID ALREADY EXIT "<<endl;
            cout<<"\nPLEASE ENTER ANOTHER ID THAT YOU GAVE TO NURSE ";
            cin>>id;
            receptionist.setreceptionistId(id);
            goto next;}
            }
            infile.close();
            */
            // check id End


            int setPosition = sizeof(receptionist);
            File.seekp(-setPosition, ios::cur);
            File.write(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist));
            cout << "\n RECEPTIONIST DATA SAVED ";
            present = 1;
        }
    }
    File.close();
    if (present == 0)
        cout << "\n DATA NOT FOUND";
};
void Receptionist::deleteReceptionist(int id) {
    Receptionist receptionist;
    ifstream in;
    in.open("Receptionist.dat", ios::binary);
    if (!in)
    {
        cout << "\nFILE NOT OPEN ";
    }
    ofstream out;
    out.open("Temp.dat", ios::out);
    in.seekg(0, ios::beg);
    while (in.read(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist)))
    {
        if (receptionist.returnRecId() != id)
        {
            out.write(reinterpret_cast<char*> (&receptionist), sizeof(Receptionist));
        }
    }
    out.close();
    in.close();
    remove("Receptionist.dat");
    rename("Temp.dat", "Receptionist.dat");
    cout << "**************" << endl;
    cout << "RECORD  DELETED..";
    cout << "**************" << endl;
};