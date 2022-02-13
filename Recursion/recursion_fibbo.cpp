#include<iostream>
using namespace std;
int fibbonacci(int n)
{
    if( n == 1 || n == 0)
    {
        // cout<<0;
        return 0;
    }
    else if( n == 2 )
    {
        // cout<<n-1;
        return fibbonacci(n - 1) + 1;
    }
    else
    {
        return (fibbonacci(n-1) + fibbonacci(n-2));
    }
}
int main()
{
    int n;
    cout<<"Enter a number till which the fibbonacci sequence is to be printed: ";
    cin>>n;
    for(int i = 1; i <= n; i++)
        cout<<fibbonacci(i)<<" ";
    return 0;
}