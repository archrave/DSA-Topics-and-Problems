#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findStr(int n)
    {
        if (n == 1)
            return "0";
        // string smallAns = findStr(s,n-1).append("1");
        // return smallAns.append(smallAns, reverse(s));
        string s = findStr(n - 1);
        return s + "1" + reverse(s);
    }

    string reverse(string s)
    {

        int i = 0, j = s.length() - 1;
        for (i = 0; i < s.length() / 2; i++)
        {
            if (s[i] == s[j - i])
            {
                invert(s[j], s[j - i]);
            }
        }
        if (s.length() % 2 == 1)
            s[i] = (s[i] == '0') ? '1' : '0';
        return s;
    }

    void invert(char &a, char &b)
    {
        a = (a == '0') ? '1' : '0';
        b = (b == '0') ? '1' : '0';
    }

    char findKthBit(int n, int k)
    {
        string s = "";
        s = findStr(n);
        return s[k - 1];
    }
};
int main()
{
    Solution s;
    cout << s.findStr(1) << endl;
    cout << s.findStr(2) << endl;
    cout << s.findStr(3) << endl;
    cout << s.findStr(4) << endl;
    // cout << s.findKthBit(4, 11);
    return 0;
}