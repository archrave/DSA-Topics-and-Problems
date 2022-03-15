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

// Find the number of ways we can reach n from 0, using 1,2 or 3 steps at a time aka staircase problem.

void staircase(int n, int &cnt)
{
    if (n == 0)
    {
        cnt++;
        return;
    }
    for (int j = 1; j <= 3 && n >= j; j++)
    {
        staircase(n - j, cnt);
    }
}

int staircase2(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (n < 0)
        return 0;
    if (n == 2)
        return 2;
    return staircase2(n - 1) + staircase2(n - 2) + staircase2(n - 3);
}

int towersOfHanoi(int n)
{
    if (n == 1)
        return 1;
    return 2 * towersOfHanoi(n - 1) + 1;
}

int main()
{
    // char s[40] = "ABC";
    // printPermutations(s);
    int n = 5, count = 0;
    // staircase(n, count);
    // cout << count << endl;
    // cout << staircase2(n);
    cout << towersOfHanoi(4);
    return 0;
}
