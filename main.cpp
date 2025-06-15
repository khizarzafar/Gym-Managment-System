#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

void login()
{
    string pass;
    char ch;
    pass = "";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGYM MANAGEMENT SYSTEM" << endl;
    cout << "\t\t\t\t\t\t\t\t\t------------------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\tLOGIN\n";
    cout << "\t\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\t\tEnter Password: ";
    ch = getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = getch();
    }
    if (pass == "1234")
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t  Access Granted!  ";
        Sleep(1000);
        system("CLS");
    }
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tAccess Aborted" << endl;
        cout << "\t\t\t\t\t\t\t\t\tPlease Try Again" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();
        system("CLS");
        login();
    }
}

class declaration
{
public:
    string id, name, age, address, contact, designation, experience, status;
    float bmi; // for BMI
    declaration() : status("Not Paid"), bmi(0.0) {}
};

class count
{
public:
    int counter;
    count() : counter(0) {}
};

class member : public count, public declaration
{
public:
    declaration m[10];
    int en, memberid, status1, status2, fee, mem_fee;
    string back;

    member() : fee(0), memberid(0), status1(0), status2(0), mem_fee(0) {}

    void get_data()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tHow many members do you want to add: ";
        cin >> en;
        system("cls");
        for (int i = 0; i < en; i++)
        {
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tAlot unique ID to member " << i + 1 << ": ";
            cin.ignore();
            getline(cin, m[memberid].id);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tName                      : ";
            getline(cin, m[memberid].name);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tAge                       : ";
            getline(cin, m[memberid].age);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tAddress                   : ";
            getline(cin, m[memberid].address);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tContact                   : ";
            getline(cin, m[memberid].contact);

            // Save to file with BMI
            ofstream file("memberdata.txt", ios::app);
            if (file.is_open())
            {
                file << m[memberid].id << "|" << m[memberid].name << "|" << m[memberid].age << "|"
                     << m[memberid].contact << "|" << m[memberid].status << "|" << m[memberid].bmi << "\n";
                file.close();
            }
            else
            {
                cout << "\n\t\t\t\t\t\t\t\tError saving member data!\n";
            }

            memberid++;
            counter++;
        back:
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tProceed Forward[Y/N]      : ";
            cin >> back;
            if (back == "Y" || back == "y")
            {
                cout << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tYou filled all Entries of " << i + 1 << "/" << en << " member successfully...";
                getch();
                cout << endl;
            }
            else if (back == "N" || back == "n")
            {
                break;
            }
            else
            {
                cout << "\n\t\t\t\t\t\t\t\tWrong Input";
                goto back;
            }
        }
    }

    void calculate_bmi() // New function for BMI calculation
    {
        system("cls");
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the member's ID to calculate BMI: ";
        cin >> n;
        system("cls");
        if (n == "0" || memberid == 0)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            int i;
            for (i = 0; i < memberid; i++)
            {
                if (n == m[i].id)
                {
                    float weight, height;
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t\t\t\tEnter Weight (kg): ";
                    cin >> weight;
                    cout << "\t\t\t\t\t\t\t\tEnter Height (m): ";
                    cin >> height;
                    if (height <= 0)
                    {
                        cout << "\t\t\t\t\t\t\t\tInvalid height!\n";
                    }
                    else
                    {
                        m[i].bmi = weight / (height * height);
                        // Update file
                        ofstream file("memberdata.txt");
                        if (file.is_open())
                        {
                            for (int j = 0; j < memberid; j++)
                            {
                                file << m[j].id << "|" << m[j].name << "|" << m[j].age << "|"
                                     << m[j].contact << "|" << m[j].status << "|" << m[j].bmi << "\n";
                            }
                            file.close();
                        }
                        else
                        {
                            cout << "\n\t\t\t\t\t\t\t\tError updating member data!\n";
                        }
                        cout << "\t\t\t\t\t\t\t\tBMI Calculated: " << m[i].bmi << endl;
                        cout << "\t\t\t\t\t\t\t\tInterpretation:\n";
                        if (m[i].bmi < 18.5)
                            cout << "\t\t\t\t\t\t\t\tUnderweight\n";
                        else if (m[i].bmi < 25)
                            cout << "\t\t\t\t\t\t\t\tNormal\n";
                        else if (m[i].bmi < 30)
                            cout << "\t\t\t\t\t\t\t\tOverweight\n";
                        else
                            cout << "\t\t\t\t\t\t\t\tObese\n";
                    }
                    break;
                }
            }
            if (i == memberid)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tNo such ID in database\n";
            }
        }
        cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();
    }

    void show_data()
    {
        system("cls");
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the member's ID  to display Record: ";
        cin >> n;
        system("cls");
        if (n == "0")
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            int i;
            for (i = 0; i < memberid; i++)
            {
                status1 = 0;
                if (n == m[i].id)
                {
                    status1 = 1;
                    break;
                }
            }
            if (status1)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMembers's ID                 :" << m[i].id << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMembers's Name               :" << m[i].name << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMember's Age                 :" << m[i].age << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMember's Address             :" << m[i].address << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMembers's Contact            :" << m[i].contact << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMember's BMI                 :" << (m[i].bmi > 0 ? to_string(m[i].bmi) : "Not Calculated") << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            }
            else
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tNo such ID in database" << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            }
        }
        getch();
    }

    void member_data()
    {
        if (memberid == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t\t  Details Of All The Members In The GYM" << endl
                 << endl;
            cout << "\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "AGE" << "\t\t\t" << "Contact" << "\t\t\t" << "BMI";
            cout << endl
                 << endl;
            for (int i = 0; i < memberid; i++)
            {
                cout << "\t\t\t\t\t\t" << m[i].id << "\t\t\t" << m[i].name << "\t\t\t" << m[i].age << "\t\t\t" << m[i].contact
                     << "\t\t\t" << (m[i].bmi > 0 ? to_string(m[i].bmi) : "N/A") << endl
                     << endl;
            }
            cout << "\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\n\t\t\t\t\t\tPress any key to choose another option...";
        }
        getch();
    }

    void total_members()
    {
        system("cls");
        int i = counter;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t-----------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tTotal Members in GYM: " << i << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t-----------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();
    }

    void record_fee()
    {
        system("cls");
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the member's ID  to Record Fee> ";
        cin >> n;
        if (n == "0")
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            int i;
            for (i = 0; i < memberid; i++)
            {
                status2 = 0;
                if (n == m[i].id)
                {
                    status2 = 1;
                    break;
                }
            }
            if (status2)
            {
                fee++;
                mem_fee += 500;
                m[i].status = "Paid";
                // Update file with BMI
                ofstream file("memberdata.txt");
                if (file.is_open())
                {
                    for (int j = 0; j < memberid; j++)
                    {
                        file << m[j].id << "|" << m[j].name << "|" << m[j].age << "|"
                             << m[j].contact << "|" << m[j].status << "|" << m[j].bmi << "\n";
                    }
                    file.close();
                }
                else
                {
                    cout << "\n\t\t\t\t\t\t\t\tError updating member data!\n";
                }
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tFee Paid...";
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo such ID in database " << endl;
                cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
            }
        }
        getch();
    }

    void show_fee()
    {
        if (memberid == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t\tFee Record Of All The Members In The GYM" << endl
                 << endl;
            cout << "\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\tTotal Members: " << counter << endl
                 << endl;
            cout << "\t\t\t\t\t\tMembers that paid fee: " << fee << endl
                 << endl;
            cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "Contact" << "\t\t\t" << "Status";
            cout << endl
                 << endl;
            for (int i = 0; i < memberid; i++)
            {
                cout << "\t\t\t\t\t\t" << m[i].id << "\t\t\t" << m[i].name << "\t\t\t" << m[i].contact << "\t\t" << m[i].status << endl;
            }
            cout << "\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\n\t\t\t\t\t\tPress any key to choose another option...";
        }
        getch();
    }
};

