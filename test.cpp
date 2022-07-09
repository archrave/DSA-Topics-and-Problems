#include <iostream>
#include <vector>
using namespace std;

int main()
{
    float f = 0.2;
    if (f == 0.2)
        printf("it's geek time");
    else if (f < 0.2)
        printf("it's party time");
    else
        printf("it's movie time");

    cout << f;
    return 0;
}