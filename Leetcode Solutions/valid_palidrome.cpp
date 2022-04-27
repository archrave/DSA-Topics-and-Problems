#include <iostream>
using namespace std;

bool isNumberorLetter(char c)
{
    return (tolower(c) >= 97 && tolower(c) <= 122) || (c >= 48 && c <= 57);
}

bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        char x = tolower(s[i]), y = tolower(s[j]);
        if (isNumberorLetter(x) && isNumberorLetter(y))
        {
            if (x != y)
            {
                cout << endl
                     << x << " " << y << endl;
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            if (!isNumberorLetter(x))
                i++;
            if (!isNumberorLetter(y))
                j--;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    // cout << tolower('8');
    s = "race a car";
    s = "0P";
    cout << isPalindrome(s);
    return 0;
}