class employe : public count, public declaration
{
public:
    declaration e[10];
    int i, en, pay, employeid, status3, status4, emp_pay_given;
    string back;

    employe() : pay(0), employeid(0), status3(0), status4(0), emp_pay_given(0) {}

    void get_data()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tHow many employes do you want to add: ";
        cin >> en;
        system("cls");
        for (i = 0; i < en; i++)
        {
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tAlot unique ID to employe " << i + 1 << ": ";
            cin.ignore();
            getline(cin, e[employeid].id);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tName                       : ";
            getline(cin, e[employeid].name);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tAge                        : ";
            getline(cin, e[employeid].age);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tDesignation                : ";
            getline(cin, e[employeid].designation);
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tExperience                 : ";
            getline(cin, e[employeid].experience);

            // Save to file
            ofstream file("employeedata.txt", ios::app);
            if (file.is_open())
            {
                file << e[employeid].id << "|" << e[employeid].name << "|" << e[employeid].age << "|"
                     << e[employeid].designation << "|" << e[employeid].experience << "|" << e[employeid].status << "\n";
                file.close();
            }
            else
            {
                cout << "\n\t\t\t\t\t\t\t\tError saving employee data!\n";
            }

            employeid++;
            counter++;
            cout << endl
                 << endl;
        back1:
            cout << "\t\t\t\t\t\t\t\tProceed Forward[Y/N]       : ";
            cin >> back;
            if (back == "Y" || back == "y")
            {
                cout << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tYou filled all Entries of " << i + 1 << "/" << en << " employee successfully...";
                getch();
                cout << endl;
            }
            else if (back == "N" || back == "n")
            {
                break;
            }
            else
            {
                cout << "\n\t\t\t\t\t\t\t\tWrong Input" << endl;
                goto back1;
            }
        }
    }

    void show_data()
    {
        system("cls");
        int i;
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the employe's ID  to display Record: ";
        cin >> n;
        system("cls");
        if (n == "0")
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            for (i = 0; i < employeid; i++)
            {
                status3 = 0;
                if (n == e[i].id)
                {
                    status3 = 1;
                    break;
                }
            }
            if (status3)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t<1> Employe's ID                 :" << e[i].id << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t<2> Employe's Name               :" << e[i].name << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t<3> Employe's Age                :" << e[i].age << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t<4> Employe's Designation        :" << e[i].designation << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t<5> Employe's Experience         :" << e[i].experience << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                     << endl;
                cout << "\n\t\t\t\t\t\t\t\tPress any key to choose another option...";
            }
            else
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tNo such ID in database " << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            }
        }
        getch();
    }

    void employe_data()
    {
        int i;
        if (employeid == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t---------------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t\tDetails Of All The Employes In The GYM" << endl
                 << endl;
            cout << "\t\t\t\t\t\t---------------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "AGE" << "\t\t\t" << "DESIGNATION";
            cout << endl
                 << endl;
            for (i = 0; i < employeid; i++)
            {
                cout << "\t\t\t\t\t\t" << e[i].id << "\t\t\t" << e[i].name << "\t\t\t" << e[i].age << "\t\t\t" << e[i].designation << endl
                     << endl;
            }
            cout << "\t\t\t\t\t\t---------------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\tPress any key to choose another option...";
        }
        getch();
    }

    void total_employes()
    {
        system("cls");
        int i = counter;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t-----------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tTotal Members in GYM: " << i << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t-----------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();
    }

    void record_pay()
    {
        system("cls");
        string n;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter the employe's ID  to Record payment: ";
        cin >> n;
        if (n == "0")
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            int i;
            for (i = 0; i < employeid; i++)
            {
                status4 = 0;
                if (n == e[i].id)
                {
                    status4 = 1;
                    break;
                }
            }
            if (status4)
            {
                pay++;
                emp_pay_given += 500;
                e[i].status = "Paid";
                // Update file
                ofstream file("employeedata.txt");
                if (file.is_open())
                {
                    for (int j = 0; j < employeid; j++)
                    {
                        file << e[j].id << "|" << e[j].name << "|" << e[j].age << "|"
                             << e[j].designation << "|" << e[j].experience << "|" << e[j].status << "\n";
                    }
                    file.close();
                }
                else
                {
                    cout << "\n\t\t\t\t\t\t\t\tError updating employee data!\n";
                }
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPay Given...";
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tNo such ID in database " << endl;
                cout << "\t\t\t\t\t\t\tPress any key to choose another option...";
            }
        }
        getch();
    }

    void show_pay()
    {
        if (employeid == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t\tPay Record Of All The Employes In The GYM" << endl
                 << endl;
            cout << "\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\tTotal Employes: " << counter << endl
                 << endl;
            cout << "\t\t\t\t\t\tEmployes that Received Pay:" << pay << endl
                 << endl;
            cout << "\t\t\t\t\t\tID" << "\t\t\t" << "NAME" << "\t\t\t" << "Designation" << "\t\t\t" << "Status";
            cout << endl
                 << endl;
            for (int i = 0; i < employeid; i++)
            {
                cout << "\t\t\t\t\t\t" << e[i].id << "\t\t\t" << e[i].name << "\t\t\t" << e[i].designation << "\t\t\t" << e[i].status << endl;
            }
            cout << "\t\t\t\t\t\t--------------------------------------------------------------------------------" << endl
                 << endl;
            cout << "\n\t\t\t\t\t\tPress any key to choose another option...";
        }
        getch();
    }
};

