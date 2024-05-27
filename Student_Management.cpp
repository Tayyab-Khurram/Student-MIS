#include <iostream>
#include <string.h>
using namespace std;

int Q, total = 0;

class Student
{
private:
    string name;
    int roll_no;
    string department;
    int phone;

public:
    void add_record()
    {
        if (total < Q)
        {
            cout << "\nEnter the name of the Student: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the Roll Number of "<<name<<" :";
            cin >> roll_no;
            cout << "What is the department of "<<name<<" :";
            cin >> department;
            cout << "Enter the Phone Number of "<<name<<" :";
            cin >> phone;

            total++;
            cout << "\t\nStudent added successfully!\n" << endl;
        }
        else
            cout << "Cannot add more students, limit reached." << endl;
    }

    void display_record(Student bacha[])
    {
        if (total == 0)
        {
            cout << "\n\tBanday ka puttar bun jaa!\n\tPehlay data tou enter kar day\n" << endl;
            exit(0);
        }

        int user;
        cout << "\n1- Display all data" << endl;
        cout << "2- Display specific data" << endl;
        cout << "\nEnter your choice : ";
        cin >> user;

        if (user == 1)
        {
            int passwd;
            int tries = 0;

            while (tries != 3)
            {
                cout << "Enter the password for the system : ";
                cin >> passwd;

                if (passwd == 786)
                {
                    for (int i = 0; i < total; i++)
                    {
                        cout << "\nName: " << bacha[i].name << endl;
                        cout << "Roll Number: " << bacha[i].roll_no << endl;
                        cout << "Department: " << bacha[i].department << endl;
                        cout << "Phone Number: " << bacha[i].phone << endl << endl;
                    }
                }
                else
                {
                    tries++;
                    cout << "\n\tWrong Password, Please enter again!\n" << endl;
                    continue;
                }
            }
        }

        else if (user == 2)
        {
            int num;
            cout << "Enter the Roll Number of the Student to display record: ";
            cin >> num;

            for (int i = 0; i < total; i++)
            {
                if (num == bacha[i].roll_no)
                {
                    cout << "\n\nName: " << bacha[i].name << endl;
                    cout << "Roll Number: " << bacha[i].roll_no << endl;
                    cout << "Department: " << bacha[i].department << endl;
                    cout << "Phone Number: " << bacha[i].phone << endl;
                }
                else
                {
                    cout << "\n\nRoll Number not found!" << endl;
                }
            }
        }
    }

    void update_record(Student bacha[])
    {
        if (total == 0)
        {
            cout << "\n\tBanday ka puttar bun jaa!\n\tPehlay data tou enter kar day\n" << endl;
            exit(0);
        }

        int gum;
        cout << "\nEnter the Roll Number of the Student to update record: ";
        cin >> gum;

        for (int i = 0; i < total; i++) // loop is always used for searching
        {
            if (gum == bacha[i].roll_no)
            {
                cout << "\nPrevious Data" << endl;

                cout << "\nName: " << bacha[i].name << endl;
                cout << "Roll Number: " << bacha[i].roll_no << endl;
                cout << "Department: " << bacha[i].department << endl;
                cout << "Phone Number: " << bacha[i].phone << endl << endl;

                cout << "Enter the name of the Student: ";
                cin.ignore();
                getline(cin, bacha[i].name);
                cout << "Enter the Roll Number of the Student: ";
                cin >> bacha[i].roll_no;
                cout << "What is the department of the Student: ";
                cin >> bacha[i].department;
                cout << "Enter the Phone Number of the Student: ";
                cin >> bacha[i].phone;

                cout << "\t\nRecord Updated successfully!\n" << endl;
            }
            else
            {
                cout << "\n\nRoll Number not found!" << endl;
            }
        }
    }

    void delete_record(Student bacha[])
    {
        if (total == 0)
        {
            cout << "\n\tBanday ka puttar bun jaa!\n\tPehlay data tou enter kar day\n" << endl;
            exit(0);
        }

        int user;
        cout << "\n1- Delete all data" << endl;
        cout << "2- Delete specific data" << endl;
        cout << "\nEnter your choice : ";
        cin >> user;

        if (user == 1)
        {
            int passwd;
            int tries = 0;

            while (tries != 3)
            {
                cout << "Enter the password for the system : ";
                cin >> passwd;

                if (passwd == 786)
                {
                    total = 0;
                    cout <<"\nAll the record has been deleted!\n"<<endl;
                    break;
                }
                else
                {
                    tries++;
                    cout << "\n\tWrong Password, Please enter again!\n" << endl;
                    continue;
                }
            }
        }

        else if (user == 2)
        {
            int del;
            cout << "Enter the Roll Number of the Student to Delete record: ";
            cin >> del;

            for (int i = 0; i < total; i++)
            {
                if (del == bacha[i].roll_no)
                {
                    bacha[i].roll_no = bacha[i + 1].roll_no;
                    bacha[i].name = bacha[i + 1].name;
                    bacha[i].department = bacha[i + 1].department;
                    bacha[i].phone = bacha[i + 1].phone;
                    cout << "\n\tStudent Deleted successfully!\n" << endl;
                }
                else
                {
                    cout << "\n\nRoll Number not found!" << endl;
                }
            }
        }
    }
    
    void count_records()
    {
        cout <<"\nTotal number of "<<total<<" students have been inserted\n"<<endl;
    }
};

int main()
{
    cout << "\t\t\t\t\t*** STUDENT MANAGEMENT SYSTEM ***\n\n";
    cout << "\nHow many Students do you want to enter : " << endl;
    cin >> Q;
    Student bacha[Q];

    int choice;
    while (1)
    {
        cout << "\t\t\t\t\t*** STUDENT MANAGEMENT SYSTEM ***\n\n";
        cout << "1- Add Record" << endl;
        cout << "2- Display Record" << endl;
        cout << "3- Update Record" << endl;
        cout << "4- Delete Record" << endl;
        cout << "5- Count Records" << endl;
        cout << "6- Exit\n" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bacha[total].add_record();
            break;
        case 2:
            bacha[total].display_record(bacha);
            break;
        case 3:
            bacha[total].update_record(bacha);
            break;
        case 4:
            bacha[total].delete_record(bacha);
            break;
        case 5:
            bacha[total].count_records();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Please enter the correct option!" << endl;
            continue;
        }
    }
    return 0;
}