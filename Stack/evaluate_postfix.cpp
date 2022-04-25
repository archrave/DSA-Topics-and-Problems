#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Postfix Notation is also called 'Reverse Polish Notation'!

int evaluatePostfix(vector<string> tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i][0] >= 48 && tokens[i][0] <= 57 || (tokens[i][0] == '-' && tokens[i].length() > 1))
        {
            st.push((int)stoi(tokens[i]));
        }
        else
        {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            if (tokens[i][0] == '+')
                st.push(x + y);
            else if (tokens[i][0] == '-')
                st.push(x - y);
            else if (tokens[i][0] == '*')
                st.push(x * y);
            else if (tokens[i][0] == '/')
                st.push(x / y);
        }
    }
    return st.top();
}

int main()
{
    vector<string> v1 = {"4", "13", "5", "/", "+"};
    vector<string> v2 = {"2", "1", "+", "3", "*"};
    vector<string> v3 = {"2"};
    cout << evaluatePostfix(v1) << endl;
    cout << evaluatePostfix(v2) << endl;
    cout << evaluatePostfix(v3) << endl;
    return 0;
}