class feedback
{
public:
    int luv, sat, nt_sat, poor;
    string input;
    feedback() : luv(0), sat(0), nt_sat(0), poor(0) {}

    void get_feeback()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPlease inform us with your valuable feedback...";
        getch();
    feed:
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t----------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t<1> I loved your management and machinery               " << endl
             << endl;
        cout << "\t\t\t\t\t\t\t<2> I am satisfied with your management and machinery   " << endl
             << endl;
        cout << "\t\t\t\t\t\t\t<3> I am not satified with your management and machinery" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t<4> Your Management and machinery is very poor          " << endl
             << endl;
        cout << "\t\t\t\t\t\t\t<5> Go Back                                   " << endl
             << endl;
        cout << "\t\t\t\t\t\t\t----------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\tEnter your choice:     ";
        cin >> input;
        if (input == "1")
        {
            luv = luv + 1;
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tThanks! We value your feedback...";
            getch();
        }
        else if (input == "2")
        {
            sat = sat + 1;
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tThanks! We value your feedback...";
            getch();
        }
        else if (input == "3")
        {
            nt_sat = nt_sat + 1;
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tThanks! We value your feedback...";
            getch();
        }
        else if (input == "4")
        {
            poor = poor + 1;
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tThanks! We value your feedback...";
            getch();
        }
        else if (input == "5")
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWe value your feedback! Please visit again...";
            getch();
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto feed;
        }
    }

    void show_feedback()
    {
        if (luv == 0 && sat == 0 && nt_sat == 0 && poor == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
            cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
            getch();
        }
        else
        {
            if (luv > sat && luv > nt_sat && luv > poor)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tMaximum people are loving your management and machinery..." << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
            }
            else if (sat > luv && sat && sat > nt_sat && sat)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\tMaximum people are Just satisfied with your management and machinery..." << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
            }
            else if (nt_sat > luv && nt_sat > sat && nt_sat > poor)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\t\tMaximum people are not satisfied with your management and machinery..." << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
            }
            else if (poor > luv && poor > sat && poor > nt_sat)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tYou need to do more, your management and machinery is POOR in quality..." << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tNot\n able to show a defined result! Need more feedback..." << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\t\t-------------------------------------------------------------------------" << endl
                     << endl;
                cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
            }
        }
    }
};

