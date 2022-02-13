#include <iostream>
#include "student.cpp"
using namespace std;
int main()
{
    int a = 19;
    char b[20] = "Rude boy";
    Student student2;
    student2.setData(a, b, 100);
    cout << "S1: " << endl;
    student2.printData();
    cout << endl;
    Student student3(student2);
    cout << "S3: " << endl;
    student3.printData();

    return 0;
}