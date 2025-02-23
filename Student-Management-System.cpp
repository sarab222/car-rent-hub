#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cctype>    
using namespace std;

class Student
{
public:
    string id; 
    string name;
    float gpa;
    Student *next;

    Student(string id, string name, float gpa)
    {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->next = NULL;
    }
};

class StudentManagementSystem
{
private:
    Student *head;

public:
    StudentManagementSystem() { head = NULL; }

    
    void addStudent(string id, string name, float gpa)
    {
        Student *newStudent = new Student(id, name, gpa);
        if (head == NULL)
        {
            head = newStudent;
        }
        else
        {
            Student *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student added successfully!" << endl;
        saveStudents();
    }

    
    void deleteStudent(string id)
    {
        if (head == NULL)
        {
            cout << "No students to delete!" << endl;
            return;
        }
        if (head->id == id)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully!" << endl;
            saveStudents();
            return;
        }
        Student *current = head;
        Student *previous = NULL;
        while (current != NULL && current->id != id)
        {
            previous = current;
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Student with ID " << id << " not found!" << endl;
            return;
        }
        previous->next = current->next;
        delete current;
        cout << "Student deleted successfully!" << endl;
        saveStudents();
    }

    
    void searchStudent(string id)
    {
        Student *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "Student found!" << endl;
                cout << "ID: " << temp->id << ", Name: " << temp->name
                     << ", GPA: " << temp->gpa << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }

    
    void updateStudent(string id)
    {
        Student *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "Student found! Enter new details:" << endl;
                string newName;
                float newGPA;

                do
                {
                    cout << "Enter new name (letters and spaces only): ";
                    cin.ignore();
                    getline(cin, newName);
                } while (!isValidName(newName));

                do
                {
                    cout << "Enter new GPA (0.0 - 4.0): ";
                    cin >> newGPA;
                } while (!isValidGPA(newGPA));

                temp->name = newName;
                temp->gpa = newGPA;
                cout << "Student details updated successfully!" << endl;
                saveStudents();
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }

     void sortStudents()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "No need to sort" << endl;
            return;
        }

        bool swapped;
        Student *current;
        Student *lastSorted = NULL;

        do
        {
            swapped = false;
            current = head;

            while (current->next != lastSorted)
            {
                if (current->id > current->next->id)
                {
                    string tempID = current->id;
                    string tempName = current->name;
                    float tempGPA = current->gpa;

                    current->id = current->next->id;
                    current->name = current->next->name;
                    current->gpa = current->next->gpa;

                    current->next->id = tempID;
                    current->next->name = tempName;
                    current->next->gpa = tempGPA;

                    swapped = true;
                }
				 current = current->next;
            }
            lastSorted = current;
        } while (swapped);

        cout << "Students sorted successfully by ID!" << endl;
    }


    void countStudents()
    {
        int count = 0;
        Student *temp = head;
        while (temp != NULL)
        {
            ++count;
            temp = temp->next;
        }
        cout << "Total number of students: " << count << endl;
    }

    
    void displayStudents()
    {
        if (head == NULL)
        {
            cout << "No students to display!" << endl;
            return;
        }
        cout << "ID\t\tName\t\t\tGPA" << endl;
        cout << "----------------------------------------------------" << endl;
        Student *temp = head;
        while (temp != NULL)
        {
            cout << temp->id << "\t\t" << temp->name << "\t\t" << temp->gpa << endl;
            temp = temp->next;
        }
    }
	

    
    void saveStudents()
    {
        ofstream file("students.txt");
        if (!file)
        {
            cout << "Error opening file for saving!" << endl;
            return;
        }
        Student *temp = head;
        while (temp != NULL)
        {
            file << temp->id << " " << temp->name << " " << temp->gpa << endl;
            temp = temp->next;
        }
        file.close();
        cout << "Student list saved successfully!" << endl;
    }

    
    void loadStudents()
    {
        ifstream file("students.txt");
        if (!file)
        {
            cout << "No saved student data found." << endl;
            return;
        }
        string id, name;
        float gpa;
        while (file >> id)
        {
            file.ignore();
            getline(file, name, ' ');
            file >> gpa;
            addStudent(id, name, gpa);
        }
        file.close();
    }

    
    bool isValidName(string name)
    {
        for (char c : name)
        {
            if (!isalpha(c) && c != ' ')
                return false;
        }
        return true;
    }

    bool isValidID(string id)
{
    
    if (id.length() != 12)
        return false;

    
    for (int i = 0; i < 8; i++)
    {
        if (!isdigit(id[i]))
            return false;
    }

    
    if (id[8] != '-')
        return false;


    for (int i = 9; i < 12; i++)
    {
        if (!isdigit(id[i]))
            return false;
    }

    return true;
}

    
    bool isValidGPA(float gpa)
    {
        return gpa >= 0.0 && gpa <= 4.0;
    }


    bool isUniqueID(string id)
    {
        Student *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
                return false;
            temp = temp->next;
        }
        return true;
    }
};

