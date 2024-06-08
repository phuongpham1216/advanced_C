#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        string Name;
        double GPA;
        int StudentID;
    public:
        Student(string name);
        ~Student();
        string getName();
        void setGPA(double gpa);
        double getGPA();
        int getID();
};

Student::Student(string name)
{
    Name = name;
    static int id = 1000;
    StudentID = id;
    ++id;
}

Student::~Student()
{
    cout << "Test Destructor" << StudentID << endl;
}

void Student::setGPA(double gpa)
{
    GPA = gpa;
}

double Student::getGPA()
{
    return GPA;
}

string Student::getName()
{
    return Name;
}

int Student::getID()
{
    return StudentID;
}

int main()
{
    Student student1("Trung");
    Student student2("Hue");
    Student student3("Phong");

    cout << "ID: " << student1.getID() << endl;
    cout << "Name: " << student1.getName() << endl;

    cout << "ID: " << student2.getID() << endl;
    cout << "Name: " << student2.getName() << endl;

    cout << "ID: " << student3.getID() << endl;
    cout << "Name: " << student3.getName() << endl;
    return 0;
}
