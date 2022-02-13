#include<iostream>
#include<math.h>
using namespace std;

void checkingIntRange()
{   
    int a=2,b;
    b = (int)pow(a,4);
    cout<<"\n\nb = "<<b<<endl;
    b = (int)pow(a,31);
    // The output below shows "-2147483648" without subtracting b by 1. This proves that 2^31 - 1 (inclusive) is the highest range for a 32 bit int
    cout<<"\n\nb = "<<b-1<<endl;
}


 long int checkReverse(int num)
{
    long int rem, revNum=0;
    while(num!=0)
    {
        rem = num % 10;
        revNum = revNum*10 + rem;
        num = num/10;
    }
    return revNum;
}

int main()
{
    long int a = 1234567892, b = -562;
    cout<<checkReverse(a)<<endl;
    cout<<checkReverse(b)<<endl;
    return 0;
}