class gym_time
{
private:
    string mon, tue, wed, thurs, satur, sun;
    int chk;

public:
    gym_time() : chk(0) {}

    void get_time()
    {
        chk++;
    monday:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Monday" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Chest Workout \t\t\t<2> Dumble rows" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Abs workout       \t\t\t<4> Glutes/Squarts" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> Weightlose workout\t\t\t<6> Leg workout" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choise:     ";
        cin >> mon;
        if (mon == "1")
        {
            mon = "Chest day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (mon == "2")
        {
            mon = "Dumble rows day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (mon == "3")
        {
            mon = "Abs day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (mon == "4")
        {
            mon = "Glutes day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (mon == "5")
        {
            mon = "Weightlose day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (mon == "6")
        {
            mon = "Leg day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto monday;
        }
    tuesday:
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tFor Tuesday" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Chest Workout     \t<2> Dumble rows" << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Abs Workout       \t<4> Glutes/Squarts" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> Weightlose Workout\t<6> Leg Workout" << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choice:     ";
        cin >> tue;
        if (tue == "1")
        {
            tue = "Chest day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (tue == "2")
        {
            tue = "Dumble rows day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (tue == "3")
        {
            tue = "Abs day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (tue == "4")
        {
            tue = "Glutes day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (tue == "5")
        {
            tue = "Weightlose day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (tue == "6")
        {
            tue = "Leg day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto tuesday;
        }
    wednesday:
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Wednesday" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Chest Workout     \t<2> Dumble rows" << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Abs Workout       \t\t\t<4> Glutes/Squarts" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> Weightlose Workout\t<6> Leg day" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choice:     ";
        cin >> wed;
        if (wed == "1")
        {
            wed = "Chest day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (wed == "2")
        {
            wed = "Dumble rows day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (wed == "3")
        {
            wed = "Abs day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (wed == "4")
        {
            wed = "Glutes day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (wed == "5")
        {
            wed = "Weightlose day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (wed == "6")
        {
            wed = "Leg day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto wednesday;
        }
    thursday:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Thursday" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Chest Workout     \t<2> Dumble rows" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Abs Workout       \t<4> Glutes/Squarts" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> Weightlose Workout\t<6> Leg Workout" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choise:     ";
        cin >> thurs;
        if (thurs == "1")
        {
            thurs = "Chest day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (thurs == "2")
        {
            thurs = "Dumble rows day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (thurs == "3")
        {
            thurs = "Abs day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (thurs == "4")
        {
            thurs = "Glutes day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (thurs == "5")
        {
            thurs = "Weightlose day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (thurs == "6")
        {
            thurs = "Leg day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto thursday;
        }
    saturday:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFriday is Off" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tFor Saturday" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Chest Workout     \t<2> Dumble rows" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Abs Workout       \t<4> Glutes/Squarts" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> Weightlose Workout\t<6> Leg Workout" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choise:     ";
        cin >> satur;
        if (satur == "1")
        {
            satur = "Chest day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (satur == "2")
        {
            satur = "Dumble rows day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (satur == "3")
        {
            satur = "Abs day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (satur == "4")
        {
            satur = "Glutes day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (satur == "5")
        {
            satur = "Weightlose day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (satur == "6")
        {
            satur = "Leg day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto saturday;
        }
    sunday:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tFor Sunday" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Chest Workout     \t<2> Dumble rows" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Abs Workout       \t<4> Glutes/Squarts" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> Weightlose Workout\t<6> Leg Workout" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choise:     ";
        cin >> sun;
        if (sun == "1")
        {
            sun = "Chest day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (sun == "2")
        {
            sun = "Dumble rows day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (sun == "3")
        {
            sun = "Abs day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (sun == "4")
        {
            sun = "Glutes day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (sun == "5")
        {
            sun = "Weightlose day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else if (sun == "6")
        {
            sun = "Leg day";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSaved...";
            Sleep(500);
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto sunday;
        }
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tSchedule has been Resetted...";
        getch();
    }

    void show_time()
    {
        if (chk == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t---------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t\t\tNo record to show" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tGYM Schedule" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tMonday           :" << mon << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tTuesday          :" << tue << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tWednesday        :" << wed << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tThursday         :" << thurs << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tFriday is Off" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tSaturday         :" << satur << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tSunday           :" << sun << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
        }
    }
};

int main()
{
    system("color 74");
    string ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, choise;
    member m1;
    employe e1;
    feedback f1;
    gym_time t1;

    // Load data from files
    {
        ifstream file("memberdata.txt");
        if (file.is_open())
        {
            string line, field;
            while (getline(file, line) && m1.memberid < 10)
            {
                size_t pos = 0, next;
                int field_count = 0;
                while ((next = line.find('|', pos)) != string::npos && field_count < 6)
                {
                    field = line.substr(pos, next - pos);
                    switch (field_count)
                    {
                    case 0:
                        m1.m[m1.memberid].id = field;
                        break;
                    case 1:
                        m1.m[m1.memberid].name = field;
                        break;
                    case 2:
                        m1.m[m1.memberid].age = field;
                        break;
                    case 3:
                        m1.m[m1.memberid].contact = field;
                        break;
                    case 4:
                        m1.m[m1.memberid].status = field;
                        if (field == "Paid")
                        {
                            m1.fee++;
                            m1.mem_fee += 500;
                        }
                        break;
                    case 5:
                        m1.m[m1.memberid].bmi = stof(field);
                        break;
                    }
                    field_count++;
                    pos = next + 1;
                }
                if (field_count >= 4)
                {
                    if (field_count == 4)
                    {
                        m1.m[m1.memberid].status = line.substr(pos);
                        if (m1.m[m1.memberid].status == "Paid")
                        {
                            m1.fee++;
                            m1.mem_fee += 500;
                        }
                    }
                    else
                    {
                        field = line.substr(pos);
                        m1.m[m1.memberid].bmi = field.empty() ? 0.0 : stof(field);
                    }
                    m1.memberid++;
                    m1.counter++;
                }
            }
            file.close();
        }
    }
    {
        ifstream file("employeedata.txt");
        if (file.is_open())
        {
            string line, field;
            while (getline(file, line) && e1.employeid < 10)
            {
                size_t pos = 0, next;
                int field_count = 0;
                while ((next = line.find('|', pos)) != string::npos && field_count < 6)
                {
                    field = line.substr(pos, next - pos);
                    switch (field_count)
                    {
                    case 0:
                        e1.e[e1.employeid].id = field;
                        break;
                    case 1:
                        e1.e[e1.employeid].name = field;
                        break;
                    case 2:
                        e1.e[e1.employeid].age = field;
                        break;
                    case 3:
                        e1.e[e1.employeid].designation = field;
                        break;
                    case 4:
                        e1.e[e1.employeid].experience = field;
                        break;
                    case 5:
                        e1.e[e1.employeid].status = field;
                        if (field == "Paid")
                        {
                            e1.pay++;
                            e1.emp_pay_given += 500;
                        }
                        break;
                    }
                    field_count++;
                    pos = next + 1;
                }
                if (field_count == 5)
                {
                    e1.e[e1.employeid].status = line.substr(pos);
                    if (e1.e[e1.employeid].status == "Paid")
                    {
                        e1.pay++;
                        e1.emp_pay_given += 500;
                    }
                    e1.employeid++;
                    e1.counter++;
                }
            }
            file.close();
        }
    }

    system("cls");
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                        WELCOME TO                                     |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                   GYM MANAGEMENT SYSTEM                               |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    cout << "Press any key to choose another option...";
    getch();
    system("cls");

    login();
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ||||||                                                  | 5% ....";
    Sleep(500);
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading |||||||||||||||||||||||||||||||||                       | 57% ....";
    Sleep(500);
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ||||||||||||||||||||||||||||||||||||||||||||||||        | 91% ....";
    Sleep(500);
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 100% ....";
    Sleep(2000);

mainmenu:
    cout << endl
         << endl;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome to the GYM Management System ***" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t<1> Menu" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t<2> Schedule" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t<3> Help" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t<4> Exit" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\tEnter Your Choice:     ";
    cin >> ch1;
    cout << endl
         << endl
         << endl;

    if (ch1 == "1")
    {
    menu:
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome to the Main Menu ***" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<1> Enter into Member's DataBase" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<2> Enter into Employes's DataBase" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<3> Enter in Monetary Database" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<4> Take Feedback" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<5> View Feedback" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<6> Go Back" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter Your choice:     ";
        cin >> ch2;

        if (ch2 == "1")
        {
        memberdatabase:
            system("cls");
            cout << "\n\n";
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome To Members's DataBase ***" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<1> Add New Member's Information              " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<2> Display Member's Information              " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<3> Detail OF ALL The Members In The GYM      " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<4> Total Number of Members in GYM            " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<5> Calculate BMI                             " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<6> Go Back                                   " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tEnter your choice:     ";
            cin >> ch3;

            if (ch3 == "1")
            {
                system("cls");
                m1.get_data();
                goto memberdatabase;
            }
            else if (ch3 == "2")
            {
                system("cls");
                m1.show_data();
                cout << "\n";
                goto memberdatabase;
            }
            else if (ch3 == "3")
            {
                system("cls");
                m1.member_data();
                goto memberdatabase;
            }
            else if (ch3 == "4")
            {
                m1.total_members();
                goto memberdatabase;
            }
            else if (ch3 == "5")
            {
                system("cls");
                m1.calculate_bmi();
                goto memberdatabase;
            }
            else if (ch3 == "6")
            {
                goto menu;
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
                cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
                goto memberdatabase;
            }
        }
        else if (ch2 == "2")
        {
        employedatabase:
            system("cls");
            cout << "\n\n";
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome To Employe's DataBase ***" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<1> Add New Employe's Information             " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<2> Display Employe's Information             " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<3> Detail OF ALL The Employes In The GYM     " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<4> Total Number of Employes in GYM           " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<5> Go Back                                   " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t----------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tEnter your choice:     ";
            cin >> ch4;

            if (ch4 == "1")
            {
                system("cls");
                e1.get_data();
                goto employedatabase;
            }
            else if (ch4 == "2")
            {
                system("cls");
                e1.show_data();
                cout << "\n";
                goto employedatabase;
            }
            else if (ch4 == "3")
            {
                system("cls");
                e1.employe_data();
                goto employedatabase;
            }
            else if (ch4 == "4")
            {
                e1.total_employes();
                goto employedatabase;
            }
            else if (ch4 == "5")
            {
                goto menu;
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
                cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
                goto employedatabase;
            }
        }
        else if (ch2 == "3")
        {
        get_data:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome To Monetary DataBase ***    " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<1> Record fee(member1 database)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<2> View Recorded Fee(member1 database)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<3> View members details(member1 database)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<4> Record Payment(employe1 database)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<5> View Recorded Payment(employe1 database)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<6> View employes details(employe1 database)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<7> Check and Balance(Over view)" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\t<8> Go back" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t\tEnter your choise:     ";
            cin >> ch5;

            if (ch5 == "1")
            {
                system("cls");
                m1.record_fee();
                goto get_data;
            }
            else if (ch5 == "2")
            {
                system("cls");
                m1.show_fee();
                goto get_data;
            }
            else if (ch5 == "3")
            {
                system("cls");
                m1.member_data();
                goto get_data;
            }
            else if (ch5 == "4")
            {
                system("cls");
                e1.record_pay();
                goto get_data;
            }
            else if (ch5 == "5")
            {
                system("cls");
                e1.show_pay();
                goto get_data;
            }
            else if (ch5 == "6")
            {
                system("cls");
                e1.employe_data();
                goto get_data;
            }
            else if (ch5 == "7")
            {
                if (m1.mem_fee != 0)
                {
                    system("cls");
                    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t---------------------------------------------" << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tTotal Members: " << m1.counter << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tMembers that paid fee: " << m1.fee << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tTotal Fee Received: " << m1.mem_fee << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tTotal Employees: " << e1.counter << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tEmployees that Received Pay: " << e1.pay << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tTotal Payment Given: " << e1.emp_pay_given << endl
                         << endl;
                    int total = m1.mem_fee - e1.emp_pay_given;
                    cout << "\t\t\t\t\t\t\t\tTotal Money Earned: " << total << endl
                         << endl;
                    if (total > 0)
                    {
                        cout << "\t\t\t\t\t\t\t\tWOW!!! You are in Profit!" << endl
                             << endl;
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\t\t\tAlas!!! You are in Loss!" << endl
                             << endl;
                    }
                    cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
                         << endl;
                    cout << "\t\t\t\t\t\t\t\tPress any key to choose another option...";
                    getch();
                }
                else
                {
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tOOPS!!!!" << endl;
                    cout << "\t\t\t\t\t\t\tNote: No Record To Display  Plz Go Back And Enter Some Entries...";
                    getch();
                }
                goto get_data;
            }
            else if (ch5 == "8")
            {
                goto menu;
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
                cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
                getch();
                goto get_data;
            }
        }
        else if (ch2 == "4")
        {
            system("cls");
            f1.get_feeback();
            goto menu;
        }
        else if (ch2 == "5")
        {
            system("cls");
            f1.show_feedback();
            goto menu;
        }
        else if (ch2 == "6")
        {
            goto mainmenu;
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto menu;
        }
    }
    else if (ch1 == "2")
    {
    schedule:
        t1.show_time();
        cout << "\n\n\t\t\t\t\t\t\t\t<1> Reset Schedule" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t<2> Go back" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\t---------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your choise:     ";
        cin >> ch6;
        if (ch6 == "1")
        {
            t1.get_time();
            goto mainmenu;
        }
        else if (ch6 == "2")
        {
            goto mainmenu;
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
            cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
            getch();
            goto schedule;
        }
    }
    else if (ch1 == "3")
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t   \n\n\n----------------------------------------------------------------------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t   IMPORTANT: Before using this software, please make sure to first access the Main Menu." << endl;
        cout << "\t\t\t\t   Begin by entering the details of members. After that, you can proceed to register employees." << endl;
        cout << "\t\t\t\t   This is a data management system that allows you to efficiently record information of members" << endl;
        cout << "\t\t\t\t   and employees. You can also access the financial section to log membership fee payments and" << endl;
        cout << "\t\t\t\t   calculate total received amounts. In addition, the system enables you to maintain employee" << endl;
        cout << "\t\t\t\t   salary records—showing who has been paid and who is pending." << endl;
        cout << "\t\t\t\t   At the end, the system provides a summary showing total income received and total expenses paid," << endl;
        cout << "\t\t\t\t   and displays whether you are in profit or loss." << endl
             << endl;
        cout << "\t\t\t\t   ----------------------------------------------------------------------------------------------------------" << endl
             << endl;
        cout << "\t\t\t\t   Press any key to return to the main menu...";
        getch();
        goto mainmenu;
    }

    else if (ch1 == "4")
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                THANK YOU FOR USING                                    |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                               GYM MANAGEMENT SYSTEM                                   |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                               |@@\n";
        cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
        cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    }

    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
        // cout << endl;
        cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option...";
        getch();
        goto mainmenu;
    }
    return 0;
}
