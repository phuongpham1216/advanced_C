#include <iostream>
#include <string>

using namespace std;

class Person
{
    protected:
        string Name;
        int Age;
        string Home_Address;

    public:
        virtual string test()
            {
                return "Hello person";
            }
        void displayInfo()
            {
                cout << test() << endl;
            }
};

class Student : public Person
{
    private:
        string School_Name;
        double GPA;
        int StudentID;

    public:
        string test()
            {
                return "Hello student";
            }
};

int main()
{
    Person person1;
    person1.displayInfo();

    cout << "------------------------------" << endl;

    Student student1;
    student1.displayInfo();

    return 0;
}