#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
        simplify();
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

    void add(Fraction const &f)
    {
        int lcm = this->denominator * f.denominator;
        int x = this->numerator * f.denominator + this->denominator * f.numerator;
        this->numerator = x;
        this->denominator = lcm;
        simplify();
    }
    Fraction operator+(Fraction const &f)
    {
        int lcm = this->denominator * f.denominator;
        int x = this->numerator * f.denominator + this->denominator * f.numerator;
        Fraction fnew(x, lcm);
        fnew.simplify();
        return fnew;
    }
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();
        // Fraction fnew(numerator, denominator);
        // fnew.simplify();
        return *this;
    }

    // Post increament operator:
    Fraction operator++(int)
    {
        Fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    void simplify()
    {
        int maxHcf = min(numerator, denominator);
        for (int i = maxHcf; i > 0; i--)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator = numerator / i;
                denominator = denominator / i;
                return;
            }
        }
    }
};

int main()
{
    Fraction f1(1, 4);
    Fraction f2(3, 2);
    Fraction f3(1, 1);

    f1.print();
    // f2.print();
    // f3 = f1 + f2;
    // f3.print();
    f2 = f1++;
    // f3 = ++(++f1);
    // f3.print();
    f1.print();
    f2.print();
    return 0;
}
