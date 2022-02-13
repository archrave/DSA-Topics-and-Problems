#include <iostream>
#include <math.h>
using namespace std;
class Triangle
{
    double a;
    double b;
    double c;

public:
    Triangle(double a1, double b1, double c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
    double perimeter()
    {
        return a + b + c;
    }
    double area()
    {
        double s = perimeter() / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }
};

int main()
{
    Triangle triangle = Triangle(3.0, 4.0, 5.0);
    cout << "Perimeter : " << triangle.perimeter() << endl;
    cout << "Area : " << triangle.area();
}