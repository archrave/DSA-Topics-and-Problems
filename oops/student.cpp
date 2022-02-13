#include <iostream>
#include <string.h>
using namespace std;
class Student
{
    int age;
    int *p;
    char name[40];

public:
    Student()
    {
        p = new int;
    }
    // Student(Student &ob)
    // {
    //     age = ob.age;
    //     strcpy(name, ob.name);
    //     p = new int;
    //     *p = *(ob.p);
    // }
    void setData(int age, char *name, int value)
    {
        this->age = age;
        strcpy(this->name, name);
        (*p) = value;
    }
    void printData()
    {
        cout << "Age : " << age << endl;
        cout << "Name : " << name << endl;
        cout << "*p: " << *p << endl
             << endl;
        cout << "Age adress : " << &age << ", Name adress : " << &name << ", Pointer p = " << p << endl;
    }
};