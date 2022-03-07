#include <bits/stdc++.h>
using namespace std;

// Print and reversePrint

void reversePrint(char a[])
{
    if (a[0] == '\0')
        return;
    reversePrint(a + 1);
    cout << a[0];
}

void print(char a[])
{
    if (a[0] == '\0')
        return;
    cout << a[0];
    print(a + 1);
}

// Length of character array

int lengthCharArray(char c[])
{
    if (c[0] == '\0')
        return 0;
    return 1 + lengthCharArray(c + 1);
}

// Replace all instances of a character in a character array

void replaceWith(char str[], char a, char b)
{
    if (str[0] == '\0')
        return;
    if (str[0] == a)
        str[0] = b;
    replaceWith(str + 1, a, b);
}

// Remove all the charaters:

void remove(char str[], char ch)
{
    if (str[0] == '\0')
        return;
    if (str[0] == ch)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }
        remove(str, ch);
    }
    else
        remove(str + 1, ch);
}

// Remove consecutive duplicates in strings like aabbbcc => abc

void removeConsecutiveDuplicates(char str[])
{
    if (str[0] == '\0')
        return;
    if (str[0] != str[1])
        removeConsecutiveDuplicates(str + 1);
    else
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = str[i + 1];
        }
        removeConsecutiveDuplicates(str);
    }
}

// Print all subsequences of a string i.e, all possible combinations

void printSubsequences(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }
    printSubsequences(str.substr(1), output);
    printSubsequences(str.substr(1), output + str[0]);
}

// Convert string like "1234" to integer 1234

int convert(string str)
{
    if (str.length() == 0)
        return 0;
    int multiplier = ((int)str[0] - 48) * pow(10, str.length() - 1);
    return multiplier + convert(str.substr(1));
}

// Print all permutations of string

void printPermutations(char str[], int i = 0) // Taking default argument
{
    if (str[i] == '\0')
    {
        cout << str << endl;
        return;
    }
    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        printPermutations(str, i + 1);
        swap(str[i], str[j]);
    }
}

int main()
{
    char s[40] = "ABC";
    printPermutations(s);
    // string number = "9043";
    // cout << convert(number) + 1;
    return 0;
}
