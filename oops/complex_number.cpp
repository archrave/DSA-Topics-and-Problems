#include <iostream>
using namespace std;
class ComplexNumber
{
    int real;
    int imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void print()
    {
        if (imaginary > 0)
        {
            cout << real << " + " << imaginary << "i" << endl;
        }
        else
        {
            cout << real << " - " << abs(imaginary) << "i" << endl;
        }
    }
    void add(ComplexNumber const &c)
    {
        real += c.real;
        imaginary += c.imaginary;
    }
    void multiply(ComplexNumber const &c)
    {
        int a = real * c.real - imaginary * c.imaginary;
        int b = real * c.imaginary + imaginary * c.real;
        real = a;
        imaginary = b;
    }
};
int main()
{
    ComplexNumber c1(1, 3);
    ComplexNumber c2(7, 2);
    ComplexNumber c1Copy = c1;
    cout << "C1: ";
    c1.print();
    cout << endl;
    cout << "C2: ";
    c2.print();
    cout << endl;
    c1.add(c2);
    cout << "C1 + C2 : ";
    c1.print();
    cout << endl;
    c1Copy.multiply(c2);
    cout << "C1 * C2 : ";
    c1Copy.print();
    cout << endl;

    return 0;
}