int main()
{
    StudentManagementSystem sms;
    sms.loadStudents();
    int choice;
    char op;
    do
    {
		 cout << "-----------------------------------------------------------------" << endl;
        cout << "*" << endl;
        cout << "|               Welcome to Student Management System             |" << endl;
        cout << "*" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << endl << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "*" << endl;
        cout << "|                         Main Menu                             |" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "*" << endl;
        cout << endl << endl;
        cout << "                         Select an option         " << endl;
        // cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Students" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Update Student Details" << endl;
        cout << "6. Count Total Students" << endl;
        cout << "7. Sort Students by ID" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string id, name;
            float gpa;

            do
            {
                cout << "Enter student ID (NNNNNNNN-NNN): ";
                cin >> id;

                if (!sms.isValidID(id))
                {
                    cout << "Error: Invalid ID! Please enter a valid ID.(e.g, 23014119-153) " << endl;
                }
                else if (!sms.isUniqueID(id))
                {
                    cout << "Error: ID already exists. Please enter a unique ID!" << endl;
                }

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (!sms.isValidID(id) || !sms.isUniqueID(id));

            do
            {
                cout << "Enter student name (letters and spaces only): ";
                cin.ignore();
                getline(cin, name);
                if (!sms.isValidName(name))
                {
                    cout << "Error: Name can only contain alphabetic characters and spaces!" << endl;
                }
            } while (!sms.isValidName(name));

            do
            {
                cout << "Enter GPA (0.0 - 4.0): ";
                cin >> gpa;
                if (!sms.isValidGPA(gpa))
                {
                    cout << "Error: GPA must be between 0.0 and 4.0!" << endl;
                }

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (!sms.isValidGPA(gpa));

            sms.addStudent(id, name, gpa);
            break;
        }
        case 2:
        {
            string id;
            cout << "Enter student ID to delete: ";
            cin >> id;

            if (!sms.isValidID(id))
            {
                cout << "Error: Invalid student ID!" << endl;
                break;
            }

            sms.deleteStudent(id);
            break;
        }
        case 3:
            sms.displayStudents();
            break;
        case 4:
        {
            string id;
            cout << "Enter student ID to search: ";
            cin >> id;

            if (!sms.isValidID(id))
            {
                cout << "Error: Invalid student ID!" << endl;
                break;
            }

            sms.searchStudent(id);
            break;
        }
        case 5:
        {
            string id;
            cout << "Enter student ID to update: ";
            cin >> id;

            if (!sms.isValidID(id))
            {
                cout << "Error: Invalid student ID!" << endl;
                break;
            }

            sms.updateStudent(id);
            break;
        }
        case 6:
            sms.countStudents();
            break;
        case 7:
            sms.sortStudents();
            break;
        case 8:
            cout << "Exiting the system." << endl;
            exit(0);
        default:
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        }
        cout << "\n\n";
        cout << "\t\tDo You Want to Continue or Exit [Yes/No]? ";
        cin >> op;
    } while (op == 'y' || op == 'Y');

    return 0;
}