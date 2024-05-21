#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    unsigned int age;
    unsigned int id;
public:
    Person()
    {
        static unsigned int ID = 202401;
        id = ID;
        ID++;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }
};

int main(int argc, char const *argv[])
{
    Person p1;
    Person p2;
    Person p3;

    p1.setName("Phuong");
    cout << "name: " << p1.getName() << endl;

    cout << "ID: " << p1.getId() << endl;
    cout << "ID: " << p2.getId() << endl;
    cout << "ID: " << p3.getId() << endl;
    return 0;
}
