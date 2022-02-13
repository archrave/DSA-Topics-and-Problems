#include <iostream>
using namespace std;
class Student
{
public:
    int rollNo;
    int age;
    static int totalStudents; //cannot initialize in this line unless it is also marked as const
};
int Student ::totalStudents = 30;

int main()
{
    Student s1, s2;
    s1.age = 2;
    s1.rollNo = 10;
    s2.age = 5;
    s2.rollNo = 20;
    cout << "s1.age: " << s1.age << endl;
    cout << "s1.rollNo: " << s1.rollNo << endl
         << endl;
    cout << "s2.age: " << s2.age << endl;
    cout << "s1.rollNo: " << s2.rollNo << endl;
    cout << "\nTotalStudents = " << Student::totalStudents;
    s1.totalStudents = 22; // This is logically an incorrect statement but our compiler is allowing it.
    cout << "\nTotalStudents = " << Student::totalStudents;
}